#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class TestVideo
{
public:
    TestVideo() = default;

    TestVideo(const std::string &baseDir)
    {
        loadFromDisk(baseDir);
    }

    void loadFromDisk(const std::string &baseDir)
    {
        std::vector<std::string> framePaths, bboxPaths;

        // Отримати шляхи до кадрів та JSON-файлів
        cv::glob(baseDir + "/frames/frame_*.jpg", framePaths, false);
        cv::glob(baseDir + "/bboxes/frame_*.json", bboxPaths, false);

        // Перевірка кількості файлів
        if (framePaths.size() != bboxPaths.size())
        {
            throw std::runtime_error("Кількість кадрів та анотацій не співпадає");
        }

        // Сортування за номером кадру
        auto extractNumber = [](const std::string &path)
        {
            size_t start = path.find_last_of("_") + 1;
            size_t end = path.find_last_of(".");
            return std::stoi(path.substr(start, end - start));
        };

        std::sort(framePaths.begin(), framePaths.end(),
                  [&](const auto &a, const auto &b)
                  { return extractNumber(a) < extractNumber(b); });
        std::sort(bboxPaths.begin(), bboxPaths.end(),
                  [&](const auto &a, const auto &b)
                  { return extractNumber(a) < extractNumber(b); });

        // Завантаження даних
        for (size_t i = 0; i < framePaths.size(); ++i)
        {
            // Завантажити кадр
            cv::Mat frame = cv::imread(framePaths[i]);
            if (frame.empty())
            {
                throw std::runtime_error("Не вдалося завантажити кадр: " + framePaths[i]);
            }
            frames.push_back(frame);

            // Обробити JSON
            std::ifstream file(bboxPaths[i]);
            if (!file.is_open())
            {
                throw std::runtime_error("Не вдалося відкрити JSON: " + bboxPaths[i]);
            }

            json data = json::parse(file);
            const auto &coords = data[0]["annotations"][0]["coordinates"];

            // Отримати координати bbox
            int x = static_cast<int>(std::round(coords["x"].get<double>()));
            int y = static_cast<int>(std::round(coords["y"].get<double>()));
            int width = static_cast<int>(std::round(coords["width"].get<double>()));
            int height = static_cast<int>(std::round(coords["height"].get<double>()));

            x -= width / 2;
            y -= height / 2;

            bboxes.emplace_back(x, y, width, height);
        }
    }

    void reset()
    {
        currentIndex = 0;
    }

    bool nextFrame(cv::Mat &frame, cv::Rect &bbox)
    {
        if (currentIndex >= frames.size())
        {
            return false;
        }

        frame = frames[currentIndex];
        bbox = bboxes[currentIndex];

        currentIndex++;

        return true;
    }

private:
    std::vector<cv::Mat> frames;
    std::vector<cv::Rect> bboxes;

    unsigned int currentIndex = 0;
};