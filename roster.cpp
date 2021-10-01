#include <sstream>
#include <string>
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <map>

using namespace std;

//E.1.
Roster::Roster() {
	classRosterArray = new Student * [5];
};

//E.3.a.
void Roster::addStudent(int index, string id, string first, string last, string em, string a, int d1, int d2, int d3, DegreeProgram dp) {

	Student* student = new Student();
	student->setID(id);
	student->setFirstName(first);
	student->setLastName(last);
	student->setEmailAddress(em);
	student->setAge(a);
	student->setDays(d1, d2, d3);
	student->setDegreeProgram(dp);
	classRosterArray[index] = student;
}

//E.3.b.
void Roster::removeStudent(string sId) {
	bool exists = false;

	int iNumber = 0;

	for (int i = 0; i < 5; i++) {
		if (this->classRosterArray[i]->getID() == sId) {
			iNumber = i;
			exists = true;
			break;
		}
		else {
			exists = false;
			continue;
		}
	}
	cout << endl;
	if (exists) {
		cout << "Removing " << sId << endl;
		Student* student = new Student();
		classRosterArray[iNumber] = student;
		student->setID("NULL");
		student->setFirstName("");
		student->setLastName("");
		student->setEmailAddress("");
		student->setAge("");
		student->setDays(0, 0, 0);
		student->setDegreeProgram(UNDECIDED);
	}

	else {
		cout << "Removing " << sId << " again." << endl << endl;
		cout << "The student with the ID: " << sId << " was not found." << endl;
	}
}

//E.3.c.
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getID() != "NULL") {
			classRosterArray[i]->print(0);
			cout << "\t";
			classRosterArray[i]->print(1);
			cout << "\t";
			classRosterArray[i]->print(2);
			cout << "\t";
			classRosterArray[i]->print(4);
			cout << "\t{";
			classRosterArray[i]->print(5);
			cout << ",";
			classRosterArray[i]->print(6);
			cout << ",";
			classRosterArray[i]->print(7);
			cout << "}\t";
			printDegree(classRosterArray[i]->getDegreeProgram());
			cout << endl;
		}
	}
	cout << endl;
}
//E.3.d.
void Roster::printAverageDaysInCourse(string sId) {
	int average;
	int daysIn1;
	int daysIn2;
	int daysIn3;
	bool exists = false;
	int iNumber = 0;

	for (int i = 0; i <= 5; i++) {
		if (this->classRosterArray[i]->getID() == sId) {
			iNumber = i;
			exists = true;
			break;
		}
		else {
			exists = false;
			continue;
		}
	}

	if (exists) {
		daysIn1 = this->classRosterArray[iNumber]->getDays(0);
		daysIn2 = this->classRosterArray[iNumber]->getDays(1);
		daysIn3 = this->classRosterArray[iNumber]->getDays(2);
		average = ((daysIn1 + daysIn2 + daysIn3) / 3);

		cout << "Student ID: " << sId << ", average days in course is: " << average;
		cout << endl;

	}
	else {
		cout << "Student " << sId << " was not found.";
		cout << endl;
	}
}
//E.3.e
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:\n" << endl;


	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') == string::npos) {
			cout << email << endl;
		}
		else if (email.find('.') == string::npos) {
			cout << email << endl;
		}
		else if (email.find(' ') != string::npos) {
			cout << email << endl;
		}
	}
	cout << endl;
}
//E.3.f.
void Roster::printByDegreeProgram(DegreeProgram degree) {

	cout << "Showing students in degree program: "; printDegree(degree); "\n";
	cout << endl;
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i]->getDegreeProgram() == degree) {
			if (classRosterArray[i]->getID() != "NULL") {
				classRosterArray[i]->print(0);
				cout << "\t";
				classRosterArray[i]->print(1);
				cout << "\t";
				classRosterArray[i]->print(2);
				cout << "\t";
				classRosterArray[i]->print(4);
				cout << "\t{";
				classRosterArray[i]->print(5);
				cout << ",";
				classRosterArray[i]->print(6);
				cout << ",";
				classRosterArray[i]->print(7);
				cout << "}\t";
				printDegree(classRosterArray[i]->getDegreeProgram());
				cout << endl;
			}
		}
	}
}

//E.2.a
void Roster::parse(int Index) {
	string studentDataString = studentData[Index];
	string studentID = "";
	string firstName = "";
	string lastName = "";
	string email = "";
	string age = "";
	string stringDays1 = "";
	string stringDays2 = "";
	string stringDays3 = "";
	int days1 = 0;
	int days2 = 0;
	int days3 = 0;
	string stringDegree = "";

	int parString = studentDataString.length();
	int i = 0;
	int commas = 0;
	for (i = 0; i < parString; i++) {
		char x = studentDataString.at(i);
		if (x != ',') {
			switch (commas) {
			case 0:
				studentID.push_back(x);
				break;
			case 1:
				firstName.push_back(x);
				break;
			case 2:
				lastName.push_back(x);
				break;
			case 3:
				email.push_back(x);
				break;
			case 4:
				age.push_back(x);
				break;
			case 5:
				stringDays1.push_back(x);
				break;
			case 6:
				stringDays2.push_back(x);
				break;
			case 7:
				stringDays3.push_back(x);
				break;
			case 8:
				stringDegree.push_back(x);
				break;
			}
		}
		else {
			commas = commas + 1;
		}
	}

	DegreeProgram degreeP;
	if (stringDegree == "SECURITY") {
		degreeP = SECURITY;
	}
	else if (stringDegree == "NETWORK") {
		degreeP = NETWORK;
	}
	else if (stringDegree == "SOFTWARE") {
		degreeP = SOFTWARE;
	}
	else {
		degreeP = UNDECIDED;
	}
	stringstream translate1(stringDays1);
	translate1 >> days1;
	stringstream translate2(stringDays2);
	translate2 >> days2;
	stringstream translate3(stringDays3);
	translate3 >> days3;

	//E.2.b
	addStudent(Index, studentID, firstName, lastName, email, age, days1, days2, days3, degreeP);
}

void Roster::printDegree(int deg) {
	switch (deg) {
	case 0:
		cout << "SECURITY";
		break;
	case 1:
		cout << "NETWORK";
		break;
	case 2:
		cout << "SOFTWARE";
		break;
	default:
		cout << "UNDECIDED";
		break;
	}
}
Roster::~Roster() = default;