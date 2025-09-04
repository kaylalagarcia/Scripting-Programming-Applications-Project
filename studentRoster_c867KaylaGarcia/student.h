
#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student
{
public:
	const static int daysInClassArraySize = 3;

private:
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	int age;
	int daysInClass[daysInClassArraySize];
	DegreeProgram degreeProgram;

public:
	Student(); //parameterless constructor
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int age, int daysInClass[], DegreeProgram degreeProgram);
	~Student(); //destructor

	/*getters aka accessor*/
	string getStudentID();
	string getStudentFirstName();
	string getStudentLastName();
	string getStudentEmail();
	int getAge();
	int* getDaysInClass();
	DegreeProgram getDegreeProgram();

	/*setters aka mutators*/
	void setStudentID(string studentID);
	void setStudentFirstName(string studentFirstName);
	void setStudentLastName(string studentLastName);
	void setStudentEmail(string studentEmail);
	void setAge(int age);
	void setDaysInClass(int daysInClass[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	void print();/*displays student's data*/
};