#pragma once

#include <opencv2/opencv.hpp>

class Evaluator
{
public:
    virtual void update(cv::Rect true_bbox, cv::Rect pred_bbox) = 0;

    void reset()
    {
        score = 0;
    }
    double getScore()
    {
        return score;
    }

protected:
    double score;
};
