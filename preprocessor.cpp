// preprocessr
// - macros
// - joining


#include <iostream>
#include <string>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

#define PRINT(x) cout << "PRINT: " << #x << endl
#define JOIN(x,y) x ## y

int main()
{
    // print constants
    cout << "__LINE__   = " << __LINE__ << endl;
    cout << "__FILE__   = " << __FILE__ << endl;
    cout << "__DATE__   = " << __DATE__ << endl;
    cout << "__TIME__   = " << __TIME__ << endl;

    // the # operator
    PRINT(hello world);

    // the ## operator
    cout << "PI = " << JOIN(3, .14159) << endl;

    // assertion passed
    cout << "assert passed test: ";
    int x = 5;
    assert(x == 5);
    cout << "  okay" << endl;

    // asertion failed,
    // notes: 
    // - to enable dump:   ulimit -c unlimited
    // - to analyze dump:  gdb <executable> <core>
    cout << "assert failed test: " << endl;
    assert(x == 10);
    cout << "  **** SHOULD NOT BEREACHED ****" << endl;

    cout << endl;
    return 0;
}
