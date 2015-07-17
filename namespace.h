#ifndef __MYNS_H__
#define __MYNS_H__

namespace myns {

class Circle {
public:
    Circle(double r);
    double area() const;
private:
    double radius;
};

}

#endif
