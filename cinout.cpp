// character i/o 

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::hex;
using std::setprecision;
using std::setiosflags;
using std::resetiosflags;
using std::setw;
using std::ostream;
using std::istream;
using std::ios;

struct person {
    char first[100];
    char last[100];
};

istream &operator>>(istream &i, struct person &p);
ostream &operator<<(ostream &o, const struct person &p);

inline ostream& bell(ostream& o) { return o << '\a'; }

int main()
{
    // char output
    cout << "hello!" << endl;
    cout << "numbers: " << 7 << " " << 22./7. << " " << 1.23e99 << endl;
    char char_array[] = "this is char_array";
    cout << "chars:   " << char_array << endl;

    // char input
    while (true) {
        int n1,n2;
        cout << "enter 2 numbers: ";
        cin >> n1 >> n2;
        cout << "cin state:"
             << " rdstate=" << cin.rdstate() 
             << " eof="     << cin.eof() 
             << " fail="    << cin.fail() 
             << " bad="     << cin.bad() 
             << " good="    << cin.good() 
             << endl;
        if (cin.eof()) {
            cout << "terminating\n";
            return 0;
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "try again - ";
            continue;
        }
        if (n1 == -1 || n2 == -1) {
            break;
        }
        cout << n1 << " + " << n2 << " = " << n1+n2 << endl;
    }
    cin.ignore(1000, '\n');

    // getline
    char line[100];
    cout << "enter a line: ";
    cin.getline(line,sizeof(line));
    cout << "you entered: " << line << endl;

    // input and output in hex
    int n;
    cout << "enter a hex number: ";
    cin >> hex >> n;
    cout << " ... is " << n << " decimal, or " << hex << n << " hex" << endl;

    // floating point precision
    double x = sqrt(2);
    cout << "sqrt(2) = " << setprecision(20) << x << endl;

    // field width
    cout << "field width is 10: " 
         << setw(10) << 1
         << setw(10) << 2
         << setw(10) << 3
         << endl;

    // test bell function
    cout << "test bell: " << bell << endl;

    // iosflags
    std::ios_base::fmtflags orig_flags = cout.flags();
    cout << "orig_flags: " << hex << orig_flags << endl;

    cout << "all hex: " 
         << resetiosflags(ios::dec) 
         << setiosflags(ios::hex | ios::showbase) 
         << setw(10) << 253
         << setw(10) << 254
         << setw(10) << 255
         << endl;

    cout.flags(orig_flags);
    cout << "after flags restored: " 
         << setw(10) << 253
         << setw(10) << 254
         << setw(10) << 255
         << endl;

    cout.setf(ios::hex | ios::showbase);
    cout.unsetf(ios::dec);
    cout << "all hex: " 
         << setw(10) << 253
         << setw(10) << 254
         << setw(10) << 255
         << endl;

    cout.unsetf(ios::hex | ios::showbase);
    cout.setf(ios::dec);
    cout << "after flags restored: " 
         << setw(10) << 253
         << setw(10) << 254
         << setw(10) << 255
         << endl;

    // overloaded cout
    struct person p;
    cin >> p;
    cout << p;

    // done
    return 0;
}

istream &operator>>(istream &i, struct person &p)
{
    cout << "PERSON? ";
    cin >> p.first >> p.last;
    return i;
}

ostream &operator<<(ostream &o, const struct person &p)
{
    cout << "PERSON: " << p.first << " " << p.last << endl;
    return o;
}
