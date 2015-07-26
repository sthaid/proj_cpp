// file i/o
// - sequential 
// - random access

// NOTES ...
//
// open flags
//   ios::in     Open for input.
//   ios::out    Open for output.
//   ios::binary Open in binary mode.
//   ios::ate    Set position at end of file, can subsequently seek.
//   ios::app    Append to file, can't seek.
//   ios::trunc  Truncate file, if it exists, and opening in output mode.
//
// good, bad, fail, eof member funcs
//   bad()  - reading or writing has failed, for example the file is not open for writing
//   fail() - same as bad, but also is set when a format error happens
//   eof()  - when an attempt to read past eof has occurred
//   good() - most generic: returns false if bad,fail,or eof is true
//
// seak direction 
//   ios::beg    offset counted from the beginning of the stream
//   ios::cur    offset counted from the current position
//   ios::end    offset counted from the end of the stream

#include <iostream>
#include <fstream>
#include <cstdint>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;
using std::ios;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::streamoff;

int main() 
{
    ifstream ifs;
    ofstream ofs;
    char c;

    cout << boolalpha;

    cout << "create file.dat" << endl;
    ofs.open("file.dat", ios::out|ios::trunc);
    assert(ofs.is_open());
    for (char c = 'A'; c < 'A'+10; c++) {
        ofs << c;
    }
    cout << "  bad,fail,eof,good,is_open = " 
         << ofs.bad() << " " 
         << ofs.fail() << " " 
         << ofs.eof() << " " 
         << ofs.good() << " " 
         << ofs.is_open() << endl;
    cout << "  tellp = " << ofs.tellp() << endl;
    ofs.close();
    cout << "  after close: is_open = " << ofs.is_open() << endl;
    
    cout << "read file.dat sequentially";
    ifs.open("file.dat", ios::in);
    assert(ifs.is_open());
    while (ifs >> c) {
        cout << c << " ";
    }
    cout << endl;
    ifs.close();

    cout << "get file size: ";
    ifs.open("file.dat", ios::in|ios::ate);
    assert(ifs.is_open());
    streamoff size = ifs.tellg();
    ifs.close();
    cout << "size = " << size << size;

    cout << "random file read access: ";
    ifs.open("file.dat", ios::in|ios::ate);
    assert(ifs.is_open());
    for (streamoff off = ifs.tellg() - static_cast<streamoff>(1); off >= 0; off--) {
        ifs.seekg(off,ios::beg);
        ifs.read(&c, 1);
        cout << c << " ";
    }
    ifs.close();
    cout << endl;
}
