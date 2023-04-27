#ifndef TIME_H
#define TIME_H

#include "pch.h"

class Time
{
    typedef std::chrono::high_resolution_clock ChronoTime;
    typedef ChronoTime::time_point TimePoint;
    typedef std::chrono::duration<double> Duration;

    Duration deltaTime = static_cast<Duration>(1.0 / 60.0); // Actual game loop delta time, init to 1/60 s which is the ideal dt.
    TimePoint TimeStart;                                    // Starting Time of Game loop
    TimePoint TimeEnd;                                      // Ending Time of Game loop

    double accumulatedTime;

public:
    float dt = 1 / 60.f;
    size_t step = 1U;

    Time()
    {
        this->dt = 1 / 60.f;
    }

    Time(float dt)
    {
        this->dt = dt;
    }

    float GetDeltaTime() { return this->dt; }
    void SetDeltaTime(float setDt) { this->dt = setDt; }

    void FrameStart()
    {
        TimeStart = std::chrono::high_resolution_clock::now();
    }

    size_t CalculateTimeSteps(float givenFixedDt)
    {
        size_t currentNumberOfSteps = 0;
        deltaTime = std::chrono::duration_cast<Duration>(TimeEnd - TimeStart);
        accumulatedTime += deltaTime.count(); // deltaTime.count() returns number of seconds in type double.
        while (accumulatedTime >= givenFixedDt)
        {
            accumulatedTime -= static_cast<double>(givenFixedDt);
            currentNumberOfSteps++;
        }
        return currentNumberOfSteps;
    }

    void FrameEnd()
    {
        TimeEnd = std::chrono::high_resolution_clock::now(); // This function gets the current time
    }

    void CoreUpdate(std::function<void()> lambda)
    {
        FrameStart();
        lambda(); // execute user lambda
        FrameEnd();
        this->step = CalculateTimeSteps(this->dt);
    }

    void SystemUpdate(float givenFixedDt, std::function<void()> lambda)
    {
        size_t steps = CalculateTimeSteps(givenFixedDt);
        for (size_t i = 0; i < steps; i++)
        {
            lambda();
        }
    }
};

#endif /* TIME_H */
