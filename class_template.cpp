// class 
// - templates

#include <iostream>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

// -----------------  TEMPLATE ARRAY CLASS ----------------------------

template<class T>
class Array;

template<class T>
ostream &operator<<(ostream &out, const Array<T> &x);

template<class T>
class Array {
    friend ostream &operator<<<T>(ostream &, const Array &);
public:
    Array(int n);
    ~Array() { delete [] ptr; }

    void set(int n, T value) { ptr[n] = value; }
    T operator[](int n) const { return ptr[n]; }
private:
    T * ptr;
    int elems;
};

template<class T>
Array<T>::Array(int n) 
{ 
    const char * datatype = typeid(T).name();

    ptr = new T[n]; 
    elems = n; 
    cout << "constructed " << elems << " array of " << datatype << endl;
}

template<class T>
ostream &operator<<(ostream &out, const Array<T> &x)
{
    for (int i = 0; i < x.elems; i++) {
        out << x.ptr[i] << " ";
    }
    return out;
}

// -----------------  MAIN  -------------------------------------------

void int_array_test();
void double_array_test();

int main()
{
    int_array_test();
    double_array_test();
    return 0;
}

void int_array_test()
{
    cout << "INT ARRAY TEST" << endl << endl;

    Array<int> x(10);

    cout << "init array" << endl;
    for (int i = 0; i < 10; i++) {
        x.set(i,i*i);
    }
    cout << endl;

    cout << "print each array element ..." <<  endl;
    for (int i = 0; i < 10; i++) {
        cout << "Array[" << i << "] = " << x[i] << endl;
    }
    cout << endl;

    cout << "print with overloaded << ..." << endl;
    cout << "Array = " << x << endl;
    cout << endl;
}
        
void double_array_test()
{
    cout << "DOUBLE ARRAY TEST" << endl << endl;

    Array<double> x(10);

    cout << "init array" << endl;
    for (int i = 0; i < 10; i++) {
        x.set(i,1./i);
    }
    cout << endl;

    cout << "print each array element ..." <<  endl;
    for (int i = 0; i < 10; i++) {
        cout << "Array[" << i << "] = " << x[i] << endl;
    }
    cout << endl;

    cout << "print with overloaded << ..." << endl;
    cout << "Array = " << x << endl;
    cout << endl;
}

