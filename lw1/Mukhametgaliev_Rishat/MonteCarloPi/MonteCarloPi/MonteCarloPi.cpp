#include "stdafx.h"
#include "MonteCarloPi.h"
#include "Point2D.h"

MonteCarloPi::MonteCarloPi(const size_t numOfIterations, const size_t numOfThreads)
{
	m_numOfIterations = numOfIterations;
	m_numOfThreads = numOfThreads;
}

MonteCarloPi::~MonteCarloPi()
{
}

void MonteCarloPi::GeneratePointsInCircle()
{
	m_innerPointsCount = 0;
	for  (size_t i = 0; i < m_numOfIterations; i++)
	{
		Point2D point = GetRandomPoint();
		if (IsPointInsideTheCircle(point))
		{
			m_innerPointsCount++;
		}
	}
}

double MonteCarloPi::GetResultPi() const
{
	return 4 * ((double)m_innerPointsCount / (double)m_numOfIterations);
}

Point2D MonteCarloPi::GetRandomPoint()
{
	return Point2D(double(rand()) / (RAND_MAX + 1), double(rand()) / (RAND_MAX + 1));
}

bool MonteCarloPi::IsPointInsideTheCircle(const Point2D & point)
{
	return ((point.GetXCoordinate() * point.GetXCoordinate()) + (point.GetYCoordinate() * point.GetYCoordinate())) <= (CIRCLE_RADIUS * CIRCLE_RADIUS);
}
