#pragma once

#include <random>

#include "GeneratorParams.hpp"

class RandomParams : public GeneratorParams
{
protected:
    // Method to generate random parameters
    cv::TrackerCSRT::Params _generateParams() override
    {
        cv::TrackerCSRT::Params params;

        // Генератор випадкових чисел
        std::random_device rd;
        std::mt19937 gen(rd());

        // Генерація випадкових значень для кожного параметра
        params.use_hog = getRandomBool();
        params.use_color_names = getRandomBool();
        params.use_gray = getRandomBool();
        params.use_rgb = getRandomBool();
        params.use_channel_weights = getRandomBool();
        params.use_segmentation = getRandomBool();

        params.window_function = getRandomWindowFunction();
        params.kaiser_alpha = getRandomFloat(minParams.kaiser_alpha, maxParams.kaiser_alpha);
        params.cheb_attenuation = getRandomFloat(minParams.cheb_attenuation, maxParams.cheb_attenuation);

        params.template_size = getRandomFloat(minParams.template_size, maxParams.template_size);
        params.gsl_sigma = getRandomFloat(minParams.gsl_sigma, maxParams.gsl_sigma);
        params.hog_orientations = getRandomFloat(minParams.hog_orientations, maxParams.hog_orientations);
        params.hog_clip = getRandomFloat(minParams.hog_clip, maxParams.hog_clip);
        params.padding = getRandomFloat(minParams.padding, maxParams.padding);
        params.filter_lr = getRandomFloat(minParams.filter_lr, maxParams.filter_lr);
        params.weights_lr = getRandomFloat(minParams.weights_lr, maxParams.weights_lr);
        params.num_hog_channels_used = getRandomInt(minParams.num_hog_channels_used, maxParams.num_hog_channels_used);
        params.admm_iterations = getRandomInt(minParams.admm_iterations, maxParams.admm_iterations);
        params.histogram_bins = getRandomInt(minParams.histogram_bins, maxParams.histogram_bins);
        params.histogram_lr = getRandomFloat(minParams.histogram_lr, maxParams.histogram_lr);
        params.background_ratio = getRandomInt(minParams.background_ratio, maxParams.background_ratio);
        params.number_of_scales = getRandomInt(minParams.number_of_scales, maxParams.number_of_scales);
        params.scale_sigma_factor = getRandomFloat(minParams.scale_sigma_factor, maxParams.scale_sigma_factor);
        params.scale_model_max_area = getRandomFloat(minParams.scale_model_max_area, maxParams.scale_model_max_area);
        params.scale_lr = getRandomFloat(minParams.scale_lr, maxParams.scale_lr);
        params.scale_step = getRandomFloat(minParams.scale_step, maxParams.scale_step);

        params.psr_threshold = getRandomFloat(minParams.psr_threshold, maxParams.psr_threshold);

        return params;
    }

private:
    // Генерація випадкового bool
    bool getRandomBool()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 1);
        return dis(gen) == 1;
    }

    // Генерація випадкового float у діапазоні [min, max]
    float getRandomFloat(float min, float max)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(min, max);
        return dis(gen);
    }

    // Генерація випадкового int у діапазоні [min, max]
    int getRandomInt(int min, int max)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    // Генерація випадкової функції вікна
    std::string getRandomWindowFunction()
    {
        static std::vector<std::string> windowFunctions = {"hann", "cheb", "kaiser"};
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, windowFunctions.size() - 1);
        return windowFunctions[dis(gen)];
    }
};