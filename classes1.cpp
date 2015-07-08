// classes part 1
// - public, private, sections
// - constructors, destructors
//   - default args
// - accessors
// - operator overloading
// - const objects / member fucntions
// - constant members, and how to initialize them
// - class object assignment
//    - memberwise copy
//    - copy constructor
//    - override = operator
// - class composition  'has-a'
//   - composition   Person has-a Name, BirthDate

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

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
    Name(const char * f, const char * l);
    ~Name();
private:
    char first[100];  // xxx use new OR string
    char last[100];  // xxx use new OR string
};

Name::Name(const char * f, const char * l)
{
    strcpy(first,f);
    strcpy(last,l);  
}

Name::~Name()
{
}

ostream &operator<<(ostream &out, const Name &n)
{
    out << n.first << " " << n.last;
    return out;
}

// -----------------  CLASS PERSON  -------------------------

class Person {
    friend ostream &operator<<(ostream &out, const Person &p);
public:
    Person(const char * first, const char * last, int bmonth, int bday, int byear);
    ~Person() {}
// xxx get and set ?
private:
    Name name;
    Date birthdate;
};

Person::Person(const char * first, const char * last, int bmonth, int bday, int byear)
    : name(first,last), 
      birthdate(bmonth,bday,byear)
{
}

ostream &operator<<(ostream &out, const Person &p)
{
    out << p.name << " birthdate " << p.birthdate << endl;
    return out;
}

// -----------------  DERIVED CLASS STUDENT  ----------------

class Student : public Person {
    friend ostream &operator<<(ostream &out, const Student &s);
public:
    Student(const char * first, const char * last, 
            int bmonth, int bday, int byear,
            double gpa);
    ~Student();
    void set_gpa(double gpa);
    double get_gpa() const;
private:
    double grade_point_average;
};

Student::Student(const char * first, const char * last, 
        int bmonth, int bday, int byear,
        double gpa)
    : Person(first, last, bmonth, bday, byear),
      grade_point_average(gpa)
{
}

Student::~Student()
{
}

void Student::set_gpa(double gpa)
{
    grade_point_average = gpa;
}

double Student::get_gpa() const
{
    return grade_point_average;
}

ostream &operator<<(ostream &out, const Student &s)
{
    // out <<  XXXX left off here

    return out;
}

// -----------------  DERIVED CLASS EMPLOYEE  ---------------

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

}
