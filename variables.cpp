// variables 
// - pointers    
// - references
// - enum
// - arrays
//   - setting size with variable
//   - sorting
// - new & delete
// - const
// - static_cast, const_cast, reinterpret_cast
// - bool data type

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

void func_increment(int&);
void func_print_int(const int&);
void func_bogus_print_int(const int&);

// -----------------  MAIN  -----------------------------------

int main(int argc, char **argv)
{
    int var;
    int *ptr_to_var;
    int &ref_to_var = var;

    // variable, ptr, ref
    var = 5;
    ptr_to_var = &var;
    cout << "var         = " << var << endl
         << "*ptr_to_var = " << *ptr_to_var << "  ptr_to_var = " << ptr_to_var << endl
         << "ref_to_var  = " << ref_to_var << endl;
    cout << endl;

    // call with reference var
    func_increment(var);
    cout << "var is incremented to " << var << endl;
    func_print_int(var);
    func_print_int(7);  // okay because arg is 'const int&'
    cout << endl;

    // new and delete  
    int * new_var = new int (77);
    cout << "new_var = " << *new_var << endl;
    delete new_var;
    cout << endl;

    // new and delete for arrays
    int * new_array = new int[10];
    for (int i = 0; i < 10; i++) {
        new_array[i] = i;
    }
    cout << "ptr to new_array = " << new_array << endl;
    cout << "new_array[] = ";
    for (int i = 0; i < 10; i++) {
        cout << new_array[i] << " ";
    }
    cout << endl;
    delete [] new_array;
    cout << endl;


    unsigned char (*static_pixels)[1000];
    static_pixels = new unsigned char[1000]  [1000];
    cout << "XXX " << static_pixels << endl;
    int i, j;
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            static_pixels[i][j] = 7;
        }
    }
    cout << endl;
    cout << endl;

    delete [] static_pixels;
    

    // enum 
    enum fruits {APPLE, PEAR, BANANA, GRAPE};
    enum fruits f;
    f = APPLE;
    cout << "enum fruit values = " << APPLE << " " << PEAR << " ..." << endl;
    cout << "enum f = " << f << endl;

    // typedef enum
    typedef enum cars {CHEVY, FORD, HONDA, TOYOTA} cars_t;
    cars_t c = FORD;
    cout << "enum c = " << c << endl;
    cout << endl;

    // const
    const char * s1 = "char string";
    s1 = "another char string";
    cout << "s1 = " << s1 << endl;

    const char * const s2 = "s2 is constant ptr to constant char string";
    cout << "s2 = " << s2 << endl;
    // ERROR  s2 = "another char string";
    cout << endl;

    // create an array of dynamic size
    int array_size = 100;
    char array[array_size];
    cout << "sizeof array " << sizeof(array) << endl;
    cout << endl;

    // bool data type
    bool flag = false;
    cout << "bool flag = " 
         << flag << " " << !flag << " "
         << boolalpha 
         << flag << " " << !flag << " "
         << endl;
    cout << endl;

    // static_cast
    double pi = 3.14;
    cout << "pi = " << pi << endl;
    cout << "pi as int = " << static_cast<int>(pi) << endl;
    cout << endl;

    // const_cast
    int z = 99;
    func_bogus_print_int(z);
    cout << "after func_bogus_print_int z=" << z << endl;
    cout << endl;

    // reinterpret_cast, and
    // c language cast
    int x = 0x00434241;
    cout << "test of reinterpret_cast: " 
         << reinterpret_cast<char*>(&x)
         << endl;
    cout << "test of c language cast: " 
         << (char*)&x
         << endl;
    cout << endl;

    // done
    return 0;
}

void func_increment(int &arg)
{
    arg++;
}

void func_print_int(const int &arg)
{
    cout << "func_print_int " << arg << endl;
}

void func_bogus_print_int(const int &arg)
{
    cout << "func_bogus_print_int " << arg << endl;
    
    // try to increment arg
    // ERROR arg++;

    // increment the const arg
    int &x = const_cast<int&>(arg);
    x++;
}
