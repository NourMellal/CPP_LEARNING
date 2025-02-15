#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point(const float x, const float y) : x(x), y(y) { }

Point::Point(const Point& rhs) : x(rhs.x), y(rhs.y) { }

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) { }

Point &Point::operator=(const Point& rhs)
{
    (void)rhs;
    return *this;
}

Point::~Point() { }

bool Point::operator==(const Point &rhs)
{
    return (x == rhs.x && y == rhs.y);
}

const Fixed &Point::get_x() const
{
    return x;
}

const Fixed &Point::get_y() const
{
    return y;
}
