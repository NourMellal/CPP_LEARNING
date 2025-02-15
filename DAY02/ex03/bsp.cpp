#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Point AB(b.get_x() - a.get_x(), b.get_y() - a.get_y());
    Point BC(c.get_x() - b.get_x(), c.get_y() - b.get_y());
    Point CA(a.get_x() - c.get_x(), a.get_y() - c.get_y());

    Point AP(point.get_x() - a.get_x(), point.get_y() - a.get_y());
    Point BP(point.get_x() - b.get_x(), point.get_y() - b.get_y());
    Point CP(point.get_x() - c.get_x(), point.get_y() - c.get_y());

    Fixed cross1 = AB.get_x() * AP.get_y() - AB.get_y() * AP.get_x();
    Fixed cross2 = BC.get_x() * BP.get_y() - BC.get_y() * BP.get_x();
    Fixed cross3 = CA.get_x() * CP.get_y() - CA.get_y() * CP.get_x();

    return ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0));
}
