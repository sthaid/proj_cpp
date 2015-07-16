// threads
// - create
// - mutex
// - condition variables
// - atomic

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>

using std::cout;
using std::endl;
using std::hex;
using std::dec;
using std::thread;
using std::mutex;
using std::condition_variable;
using std::atomic;

mutex mtx1, mtx2, mtx3;

condition_variable cv;
mutex cv_mtx;
bool cv_ready = false;

atomic<long> atomic_counter(0);
long non_atomic_counter(0);

void microsec_sleep(long us)
{
    std::this_thread::sleep_for (std::chrono::microseconds(us));
}

void thread_proc(int id, int param1, int param2) 
{
#if 0
    {
        mtx1.lock();
        cout << "thread_proc(" << id << "): mtx1 starting\n";
        microsec_sleep(3000000);
        cout << "thread_proc(" << id << "): mtx1 complete\n";
        mtx1.unlock();
    }
#endif

#if 0
    {
        std::lock_guard<std::mutex> lck (mtx2);
        cout << "thread_proc(" << id << "): mtx2 starting\n";
        microsec_sleep(3000000);
        cout << "thread_proc(" << id << "): mtx2 complete\n";
    }
#endif

#if 0
    {
        std::unique_lock<std::mutex> lck (mtx3);
        cout << "thread_proc(" << id << "): mtx3 starting\n";
        microsec_sleep(3000000);
        cout << "thread_proc(" << id << "): mtx3 complete\n";
        lck.unlock();   // optional in this example
    }
#endif

#if 0
    {
        if (id == 0) {
            // wait
            std::unique_lock<std::mutex> cv_lck(cv_mtx);
            while (!cv_ready) {
                cv.wait(cv_lck);
            }
            cv_lck.unlock();
            cout << "thread_proc(" << id << "): wait completed\n";
        } else {
            // go
            microsec_sleep(3000000);
            cout << "thread_proc(" << id << "): notifying\n";
            cv_ready = true;
            cv.notify_one();
        }
    }
#endif

#if 1
    {
        for (long i = 0; i < 100000000; i++) {
            non_atomic_counter++;
        }
        for (long i = 0; i < 100000000; i++) {
            atomic_counter++;
        }
    }
#endif
}

int main()
{
    thread threads[2];

    // create the 2 threads
    for (int i = 0; i < 2; i++) {
        threads[i] = thread(thread_proc, i, 0, 0);
    }

    // print the thread ids
    cout << "main: thread ids = ";
    for (auto& th : threads) {
        cout << hex << th.get_id() << dec << " ";
    }
    cout << endl;

    // join
    cout << "main: calling join\n";
    for (auto& th : threads) {
        th.join();
    }

    // print completion info
    cout << "atomic_counter     = " << atomic_counter << endl;
    cout << "non_atomic_counter = " << non_atomic_counter << endl;
    cout << "main terminating" << endl;
    return 0;
}
