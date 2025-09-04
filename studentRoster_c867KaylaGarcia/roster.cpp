#include "roster.h"
using namespace std;

Roster::Roster(){}

void Roster::parse(string studentData) 
{
	DegreeProgram degreeProgram = SECURITY;//default value
	if (studentData.back() =='E') degreeProgram = SOFTWARE;
	else if (studentData.back() == 'K') degreeProgram = NETWORK;

	int rhs = studentData.find(",");//locate comma
	string sID = studentData.substr(0, rhs);//student ID

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sfn = studentData.substr(lhs, rhs - lhs);//first name
	
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sln = studentData.substr(lhs, rhs - lhs);//last name

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string sem = studentData.substr(lhs, rhs - lhs);//email

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int sage = stoi(studentData.substr(lhs, rhs - lhs));//age

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d1 = stoi(studentData.substr(lhs, rhs - lhs));//days in class 1

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d2 = stoi(studentData.substr(lhs, rhs - lhs));//days in class 2

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int d3 = stoi(studentData.substr(lhs, rhs - lhs));//days in class 3

	add(sID, sfn, sln, sem, sage, d1, d2, d3, degreeProgram);
}

void Roster::add(string studentID, string studentFirstName, string studentLastName, string studentEmail, int age, int daysInClass1, int daysInClass2, int daysInClass3, DegreeProgram degreeProgram)
{
	int daysarray[3] = { daysInClass1,daysInClass2,daysInClass3 };
	
	classRosterArray[++lastIndex] = new Student(studentID, studentFirstName, studentLastName, studentEmail, age, daysarray, degreeProgram);
}

void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << "First Name: " << classRosterArray[i]->getStudentFirstName(); cout << '\t';
		cout << "Last Name: " << classRosterArray[i]->getStudentLastName(); cout << '\t';
		cout << "Email: " << classRosterArray[i]->getStudentEmail(); cout << '\t';
		cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
		cout << "Days in course: (" << classRosterArray[i]->getDaysInClass()[0];
		cout << ", " << classRosterArray[i]->getDaysInClass()[1];
		cout << ", " << classRosterArray[i]->getDaysInClass()[2]; cout << ") ";
		cout << "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sem = (classRosterArray[i]->getStudentEmail());
		if (sem.find('@') == string::npos || (sem.find('.') == string::npos) || (sem.find(' ') != string::npos))
		{
			any = true;
			cout << sem << ": " << classRosterArray[i]->getStudentFirstName() << endl;
		}
	}
	if (!any) cout << "NONE" << endl;
}

void Roster::printAverageDaysInClass(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << "Student ID " << studentID << " averages ";
			cout << (classRosterArray[i]->getDaysInClass()[0] + classRosterArray[i]->getDaysInClass()[1] + classRosterArray[i]->getDaysInClass()[2]) / 3 << " days in courses." << endl;
		}
	}
	cout << endl;
}

void Roster::removeStudentByID(string studentID)
{
	bool studentexists = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			studentexists = true;
			if (i < studentDataInfo - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[studentDataInfo - 1];
				classRosterArray[studentDataInfo - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (studentexists)
	{
		cout << studentID << " removed from class roster." << endl << endl;
		this->printAll();
	}
	else cout << studentID << " not found." << endl << endl;
}

Roster::~Roster()
{
	cout << "Destructor is called!" << endl << endl;
	for (int i = 0; i < studentDataInfo; i++)
	{
		cout << "Destroying student record." << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};