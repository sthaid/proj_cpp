// exceptions
// - try. catch, throw
// - new, bad_alloc
// - unique_ptr
// - set_unexpected 

#include <iostream>
#include <stdexcept>
#include <memory>
#include <new>

#define GB (1024*0x100000L)

using std::cout;
using std::endl;
using std::exception;
using std::bad_alloc;
using std::unique_ptr;

class my_exception : public exception {
public:
    my_exception() throw() { cout << "my_exception: constructor\n"; }
    virtual ~my_exception() throw() { cout << "my_exception: destructor\n"; }
    virtual const char * what() const throw() { return "MYEXCEPTION"; }
};

int func_throw_exception(void) 
{
    throw exception();
    cout << "func_throw_exception: after throw" << endl;
    return 0;
}

void my_unexpected_handler(void)
{
    cout << "my_unexpected_handler: called, program exitting" << endl;
    exit(1);
}

void test_set_unexpected(void) throw()
{
    throw my_exception();
}

// -----------------  MAIN  -------------------------------------------

int main()
{
    // catch std::exception
    try {
        func_throw_exception();
        cout << "main: after func_throw_exception call, should not be here" << endl;
    } catch (exception &e) {
        cout << "main: exception caught -  " << e.what() << endl;
    }

    // catch std::bad_alloc
    try {
        char * p = new char[1000*GB];
        cout << "main: after new, should not be here, p=" << p << endl;
    } catch (bad_alloc &ba) {
        cout << "main: bad_alloc exception caught -  " << ba.what() << endl;
    }

    // catch std::exception, followed by catch of any other exception
    try {
        char * p = new char[1000*GB];
        cout << "main: after new, should not be here, p=" << static_cast<void*>(p) << endl;
    } catch (exception &e) {
        cout << "main: exception caught -  " << e.what() << endl;
    } catch (...) {
        cout << "main: unknown exception caught, should not be here"  << endl;
    }

    // catch any exception    
    try {
        char * p = new char[1000*GB];
        cout << "main: after new, should not be here, p=" << static_cast<void*>(p) << endl;
    } catch (...) {
        cout << "main: unknown exception caught"  << endl;
    }

    // unique_ptr
    try {
        unique_ptr<int[]> x (new int[100]);
        for (int i = 0; i < 100; i++) {
            x[i] = i;
        }
        throw my_exception();
        cout << "main: after throw exception" << endl;
    } catch (exception &e) {
        cout << "main: exception caught, unique_ptr automatically freed -  " << e.what() << endl;
    }

    // test set_unexpected
    std::set_unexpected(my_unexpected_handler);
    test_set_unexpected();

    // terminating
    cout << __func__ << ": terminating" << endl;
    return 0;
}

