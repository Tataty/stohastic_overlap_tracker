#pragma once

#include <memory>
#include <random>
#include <algorithm>
#include <vector>

#include "GeneratorParams.hpp"
#include "Agent.hpp"

class MutationParams : public GeneratorParams
{
public:
    MutationParams(double rate = 0.1, double mutationRange = 10.0)
        : mutationRate(rate), mutationRange(mutationRange)
    {
        if (rate < 0 || rate > 1)
        {
            throw std::invalid_argument("Mutation rate must be in range [0, 1].");
        }
    }

    void setBasicParams(const cv::TrackerCSRT::Params &p)
    {
        this->basicParams = p;
    }

protected:
    cv::TrackerCSRT::Params _generateParams() override
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        cv::TrackerCSRT::Params newParams = basicParams;

        // Мутація для кожного параметра
        mutate(newParams.use_hog, gen);
        mutate(newParams.use_color_names, gen);
        mutate(newParams.use_gray, gen);
        mutate(newParams.use_rgb, gen);
        mutate(newParams.use_channel_weights, gen);
        mutate(newParams.use_segmentation, gen);

        mutate(newParams.window_function, gen);
        mutate(newParams.kaiser_alpha, gen, minParams.kaiser_alpha, maxParams.kaiser_alpha);
        mutate(newParams.cheb_attenuation, gen, minParams.cheb_attenuation, maxParams.cheb_attenuation);

        mutate(newParams.template_size, gen, minParams.template_size, maxParams.template_size);
        mutate(newParams.gsl_sigma, gen, minParams.gsl_sigma, maxParams.gsl_sigma);
        mutate(newParams.hog_orientations, gen, minParams.hog_orientations, maxParams.hog_orientations);
        mutate(newParams.hog_clip, gen, minParams.hog_clip, maxParams.hog_clip);
        mutate(newParams.padding, gen, minParams.padding, maxParams.padding);
        mutate(newParams.filter_lr, gen, minParams.filter_lr, maxParams.filter_lr);
        mutate(newParams.weights_lr, gen, minParams.weights_lr, maxParams.weights_lr);
        mutate(newParams.num_hog_channels_used, gen, minParams.num_hog_channels_used, maxParams.num_hog_channels_used);
        mutate(newParams.admm_iterations, gen, minParams.admm_iterations, maxParams.admm_iterations);
        mutate(newParams.histogram_bins, gen, minParams.histogram_bins, maxParams.histogram_bins);
        mutate(newParams.histogram_lr, gen, minParams.histogram_lr, maxParams.histogram_lr);
        mutate(newParams.background_ratio, gen, minParams.background_ratio, maxParams.background_ratio);
        mutate(newParams.number_of_scales, gen, minParams.number_of_scales, maxParams.number_of_scales);
        mutate(newParams.scale_sigma_factor, gen, minParams.scale_sigma_factor, maxParams.scale_sigma_factor);
        mutate(newParams.scale_model_max_area, gen, minParams.scale_model_max_area, maxParams.scale_model_max_area);
        mutate(newParams.scale_lr, gen, minParams.scale_lr, maxParams.scale_lr);
        mutate(newParams.scale_step, gen, minParams.scale_step, maxParams.scale_step);

        mutate(newParams.psr_threshold, gen, minParams.psr_threshold, maxParams.psr_threshold);

        return newParams;
    }

private:
    cv::TrackerCSRT::Params basicParams;
    double mutationRate;
    double mutationRange;

    // Мутація для bool (інвертування значення)
    void mutate(bool &param, std::mt19937 &gen)
    {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        if (dist(gen) < mutationRate)
        {
            param = !param;
        }
    }

    // Мутація для float
    void mutate(float &param, std::mt19937 &gen, float min, float max)
    {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        if (dist(gen) < mutationRate)
        {
            float delta = (max - min) / mutationRange;
            std::uniform_real_distribution<float> deltaDist(-delta, delta);
            param = std::clamp(param + deltaDist(gen), min, max);
        }
    }

    // Мутація для int
    void mutate(int &param, std::mt19937 &gen, int min, int max)
    {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        if (dist(gen) < mutationRate)
        {
            int delta = static_cast<int>((max - min) / mutationRange);
            std::uniform_int_distribution<int> deltaDist(-delta, delta);
            param = std::clamp(param + deltaDist(gen), min, max);
        }
    }

    // Мутація для std::string (випадковий вибір зі списку)
    void mutate(std::string &param, std::mt19937 &gen)
    {
        static const std::vector<std::string> windowFunctions = {"hann", "cheb", "kaiser"};
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        if (dist(gen) < mutationRate)
        {
            std::uniform_int_distribution<size_t> idxDist(0, windowFunctions.size() - 1);
            param = windowFunctions[idxDist(gen)];
        }
    }
};