
#include "student.h"
#include "degree.h"

Student::Student()
{
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmail = "";
	this->age = 0;
	for (int i = 0; i < daysInClassArraySize; i++) this->daysInClass[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, int age, int daysInClass[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmail = studentEmail;
	this->age = age;
	for (int i = 0; i < daysInClassArraySize; i++) this->daysInClass[i] = daysInClass[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student(){} //destructor

	//accessors

	string Student::getStudentID() { return this->studentID; } /*returns student id*/
	string Student::getStudentFirstName() { return this->studentFirstName; } /*returns first name*/
	string Student::getStudentLastName() { return this->studentLastName; }/*returns last name*/
	string Student::getStudentEmail() { return this->studentEmail; } /*returns email address*/
	int Student::getAge() { return this->age; }/*returns age*/
	int* Student::getDaysInClass() { return this->daysInClass; }/*returns the pointer to the array of days spent in each course*/
	DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }/*this returns the degree program*/

		//mutators
	void Student::setStudentID(string studentID) {this->studentID = studentID; }
	void Student::setStudentFirstName(string studentFirstName) { this->studentFirstName = studentFirstName; }
	void Student::setStudentLastName(string studentLastName) { this->studentLastName = studentLastName; }
	void Student::setStudentEmail(string studentEmail) { this->studentEmail = studentEmail; }
	void Student::setAge(int age) { this->age = age; }
	void Student::setDaysInClass(int daysInClass[])
	{
		for (int i = 0; i < daysInClassArraySize; i++) this->daysInClass[i] = daysInClass[i];
	}
	void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

	void Student::print()
	{
		cout << this->getStudentID() << '\t';
		cout << "First Name: " << this->getStudentFirstName() << '\t';
		cout << "Last Name: " << this->getStudentLastName() << '\t';
		cout << "Email: " << this->getStudentEmail() << '\t';
		cout << "Age: " << this->getAge() << '\t';
		cout << "Days in course: {" << this->getDaysInClass()[0];
		cout << ", " << this->getDaysInClass()[1];
		cout << ", " << this->getDaysInClass()[2] << "} ";
		cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n';
	};