#include "namespace.h"

myns::Circle::Circle(double r)
{
    radius = r;
}

double myns::Circle::area() const
{
    return 3.14*radius*radius;
}
