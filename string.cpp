// string class

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::istringstream;
using std::out_of_range;

int main()
{
    string s1, s2;

    // output a string
    s1 = "hello ";
    cout << "output string: " << s1 << endl;
    cout << endl;

    // append
    s1 = "hello ";
    s1 = s1 + "new ";
    cout << "after append of new: " << s1 << endl;
    s1 += " world";    
    cout << "after append of world: " << s1 << endl;
    cout << endl;

    // assign a string
    s1 = "hello ";
    s2 = s1;
    cout << "after assign: " << s2 << endl;
    cout << endl;

    // input a string
    cout << "enter a string: ";
    cin >> s1;
    cout << "you entered: " << s1 << endl;
    cout << endl;

    // ignore chars on input stream up until next newline
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // read a line
    cout << "enter a line: ";
    getline(cin,s1);
    cout << "you entered: " << s1 << endl;
    cout << endl;

    // methods: assign, substring, length, at, empty 
    s1 = "hello world";
    s2.assign(s1, 1, 3);
    cout << "substring from 'assign'= " << s2 << endl;
    s2 = s1.substr(1, 3);
    cout << "substring from 'substr': " << s2 << endl;
    cout << "length            = " << s2.length() << endl;
    cout << "at(0),at(1) at(2) = " << s2.at(0) << " " << s2.at(1) << " " << s2.at(2) << endl;
    cout << "empty             = " << std::boolalpha << s2.empty() << endl;
    cout << endl;

    // catch out of range exception
    cout << "generate an exception test" << endl;
    try {
        s1 = "123";
        cout << "does this print? " << s1.at(3) << endl;
    } catch (const out_of_range oor) {
        cout << "get exception << " << oor.what() << endl;
    }
    cout << endl;

    // compare 2 identical strings
    s1 = "compare identical strings";
    s2 = "compare identical strings";
    if (s1 == s2) {
        cout << "compare okay" << endl;
    } else {
        cout << "compare not okay" << endl;
    }
    cout << endl;

    // insert
    s1 = "123456789";
    s1.insert(5, " ABC ");
    cout << "insert_test: " << s1 << endl;
    cout << endl;

    // string iterator begin ... end
    s1 = "hello";
    cout << "individual chars: ";
    for (string::iterator i = s1.begin(); i != s1.end(); i++) {
        cout << "'" << *i << "' ";
    }
    cout << endl << endl;

    // string iterator begin ... end; using different for loop
    cout << "individual chars: ";
    for (auto &ch: s1) {
        cout << "'" << ch << "' ";
    }
    cout << endl << endl;

    // swap strings
    s1 = "first_string";
    s2 = "second_string";
    cout << "before_swap: " << s1 << " - " << s2 << endl;
    s1.swap(s2);
    cout << "after_swap:  " << s1 << " - " << s2 << endl;
    cout << endl;

    // convert to C language, method 1
    s1 = "convert_to_c_method_1";
    cout << "convert to c: " << s1.c_str() << endl;
    cout << endl;

    // convert to C language, method 2
    s1 = "convert_to_c_method_2";
    char *p = new char[s1.length()+1];
    s1.copy(p,s1.length());
    p[s1.length()] = '\0';
    cout << "convert to c: " << p << endl;
    delete [] p;
    cout << endl;

    // output string stream
    ostringstream outs;
    outs << "ostringstream test: " << "hello, pi=" << 3.14;
    cout << outs.str() << " - length=" << outs.str().length() << endl;
    cout << endl;

    // input string stream
    double n1=0,n2=0;
    istringstream ins("helloworld 1.0 3.14\n");
    ins >> s2 >> n1 >> n2;
    if (ins.good()) {
        cout << "istringstream test: GOOD - " << s2 << " " << n1 << " " << n2 << endl;
    } else {
        cout << "istringstream test: BAD" << endl;
    }
    cout << endl;

    // done
    return 0;
}
