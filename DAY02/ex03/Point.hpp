#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float x, const float y);
    Point(const Fixed x, const Fixed y);
    Point(const Point& rhs);
    
    Point &operator=(const Point& rhs);
    bool operator==(const Point& rhs);

    const Fixed &get_x() const;
    const Fixed &get_y() const;
    ~Point();
};
