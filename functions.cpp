// functions
// - overloading              DONE
// - default args             DONE
// - inline                   DONE
// - reference params         DONE
// - function templates       DONE
// - recursion for fibonacci  DONE

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

inline int func_increment(int &x) { return ++x; }

void func_default_args(int x=0, int y=0, int z=0)
{
    cout << "func_default_args: " << x << " " << y << " " << z << endl;
}   

void func_clear_array(int * array, int elements) 
{
    cout << "clearing array of " << elements << " ints" << endl;
    for (int i = 0; i < elements; i++) {
        array[i] = 0;
    }
}

void func_clear_array(double * array, int elements) 
{
    cout << "clearing array of " << elements << " doubles" << endl;
    for (int i = 0; i < elements; i++) {
        array[i] = 0;
    }
}

int func_fibonacci(unsigned int n) 
{
    if (n <= 1) {
        return n;
    } else {
        return func_fibonacci(n-1) + func_fibonacci(n-2);
    }
}

template<typename T>
void func_print_array(const char * title, T * array, int elements) 
{
    cout << title << " ";
    for (int i = 0; i < elements; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template<typename T>
void func_sort_array(T * array, int elements)
{
    bool exchanges;
    do {
        exchanges = false;
        for (int i = 0; i < elements-1; i++) {
            if (array[i] > array[i+1]) {
                T temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                exchanges = true;
            }
        }
    } while (exchanges);
}

// -----------------  MAIN  -----------------------------------

int main(int argc, char **argv)
{
    // print program args
    cout << "argc=" << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "  argv[" << i << "] = " << argv[i] << endl;
    }

    // default args
    func_default_args();
    func_default_args(1);
    func_default_args(1,2);
    func_default_args(1,2,3);

    // overloaded func
    double array_of_doubles[10];
    int array_of_ints[10];
    func_clear_array(array_of_doubles, 10);
    func_clear_array(array_of_ints, 10);

    // inline func, using reference variable
    int x = 5;
    cout << "func_increment return " << func_increment(x) << endl;
    cout << "  x was 5, and is now " << x << endl;

    // print first 10 fibonacci numbers
    cout << "fibonacci: ";
    for (int i = 0; i < 10; i++) {
        cout << func_fibonacci(i) << " ";
    }
    cout << endl;

    // template function to sort
    int int_array[10] = { 7,3,49,22,64,4,1,19,3,77 };
    func_print_array("before_sort", int_array, 10);
    func_sort_array(int_array, 10);
    func_print_array("after_sort", int_array, 10);

    double double_array[10] = { 9.9,7.6,3.3,99.999,55.123,18.76,44.12345,1.234,-0.5,50};
    func_print_array("before_sort", double_array, 10);
    func_sort_array(double_array, 10);
    func_print_array("after_sort", double_array, 10);

    // done
    return 0;
}
