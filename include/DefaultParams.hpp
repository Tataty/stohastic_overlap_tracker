#pragma once

#include <opencv2/tracking.hpp>

namespace DefaultParams
{
    static cv::TrackerCSRT::Params minParams()
    {
        cv::TrackerCSRT::Params params;
        params.padding = 0.5;
        params.template_size = 100.0;
        params.gsl_sigma = 0.1;
        params.filter_lr = 0.001;
        params.admm_iterations = 1;
        params.number_of_scales = 1;
        params.scale_sigma_factor = 0.1;
        params.scale_model_max_area = 16.0;
        params.scale_lr = 0.005;
        params.scale_step = 1.01;
        params.use_channel_weights = 0;
        params.weights_lr = 0.005;
        params.use_segmentation = 0;
        params.background_ratio = 5;
        params.psr_threshold = 0.005;
        params.use_hog = false;
        params.use_color_names = false;
        params.use_gray = false;
        params.use_rgb = false;
        params.window_function = "hann";
        params.kaiser_alpha = 1.0;
        params.cheb_attenuation = 20.0;
        params.hog_orientations = 6.0;
        params.hog_clip = 0.2;
        params.num_hog_channels_used = 9;
        params.histogram_bins = 8;
        params.histogram_lr = 0.01;
        return params;
    }

    static cv::TrackerCSRT::Params maxParams()
    {
        cv::TrackerCSRT::Params params;
        params.padding = 5.0;
        params.template_size = 600.0;
        params.gsl_sigma = 1.5;
        params.filter_lr = 0.1;
        params.admm_iterations = 50;
        params.number_of_scales = 100;
        params.scale_sigma_factor = 0.5;
        params.scale_model_max_area = 1024.0;
        params.scale_lr = 0.1;
        params.scale_step = 1.2;
        params.use_channel_weights = 1;
        params.weights_lr = 0.1;
        params.use_segmentation = 1;
        params.background_ratio = 20;
        params.psr_threshold = 0.1;
        params.use_hog = true;
        params.use_color_names = true;
        params.use_gray = true;
        params.use_rgb = true;
        params.window_function = "kaiser";
        params.kaiser_alpha = 3.0;
        params.cheb_attenuation = 40.0;
        params.hog_orientations = 18.0;
        params.hog_clip = 0.5;
        params.num_hog_channels_used = 18;
        params.histogram_bins = 32;
        params.histogram_lr = 0.1;
        return params;
    }

    void to_json(const std::string &filename, const cv::TrackerCSRT::Params &p)
    {
        nlohmann::json j;

        j = nlohmann::json{
            {"use_hog", p.use_hog},
            {"use_color_names", p.use_color_names},
            {"use_gray", p.use_gray},
            {"use_rgb", p.use_rgb},
            {"use_channel_weights", p.use_channel_weights},
            {"use_segmentation", p.use_segmentation},
            {"window_function", p.window_function},
            {"kaiser_alpha", p.kaiser_alpha},
            {"cheb_attenuation", p.cheb_attenuation},
            {"template_size", p.template_size},
            {"gsl_sigma", p.gsl_sigma},
            {"hog_orientations", p.hog_orientations},
            {"hog_clip", p.hog_clip},
            {"padding", p.padding},
            {"filter_lr", p.filter_lr},
            {"weights_lr", p.weights_lr},
            {"num_hog_channels_used", p.num_hog_channels_used},
            {"admm_iterations", p.admm_iterations},
            {"histogram_bins", p.histogram_bins},
            {"histogram_lr", p.histogram_lr},
            {"background_ratio", p.background_ratio},
            {"number_of_scales", p.number_of_scales},
            {"scale_sigma_factor", p.scale_sigma_factor},
            {"scale_model_max_area", p.scale_model_max_area},
            {"scale_lr", p.scale_lr},
            {"scale_step", p.scale_step},
            {"psr_threshold", p.psr_threshold}};

        std::ofstream outputFile(filename);
        outputFile << j.dump(4);
    }

    void from_json(const std::string &filename, cv::TrackerCSRT::Params &p)
    {
        std::ifstream inputFile(filename);
        nlohmann::json j;
        inputFile >> j;

        j.at("use_hog").get_to(p.use_hog);
        j.at("use_color_names").get_to(p.use_color_names);
        j.at("use_gray").get_to(p.use_gray);
        j.at("use_rgb").get_to(p.use_rgb);
        j.at("use_channel_weights").get_to(p.use_channel_weights);
        j.at("use_segmentation").get_to(p.use_segmentation);
        j.at("window_function").get_to(p.window_function);
        j.at("kaiser_alpha").get_to(p.kaiser_alpha);
        j.at("cheb_attenuation").get_to(p.cheb_attenuation);
        j.at("template_size").get_to(p.template_size);
        j.at("gsl_sigma").get_to(p.gsl_sigma);
        j.at("hog_orientations").get_to(p.hog_orientations);
        j.at("hog_clip").get_to(p.hog_clip);
        j.at("padding").get_to(p.padding);
        j.at("filter_lr").get_to(p.filter_lr);
        j.at("weights_lr").get_to(p.weights_lr);
        j.at("num_hog_channels_used").get_to(p.num_hog_channels_used);
        j.at("admm_iterations").get_to(p.admm_iterations);
        j.at("histogram_bins").get_to(p.histogram_bins);
        j.at("histogram_lr").get_to(p.histogram_lr);
        j.at("background_ratio").get_to(p.background_ratio);
        j.at("number_of_scales").get_to(p.number_of_scales);
        j.at("scale_sigma_factor").get_to(p.scale_sigma_factor);
        j.at("scale_model_max_area").get_to(p.scale_model_max_area);
        j.at("scale_lr").get_to(p.scale_lr);
        j.at("scale_step").get_to(p.scale_step);
        j.at("psr_threshold").get_to(p.psr_threshold);
    }

} // namespace DefaultParams