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

    float GetDeltaTime() { return this->dt; }
    void SetDeltaTime(float setDt) { this->dt = setDt; }

    void FrameStart()
    {
        TimeStart = std::chrono::high_resolution_clock::now();
    }

    size_t CalculateTimeSteps(float given_dt)
    {
        size_t currentNumberOfSteps = 0;
        deltaTime = std::chrono::duration_cast<Duration>(TimeEnd - TimeStart);
        accumulatedTime += deltaTime.count(); // deltaTime.count() returns number of seconds in type double.
        while (accumulatedTime >= given_dt)
        {
            accumulatedTime -= static_cast<double>(given_dt);
            currentNumberOfSteps++;
        }
        return currentNumberOfSteps;
    }

    void FrameEnd()
    {
        TimeEnd = std::chrono::high_resolution_clock::now(); // This function gets the current time
    }

    void Update(void (*lambda)()){
        FrameStart();
        lambda(); //execute user lambda
        FrameEnd();
        
        this->step = CalculateTimeSteps(this->dt);
    }


};

#endif /* TIME_H */
