#include "stdafx.h"
#include "Point2D.h"


Point2D::Point2D(const double x, const double y)
{
	m_x = x;
	m_y = y;
}


Point2D::~Point2D()
{
}

double Point2D::GetXCoordinate() const
{
	return m_x;
}

double Point2D::GetYCoordinate() const
{
	return m_y;
}
