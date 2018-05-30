#pragma once
class Point2D
{
public:
	Point2D(const double x, const double y);
	~Point2D();
	double GetXCoordinate() const;
	double GetYCoordinate() const;
private:
	double m_x;
	double m_y;
};

