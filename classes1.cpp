// classes part 1
// - public, private, sections
// - constructors, destructors, default constructor args
// - accessors
// - operator overloading
// - const objects / member fucntions
// - class composition  'has-a'
// - constant members, and how to initialize them           XXX
// - class object assignment                                XXX
//    - memberwise copy
//    - copy constructor
//    - override = operator

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
    ~Date() {}

    Date &set_month(int m) { month = m; return *this; }
    Date &set_day(int d) { day = d; return *this; }
    Date &set_year(int y) { year = y; return *this; }

    int get_month() const { return month; }
    int get_day() const {return day; }
    int get_year() const {return year; }

    void print() const;

    Date operator++(int);   // postincrement
    Date  operator++();      // preincrement
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
    Name(const string f, const string l) : first(f), last(l) {}
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
    Person(const char * first, const char * last, int bmonth, int bday, int byear)
        : name(first,last), birthdate(bmonth,bday,byear) {}
    ~Person() {}
private:
    const Name name;
    const Date birthdate;
};

ostream &operator<<(ostream &out, const Person &p)
{
    out << p.name << " birthdate " << p.birthdate;
    return out;
}

// -----------------  DERIVED CLASS STUDENT  ----------------

class Student : public Person {
    friend ostream &operator<<(ostream &out, const Student &s);
public:
    Student(const char * first, const char * last, 
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
    Person p = s;

    out << p << " gpa " << s.gpa_val;
    return out;
}

// -----------------  DERIVED CLASS EMPLOYEE  ---------------

class Employee : public Person {
    friend ostream &operator<<(ostream &out, const Employee &e);
public:
    Employee(const char * first, const char * last,
            int bmonth, int bday, int byear,
            int hmonth, int hday, int hyear)
            : Person(first, last, bmonth, bday, byear), hiredate(hmonth,hday,hyear) {}
    ~Employee() {}
private:
    Date hiredate;
};

ostream &operator<<(ostream &out, const Employee &e)
{
    Person p = e;

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

    // test Name class
    Name n("John", "Smith");
    cout << "Name is " << n << endl;

    // test Person class
    Person p("Jane", "Smith", 1, 2, 3);
    cout << "Person is " << p << endl;

    // test Student derived class
    Student s("Jane", "Jones", 4, 5, 6, 3.5);
    cout << "Student is " << s << endl;

    // test Employee derived class
    Employee e("Roger", "Smith", 5, 6, 7, 8, 9, 10);
    cout << "Employee is " << e << endl;

    // array of Person
    Person *parray[3] = { &p,&s,&e };
    for (int i = 0; i < 3; i++) {
        cout << "parray[" << i << "] = " << *parray[i] << endl;
    }

    // XXX
    Person newp(p);


}
