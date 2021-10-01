#include <string>
#include "student.h"
using namespace std;
//A.1.
const string studentData[5] = {
  "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
  "A5,Rick,R,#######,00,8,18,15,SOFTWARE"
};
//E.
class Roster {
public:

    Roster();
    void printDegree(int deg);
    //E.1.
    Student** classRosterArray;

    //E.2.
    void parse(int Index);

    //E.3.a.
    void addStudent(int index, string id, string first, string last, string em, string a, int d1, int d2, int d3, DegreeProgram dp);

    //E.3.b.
    void removeStudent(string sId);

    //E.3.c.
    void printAll();

    //E.3.d.
    void printAverageDaysInCourse(string sId);

    //E.3.e.
    void printInvalidEmails();

    //E.3.f.
    void printByDegreeProgram(DegreeProgram degree);

    ~Roster();
};
