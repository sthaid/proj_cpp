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
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::exception;

// -----------------  VECTOR CONTAINER  --------------------------

void vector_test()
{
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
    
    cout << endl;
}



// -----------------  MAIN  --------------------------------------

int main()
{
    cout << std::boolalpha;

    vector_test();

    cout << "-- DONE --" << endl;
}


