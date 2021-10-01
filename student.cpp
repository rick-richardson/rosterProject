#include <string>
#include <iostream>
#include "student.h"

using namespace std;

//D.2.a.
string Student::getID()
{
    return studentID;
}
string Student::getFirstName()
{
    return firstName;
}
string Student::getLastName()
{
    return lastName;
}
string Student::getEmailAddress()
{
    return emailAddress;
}
string Student::getAge()
{
    return age;
}
int Student::getDays(int daysArray)
{
    return daysInCourse[daysArray];
}
DegreeProgram Student::getDegreeProgram()
{
    return degree;
}

//D.2.b.
void Student::setID(string studentID)
{
    this->studentID = studentID;
}
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}
void Student::setAge(string age)
{
    this->age = age;
}
void Student::setDays(int day1, int day2, int day3)
{
    this->daysInCourse[0] = day1; this->daysInCourse[1] = day2; this->daysInCourse[2] = day3;
}
void Student::setDegreeProgram(DegreeProgram degree)
{
    this->degree = degree;
}

//D.2.d.
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = "";
    for (int i = 0; i < 3; i++)
    {
        this->daysInCourse[i] = 0;
    }
    this->degree = UNDECIDED;
};
//D.2.e.
void Student::print(int arrayPosition) {
    switch (arrayPosition) {
    case 0:
        cout << studentID;
        break;
    case 1:
        cout << firstName;
        break;
    case 2:
        cout << lastName;
        break;
    case 3:
        cout << emailAddress;
        break;
    case 4:
        cout << age;
        break;
    case 5:
        cout << daysInCourse[0];
        break;
    case 6:
        cout << daysInCourse[1];
        break;
    case 7:
        cout << daysInCourse[2];
        break;
    case 8:
        cout << degree;
        break;
    default:
        cout << "NULL";
        break;
    }
}