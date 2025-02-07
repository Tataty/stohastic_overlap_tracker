#pragma once

#include <memory>
#include <opencv2/tracking.hpp>
#include <opencv2/opencv.hpp>

#include "Evaluator.hpp"
#include "TestVideo.hpp"

class Agent
{
public:
    Agent() = default;

    void init(std::unique_ptr<TestVideo> tv, std::unique_ptr<Evaluator> ev)
    {
        testVideo = std::move(tv);
        evaluator = std::move(ev);
    }

    void setParams(const cv::TrackerCSRT::Params &p)
    {
        params = p;
        tracker = cv::TrackerCSRT::create(params);
    }

    cv::TrackerCSRT::Params getParams() const
    {
        return params;
    }

    void estimate(bool display = false)
    {
        if (tracker.empty())
        {
            throw std::runtime_error("Tracker is not initialized");
        }

        /* Init */
        cv::Mat frame;
        cv::Rect true_bbox, pred_bbox;
        bool is_tracker = true;

        testVideo->reset();
        evaluator->reset();

        /* Pre-Update */
        testVideo->nextFrame(frame, true_bbox);
        tracker->init(frame, true_bbox);

        /* Update */
        while (testVideo->nextFrame(frame, true_bbox))
        {
            if (is_tracker)
            {
                try
                {
                    is_tracker = tracker->update(frame, pred_bbox);

                    if (pred_bbox.area() == 0)
                        is_tracker = false;
                }
                catch (cv::Exception &e)
                {
                    is_tracker = false;
                }

                if (!is_tracker)
                {
                    pred_bbox = cv::Rect(0, 0, 0, 0);
                }
            }

            if (is_tracker && display)
            {
                cv::Mat display_frame = frame.clone();

                cv::rectangle(display_frame, true_bbox, cv::Scalar(0, 255, 0), 2); // Green for true_bbox
                cv::rectangle(display_frame, pred_bbox, cv::Scalar(0, 0, 255), 2); // Red for pred_bbox

                cv::imshow("Tracking", display_frame);
                cv::waitKey(30);
            }

            evaluator->update(true_bbox, pred_bbox);
        }
        tracker.release();
    }

    double getScore() const
    {
        return evaluator->getScore();
    }

private:
    std::unique_ptr<TestVideo> testVideo;
    std::unique_ptr<Evaluator> evaluator;

    cv::TrackerCSRT::Params params;
    cv::Ptr<cv::TrackerCSRT> tracker;
};
