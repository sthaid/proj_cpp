#include <iostream>

#include "namespace.h"

using std::cout;
using std::endl;

using myns::Circle;

int main()
{
    Circle c(10);    

    cout << "area = " << c.area() << endl;
    return 0;
}
