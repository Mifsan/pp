#pragma once
#include <ctime>

class Timer
{
public:
	Timer();
	~Timer();
	void Start();
	void Stop();
	double GetPassedTime() const;
private:
	std::clock_t m_startTime = 0;
	std::clock_t m_endTime = 0;
};

