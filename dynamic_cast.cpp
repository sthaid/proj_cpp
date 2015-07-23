// dynamic cast 

#include <iostream>
#include <string>
#include <typeinfo>

using std::cout;
using std::endl;
using std::string;

class Shape {
public:
    Shape(int x=0, int y=0) : x_loc(x), y_loc(y) {}
    int get_x() const { return x_loc; }
    int get_y() const { return y_loc; }
    virtual string get_name() const { return "shape"; }
private:
    int x_loc;
    int y_loc;
}; 

class Circle: public Shape {
public:
    Circle(int x=0, int y=0, int r=1) : Shape(x,y), radius(r) {}
    int get_radius() const { return radius; }
    virtual string get_name() const { return "circle"; }
private:
    int radius;
};

class Triangle: public Shape {
public:
    Triangle(int x=0, int y=0, int s=1) : Shape(x,y), side(s) {}
    int get_side() const { return side; }
    virtual string get_name() const { return "triangle"; }
private:
    int side;
};

void print(Shape *s);

int main() 
{
    Shape shape;
    Circle circle(1,1,10);
    Triangle triangle(2,2,20);
    
    print(&shape);
    print(&circle);
    print(&triangle);

    return 0;
}

void print(Shape *s)
{
    cout  << s->get_name() << " " << s->get_x() << " " << s->get_y() << " ";
    if (Circle * c =dynamic_cast<Circle*>(s)) {
        cout << "radius=" << c->get_radius();
    } 
    if (Triangle * t =dynamic_cast<Triangle*>(s)) {
        cout << "side=" << t->get_side();
    }
    cout << " - DataType is " << typeid(*s).name();
    cout << endl;
}
