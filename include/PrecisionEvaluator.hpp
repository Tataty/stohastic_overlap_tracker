#pragma once

#include "Evaluator.hpp"

class PrecisionEvaluator : public Evaluator
{
public:
    void update(cv::Rect true_bbox, cv::Rect pred_bbox) override
    {
        score += fabs(pred_bbox.x - true_bbox.x) +
                 fabs(pred_bbox.y - true_bbox.y) +
                 fabs((pred_bbox.x + pred_bbox.width) - (true_bbox.x + true_bbox.width)) +
                 fabs((pred_bbox.y + pred_bbox.height) - (true_bbox.y + true_bbox.height));
    }
};
