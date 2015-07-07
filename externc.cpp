// externc
// - calling c language routines
// - calling routines from standard c header files

extern "C" {
int c_language_square(int x);
}

// c headers
#include <stdio.h>
#include <unistd.h>

// c++ headers
#include <iostream>
#include <thread>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::microseconds;

int main()
{
    // c++
    cout << "c++ print" << endl;
    // std::this_thread::sleep_for(std::chrono::microseconds(100000));
    sleep_for(microseconds(100000));

    // c
    printf("c print\n");
    usleep(100000);

    // call extern-c rotuine
    cout << "c_language_square(10) = " << c_language_square(10) << endl;
    return 0;
}

extern "C" {
int c_language_square(int x)
{
    return x * x;
}
}
