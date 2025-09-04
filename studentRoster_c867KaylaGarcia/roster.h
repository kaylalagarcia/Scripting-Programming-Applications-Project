#pragma once
#include "student.h"

class Roster 
{
public:
	const static int studentDataInfo = 5;
	Student* classRosterArray[studentDataInfo];
	int lastIndex = -1;

public:

	void parse(string row);
	void add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sDays1, int sDays2, int sDays3, DegreeProgram degreeProgram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDaysInClass(string studentID);
	void removeStudentByID(string studentID);
	Roster();
	~Roster();
};