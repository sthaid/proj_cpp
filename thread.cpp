// XXX tbd
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

void proc(void) 
{
    cout << "proc starting\n";
    std::this_thread::sleep_for (std::chrono::seconds(5));
    cout << "proc done\n";
}

int main()
{
    std::thread t(proc);
    
    cout << "main calling join\n";
    t.join();

    cout << "main terminating\n";
    return 0;
}
