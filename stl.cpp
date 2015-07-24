// standard template library
//
// - containers
//   - sequence:     vector, deque, list              : first class
//   - associative:  set, multiset, map, multimap     : first class
//   - adapter:      stack, queue, priority_queue     : oo iterators ??
//   - near:         string, bitset, valarray         : near containers
//
// - some methods of container objects
//   - empty, size, max_sixe
//   - == != > >= < <= 
//   - =
//   - swap
//   - begin, end, rbegin, rend
//   - erase : erase one or more elements
//   - clear : erase all elements
//
// - stl header files
//   - vector, list, deque, queue, stack, map, set, bitset
//
// - typedefs
//   - value_type, 
//   - reference, const_reference, pointer
//   - iterator, const_iterator, reverse_iterator, const_reverse_iterator
//   - difference_type
//   - size_type
//
// - iterators categories
//   - input, output, forward, bidirectional, random access
//     - for example: 'iterator' is forward, read/write
//                     const_iterator'  is forward, readonly
//
// - iterator operations
//   - ++p  p++  --p  p--
//   - *p 
//   - =  ==  !=  +=  -=  +  -  []  <  <=  >  >=
//
// - algorithms
//   - XXX 

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

using std::cout;
using std::endl;
using std::exception;

// -----------------  VECTOR CONTAINER  --------------------------

void vector_test()
{
    using std::vector;

    vector<int> v;
    vector<int>::iterator p;
    vector<int>::reverse_iterator rp;

    cout << "-- VECTOR TEST --" << endl;

    cout << "init v 1,2,3" << endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "  v empty=" << v.empty() << " size=" << v.size() << " max_size=" << v.max_size() << endl;

    cout << "auto print v = ";
    for (auto &i: v) {
        cout << i << " ";
    }
    cout << endl;

    cout << "forward print v = ";
    for (p = v.begin(); p != v.end(); p++) {
        cout << *p << " ";
    }
    cout << endl;

    cout << "reverse print v = ";
    for (rp = v.rbegin(); rp != v.rend(); rp++) {
        cout << *rp << " ";
    }
    cout << endl;

    cout << "clear v" << endl;
    v.clear();
    cout << "  v = "; for (auto &i: v) cout << i << " "; cout << endl;
    cout << "  v empty=" << v.empty() << " size=" << v.size() << " max_size=" << v.max_size() << endl;

    cout << "init v 4,5,6" << endl;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    cout << "erase v first 2 elements" << endl;
    v.erase(v.begin(),v.begin()+2);
    cout << "  v = "; for (auto &i: v) cout << i << " "; cout << endl;

    cout << "read elements of v" << endl;
    try {
        cout << "  v[0]    = " << v[0] << endl;
        cout << "  v.at(0) = " << v.at(0) << endl;
        cout << "  v[1]    = " << v[1] << " ** INVALID READ **" << endl;
        cout << "  v.at(1) = " << v.at(1) << " ** INVALID READ **" << endl;
    } catch (const std::out_of_range e) {
        cout << "  exception " << e.what() << endl;
    }
    
    cout << "write element using copy to output iterator: ";
    std::ostream_iterator<int> out(cout, " ");
    v.clear();
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    std::copy(v.begin(), v.end(), out);
    cout << endl;

    cout << "insert at begining: ";
    v.insert(v.begin(), 6);
    std::copy(v.begin(), v.end(), out);
    cout << endl;

    cout << endl;
}

void list_test()
{
    using std::list;

    const int SIZE = 5;
    int data[SIZE] = { 10, 5, 3, 15, 13 };
    list<int> l(data,data+SIZE);
    list<int>::iterator p;
    list<int>::reverse_iterator rp;
    std::ostream_iterator<int> out(cout, " ");

    cout << "-- LIST TEST --" << endl;

    cout << "print list using copy: ";
    std::copy(l.begin(), l.end(), out);
    cout << endl;

    cout << "print list using iterator: ";
    for (auto &i: l) {
        cout << i << " ";
    }
    cout << endl;

    cout << "add to head and tail, and print: ";
    l.push_front(13);
    l.push_back(0);
    std::copy(l.begin(), l.end(), out);
    cout << endl;

    cout << "sort: ";
    l.sort();
    std::copy(l.begin(), l.end(), out);
    cout << endl;

    cout << "unique: ";
    l.unique();
    std::copy(l.begin(), l.end(), out);
    cout << endl;

    cout << "reverse: ";
    l.reverse();
    std::copy(l.begin(), l.end(), out);
    cout << endl;

    cout << "splice: ";
    list<int> x;
    x.push_back(-1);
    x.push_back(-2);
    x.push_back(-3);
    std::copy(x.begin(), x.end(), out); cout << endl;
    l.splice(l.begin(),x);
    cout << "  l = "; std::copy(l.begin(), l.end(), out); cout << endl;
    cout << "  x = "; std::copy(x.begin(), x.end(), out); cout << endl;

    cout << "swap: " << endl;
    l.swap(x);
    cout << "  l = "; std::copy(l.begin(), l.end(), out); cout << endl;
    cout << "  x = "; std::copy(x.begin(), x.end(), out); cout << endl;

    cout << "merge: " << endl;
    l.clear();
    x.clear();
    l.push_back(1); l.push_back(3); l.push_back(5);
    x.push_back(2); x.push_back(4); x.push_back(6);
    cout << "  l = "; std::copy(l.begin(), l.end(), out); cout << endl;
    cout << "  x = "; std::copy(x.begin(), x.end(), out); cout << endl;
    l.merge(x);
    cout << "  l = "; std::copy(l.begin(), l.end(), out); cout << endl;
    cout << "  x = "; std::copy(x.begin(), x.end(), out); cout << endl;

    cout << endl;
}

void deque_test()
{
    using std::deque;

    const int SIZE = 3;
    int data[SIZE] = { 10, 20, 30 };
    deque<int> q(data, data+SIZE);
    std::ostream_iterator<int> out(cout, " ");

    cout << "-- DEQUE TEST --" << endl;

    cout << "init: ";
    std::copy(q.begin(), q.end(), out);
    cout << endl;

    cout << "add to front and back (0 and 40)" << endl;
    q.push_front(0);
    q.push_back(40);

    cout << "print with for loop: " << endl;
    for (unsigned int i = 0; i < q.size(); i++) {
        cout << "  q[" << i << "] = " << q[i] << endl;
    }

    cout << "print with for loop: " << endl;
    for (unsigned int i = 0; i < q.size(); i++) {
        cout << "  q.at(" << i << ") = " << q.at(i) << endl;
    }

    cout << "after pop_front = ";
    q.pop_front();
    std::copy(q.begin(), q.end(), out); cout << endl;

    cout << endl;
}

// -----------------  MAIN  --------------------------------------

int main()
{
    cout << std::boolalpha;

    vector_test();
    list_test();
    deque_test();

    cout << "-- DONE --" << endl;
}


