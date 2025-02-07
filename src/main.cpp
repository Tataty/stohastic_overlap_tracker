
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>
#include <iostream>

#include "Agent.hpp"
#include "PrecisionEvaluator.hpp"
#include "RandomParams.hpp"
#include "MutationParams.hpp"
#include "TestVideo.hpp"
#include "DefaultParams.hpp"

void ParameterModifier(cv::TrackerCSRT::Params &params)
{
    params.use_hog = false;
    params.use_color_names = false;
    params.use_gray = true;
    params.use_rgb = false;
    params.use_segmentation = false;
    params.window_function = "kaiser";
}

const std::string TEST_VIDEO_DIR = "/mnt/a/Markup/1_drone_cut_fine_tuning/";
const std::string SAVE_DIR = "/home/rusa/rusagot_genetic_optimizer_tracker/";

const int NUM_EPOCH = 2;
const int NUM_THREADS = 32;

const int AGENTS_PER_THREAD = 1;
const int NUM_AGENTS = AGENTS_PER_THREAD * NUM_THREADS;

void processAgents(Agent agents[AGENTS_PER_THREAD])
{
    for (int i = 0; i < AGENTS_PER_THREAD; i++)
    {
        agents[i].estimate();
    }
}

int main()
{
    std::cout << "Create Random Generator." << std::endl;
    RandomParams randomParams;
    randomParams.setRange(DefaultParams::minParams(), DefaultParams::maxParams());
    randomParams.setModifierFunction(ParameterModifier);

    std::cout << "Create Mutation Generator." << std::endl;
    MutationParams mutationParams;
    mutationParams.setRange(DefaultParams::minParams(), DefaultParams::maxParams());
    mutationParams.setModifierFunction(ParameterModifier);

    std::cout << "Create Agents array." << std::endl;
    Agent agents[NUM_AGENTS];

    // Ініціалізація агентів
    std::cout << "Init Agents." << std::fflush;
    for (int i = 0; i < NUM_AGENTS; i++)
    {
        std::cout << i << "." << std::fflush;
        agents[i].init(std::make_unique<TestVideo>(TEST_VIDEO_DIR), std::make_unique<PrecisionEvaluator>());
        agents[i].setParams(randomParams.generateParams());
    }
    std::cout << std::endl;

    for (int epoch = 0; epoch < NUM_EPOCH; epoch++)
    {
        std::cout << "Epoch " << epoch << std::endl;

        // Паралельна обробка агентів
        std::vector<std::thread> threads;

        std::cout << "Estimate Agents." << std::fflush;
        for (int t = 0; t < NUM_AGENTS; t++)
        {
            std::cout << t << "." << std::fflush;
            agents[t].estimate();
        }
        std::cout << std::endl;

        // std::cout << "Threads." << std::fflush;
        // for (int t = 0; t < NUM_THREADS; t++)
        // {
        //     int startIdx = t * AGENTS_PER_THREAD;

        //     std::cout << t << "." << std::fflush;
        //     threads.emplace_back(processAgents, agents + sizeof(Agent) * startIdx);
        // }
        // std::cout << std::endl;

        // std::cout << "Join." << std::fflush;
        // for (auto &thread : threads)
        // {
        //     std::cout << "." << std::fflush;
        //     thread.join();
        // }

        // Знаходження агента з найменшим score
        int minIndex = 0;
        double minScore = agents[0].getScore();
        for (int i = 1; i < NUM_AGENTS; i++)
        {
            double score = agents[i].getScore();
            if (score < minScore)
            {
                minScore = score;
                minIndex = i;
            }
        }

        // Збереження параметрів найкращого агента
        std::string params_filename = SAVE_DIR + "best_params_" + std::to_string(epoch) + ".json";
        DefaultParams::to_json(params_filename, agents[minIndex].getParams());

        // Виведення результатів
        std::cout << "Best agent score: " << minScore << std::endl;
        std::cout << "Best params save to: " << params_filename << std::endl;

        agents[minIndex].estimate(true);

        // Мутація параметрів
        mutationParams.setBasicParams(agents[minIndex].getParams());

        for (int i = 0; i < NUM_AGENTS; i++)
        {
            agents[i].setParams(mutationParams.generateParams());
        }
    }

    return 0;
}
