#pragma once

#include <opencv2/tracking.hpp>
#include <functional>

class GeneratorParams
{
public:
    using ModifierFunction = std::function<void(cv::TrackerCSRT::Params &)>;

    void setRange(const cv::TrackerCSRT::Params &min, const cv::TrackerCSRT::Params &max)
    {
        minParams = min;
        maxParams = max;
    }

    void setModifierFunction(ModifierFunction modifier)
    {
        modifierFunction = modifier;
    }

    cv::TrackerCSRT::Params generateParams()
    {
        cv::TrackerCSRT::Params params = _generateParams();
        if (modifierFunction)
        {
            modifierFunction(params);
        }
        return params;
    }

protected:
    virtual cv::TrackerCSRT::Params _generateParams() = 0;

    cv::TrackerCSRT::Params minParams;
    cv::TrackerCSRT::Params maxParams;

    ModifierFunction modifierFunction;
};