// classes overview
// - public, private, sections
// - constructors, destructors, default constructor args, copy constructors
// - accessors
// - operator overloading
// - const objects, members, and member fucntions
// - static members
// - class composition  'has-a'

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

// -----------------  CLASS DATE  ---------------------------

class Date {
    friend ostream &operator<<(ostream &, const Date &);
public:
    Date(int m=0, int d=0, int y=0) { set_month(m); set_day(d); set_year(y); }
    Date(const Date &d) { set_month(d.month); set_day(d.day); set_year(d.year); }
    ~Date() {}

    Date &set_month(int m) { month = m; return *this; }
    Date &set_day(int d) { day = d; return *this; }
    Date &set_year(int y) { year = y; return *this; }

    int get_month() const { return month; }
    int get_day() const {return day; }
    int get_year() const {return year; }

    void print() const;

    Date operator++(int);   // postincrement
    Date operator++();      // preincrement
    Date operator+(int) const;
private:
    int month;
    int day;
    int year;
};

ostream &operator<<(ostream &out, const Date &d)
{
    out << d.month << "/" << d.day << "/" << d.year;
    return out;
}

void Date::print() const
{
    cout << month << "/" << day << "/" << year;
}

Date Date::operator++(int dummy) // postincrement
{
    Date ret = *this;
    day++;
    return ret;
}

Date Date::operator++() // preincrement
{
    day++;
    return *this;
}

Date Date::operator+(int value) const
{
    Date ret = *this;
    
    ret.set_day(ret.get_day() + value);
    return ret;
}

// -----------------  CLASS NAME  ---------------------------

class Name {
    friend ostream &operator<<(ostream &, const Name &);
public:
    Name(const string f="", const string l="") : first(f), last(l) {}
    Name(const Name &n) : first(n.first), last(n.last) {}

    Name &set_first(string f) { first = f; return *this; }
    Name &set_last(string l) { last = l; return *this; }

    string get_first() const { return first; }
    string get_last() const { return last; }
    ~Name() {}
private:
    string first;
    string last;
};

ostream &operator<<(ostream &out, const Name &n)
{
    out << n.first << " " << n.last;
    return out;
}

// -----------------  CLASS PERSON  -------------------------

class Person {
    friend ostream &operator<<(ostream &out, const Person &p);
public:
    Person();
    Person(const string first, const string last, int bmonth, int bday, int byear);
    Person(const Person &);  // copy constructor
    ~Person();

    Person &operator=(const Person &);

    static int get_count();
private:
    Name name;
    Date birthdate;

    static int count;
};

Person::Person()
{
    count++;
    cout << " -- person default constructor" << endl;
}

Person::Person(const string first, const string last, int bmonth, int bday, int byear)
    : name(first,last), 
      birthdate(bmonth,bday,byear) 
{   
    count++;
    cout << " -- person constructor for " << name << " - count " << count << endl; 
}

Person::Person(const Person &p)
    : name(p.name), 
      birthdate(p.birthdate)
{
    count++;
    cout << " -- person copy constructor for " << name << " - count " << count << endl; 
}

Person::~Person() 
{
    count--;
    cout << " -- person destructor for " << name << " - count " << count << endl; 
}

Person &Person::operator=(const Person &p)
{
    if (this == &p) {
        cout << "** prevent self assignment **" << endl;
        return *this;
    }

    this->name = p.name;
    this->birthdate = p.birthdate;
    return *this;
}

int Person::count = 0;

int Person::get_count()
{
    return Person::count;
}

ostream &operator<<(ostream &out, const Person &p)
{
    out << p.name << " birthdate " << p.birthdate;
    return out;
}

// -----------------  DERIVED CLASS STUDENT  ----------------

class Student : public Person {
    friend ostream &operator<<(ostream &out, const Student &s);
public:
    Student(const string first, const string last, 
            int bmonth, int bday, int byear,
            double gpa)
            : Person(first, last, bmonth, bday, byear), gpa_val(gpa) {}
    ~Student() {}
    void set_gpa(double gpa) { gpa_val = gpa; }
    double get_gpa() const { return gpa_val; }
private:
    double gpa_val;
};

ostream &operator<<(ostream &out, const Student &s)
{
    const Person &p = s;

    out << p << " gpa " << s.gpa_val;
    return out;
}

// -----------------  DERIVED CLASS EMPLOYEE  ---------------

class Employee : public Person {
    friend ostream &operator<<(ostream &out, const Employee &e);
public:
    Employee(const string first, const string last,
            int bmonth, int bday, int byear,
            int hmonth, int hday, int hyear)
            : Person(first, last, bmonth, bday, byear), hiredate(hmonth,hday,hyear) {}
    ~Employee() {}
private:
    Date hiredate;
};

ostream &operator<<(ostream &out, const Employee &e)
{
    const Person &p = e;

    out << p << " hiredate " << e.hiredate;
    return out;
}

// -----------------  MAIN  ---------------------------------

int main()
{
    // test Date class
    Date d;
    d.set_month(1).set_day(2).set_year(3);
    cout << "date is initially " << d << endl;
    cout << "date is post-incremented " << d++ << endl;
    cout << "date is now " << d << endl;
    cout << "date is pre-incremented " << ++d << endl;
    cout << "date is now " << d << endl;
    d = d + 5;
    cout << "date is added by 5 " << d << endl;
    cout << endl;

    // test Name class
    Name n("Name", "Test");
    cout << "Name is " << n << endl;
    cout << endl;

    // test Person class
    Person p("Person", "Class", 1, 2, 3);
    cout << "Person is " << p << endl;
    cout << endl;

    // test Student derived class
    Student s("Student", "Derived", 4, 5, 6, 3.5);
    cout << "Student is " << s << endl;
    cout << endl;

    // test Employee derived class
    Employee e("Employee", "Derived", 5, 6, 7, 8, 9, 10);
    cout << "Employee is " << e << endl;
    cout << endl;

    // array of ptr to Person
    Person *parray[3] = { &p,&s,&e };
    for (int i = 0; i < 3; i++) {
        cout << "parray[" << i << "] = " << *parray[i] << endl;
    }
    cout << endl;

    // array of reference to Person
    // ERROR: Person &ref_array[3] = { &p,&s,&e };

    // array of reference to Person, by embedding reference in a structure
    struct {
        Person &p;
    } ref[3] = { {p}, {s}, {e} };
    for (int i = 0; i < 3; i++) {
        cout << "ref[" << i << "].p = " << ref[i].p << endl;
    }
    cout << endl;

    // copy constructor, and alternate form of copy constructor
    cout << "person count before copy construct= " << Person::get_count() << endl;
    Person p2(p);
    cout << "p2: " << p2 << endl;
    cout << "person count after copy construct= " << Person::get_count() << endl;
    cout << endl;

    cout << "person count before copy alternate construct= " << Person::get_count() << endl;
    Person p3 = p;
    cout << "p3: " << p3 << endl;
    cout << "person count after alternate copy construct= " << Person::get_count() << endl;
    cout << endl;

    // object assignment
    Person p4;
    cout << "default person p4: " << p4 << endl;
    p4 = p;
    cout << "person p4 after assignment: " << p4 << endl;
    p4 = p4;
    cout << "person p4 after self assignment: " << p4 << endl;
    cout << endl;

    // const object
    const Person p5("Const", "Person", 9,9,9);
    cout << "const person " << p5 << endl;
    // ERROR p5 = p;
    cout << endl;

    // terminating
    cout << "program terminating" << endl;
    cout << endl;
}
