#include "roster.h"
#include "student.h"
#include <iostream>
using namespace std;

int main() 
{
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 000782257" << endl;
	cout << "Student Name: Kayla Garcia" << endl;
    cout << endl;
    cout << endl;

	const string studentData[] = 
    { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Kayla,Garcia,kgarc73@wgu.edu,28,15,40,25,SOFTWARE"
	};

	const int studentDataInfo = 5;
    Roster classRoster;// parameterless constructor

    for (int i = 0; i < studentDataInfo; i++) classRoster.parse(studentData[i]);
    cout << "All students in class roster: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Average days in class: " << endl;
    cout << "\n";
    classRoster.printAverageDaysInClass("A5");
    cout << endl;

    cout << "Software students:" << endl;
    cout << "\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    cout << "Remove student A3" << endl;
    classRoster.removeStudentByID("A3");
    cout << endl;

    classRoster.removeStudentByID("A3");
    cout << endl;

    system("pause");
    return 0;
}