#pragma once
#include "Point2D.h"
#include <Windows.h>

const double CIRCLE_RADIUS = 1;

class MonteCarloPi
{
public:
	MonteCarloPi(const size_t numOfIterations, const size_t numOfThreads = 1);
	~MonteCarloPi();
	double GetResultPi() const;
	void Run();

private:
	static DWORD WINAPI GeneratePointsInCircle(LPVOID lpParam);

	Point2D GetRandomPoint();
	bool IsPointInsideTheCircle(const Point2D & point);
	size_t m_innerPointsCount = 0;
	size_t m_iterationsCount = 0;
	size_t m_numOfIterations;
	size_t m_numOfThreads;
};

