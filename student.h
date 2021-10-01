#pragma once
#include "degree.h"

using namespace std;
class Student {

private:
    //D.1.
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    string age;
    int daysInCourse[3];
    DegreeProgram degree;

public:
    //D.2.a.
    string getID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    string getAge();
    int getDays(int daysArray);
    DegreeProgram getDegreeProgram();

    //D.2.b.
    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(string age);
    void setDays(int day1, int day2, int day3);
    void setDegreeProgram(DegreeProgram degree);

    //D.2.d.
    Student();

    //D.2.e.
    void print(int arrayPosition);
};
