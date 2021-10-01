#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {


    //F.2.
    Roster* classRoster = new Roster();

    //F.3.
    for (int i = 0; i <= 5; i++) { classRoster->parse(i); }

    //F.4.
    cout << "Displaying all students: ";
    cout << endl;
    classRoster->printAll();

    //F.4.
    classRoster->printInvalidEmails();

    //F.4.
    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse
        (classRoster->classRosterArray[i]->getID());
    } cout << endl;

    //F.4.
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;

    //F.4.
    classRoster->removeStudent("A3");
    cout << endl;

    //F.4>
    classRoster->printAll();

    //F.4.
    classRoster->removeStudent("A3");

    //F.5.
    cout << "Done." << endl;
    return 0;
}