#include "stdafx.h"
#include "MonteCarloPi.h"
#include "Point2D.h"
#include "ThreadHandler.h"

MonteCarloPi::MonteCarloPi(const size_t numOfIterations, const size_t numOfThreads)
{
	m_numOfIterations = numOfIterations;
	m_numOfThreads = numOfThreads;
}

MonteCarloPi::~MonteCarloPi()
{
}

double MonteCarloPi::GetResultPi() const
{
	return 4 * ((double)m_innerPointsCount / (double)m_numOfIterations);
}

void MonteCarloPi::Run()
{
	ThreadHandler threadHandler;
	for (size_t i = 1; i < m_numOfThreads; i++)
	{
		threadHandler.Add(GeneratePointsInCircle, this);
	}
	GeneratePointsInCircle(this);
	threadHandler.JoinAll();
}

DWORD MonteCarloPi::GeneratePointsInCircle(LPVOID lpParam)
{
	MonteCarloPi* monteCarloPi = (MonteCarloPi*)lpParam;
	for (; monteCarloPi->m_iterationsCount < monteCarloPi->m_numOfIterations; InterlockedIncrement(&monteCarloPi->m_iterationsCount))
	{
		Point2D point = monteCarloPi->GetRandomPoint();
		if (monteCarloPi->IsPointInsideTheCircle(point))
		{
			InterlockedIncrement(&monteCarloPi->m_innerPointsCount);
		}
	}
	return 0;
}

Point2D MonteCarloPi::GetRandomPoint()
{
	return Point2D(double(rand()) / (RAND_MAX + 1), double(rand()) / (RAND_MAX + 1));
}

bool MonteCarloPi::IsPointInsideTheCircle(const Point2D & point)
{
	return ((point.GetXCoordinate() * point.GetXCoordinate()) + (point.GetYCoordinate() * point.GetYCoordinate())) <= (CIRCLE_RADIUS * CIRCLE_RADIUS);
}