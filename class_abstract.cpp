// classes part 2
// - inheritence of abstrace base class
// - container and iterator

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// -----------------  ABSTRACT BASE CLASS ----------------------------------

class Shape {
public:
    Shape(string n) : nm(n) {}
    ~Shape() {}

    string name() const { return nm; };
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
private:
    const string nm;
};

// -----------------  DERIVED CLASSES  -------------------------------------

class Circle : public Shape{
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    ~Circle() {}

    virtual double area() const { return 3.14*radius*radius; }
    virtual double perimeter() const { return 3.14*2*radius; }
private:
    const double radius;
};

class Square : public Shape{
public:
    Square(double s) : Shape("Square"), side(s) {}
    ~Square() {}

    virtual double area() const { return side*side; }
    virtual double perimeter() const { return 4*side; }
private:
    const double side;
};

class Triangle : public Shape{
public:
    Triangle(double s) : Shape("Triangle"), side(s) {}
    ~Triangle() {}

    virtual double area() const { return 0.5*side * 0.5*sqrt(3)*side; }
    virtual double perimeter() const { return 3*side; }
private:
    const double side;
};

// -----------------  MAIN  ------------------------------------------------

int main()
{
    Circle circle(1);
    Square square(1);
    Triangle triangle(1);
    Shape *shapes[3] = {&circle, &square, &triangle};

    for (int i = 0; i < 3; i++) {
        cout << shapes[i]->name() 
             << " Area=" << shapes[i]->area() 
             << " Perimeter=" << shapes[i]->perimeter() 
             << endl;
    }

    return 0;
}
