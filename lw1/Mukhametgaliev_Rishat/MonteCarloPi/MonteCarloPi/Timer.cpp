#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
}


Timer::~Timer()
{
}

void Timer::Start()
{
	m_startTime = clock();
}

void Timer::Stop()
{
	m_endTime = clock();
}

double Timer::GetPassedTime() const
{
	return (m_endTime != 0) ? (clock() - m_startTime) / (double)CLOCKS_PER_SEC : (m_endTime - m_startTime) / (double)CLOCKS_PER_SEC;
}
