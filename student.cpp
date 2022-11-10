#pragma once
#include "student.h"
#include "degree.h"
#include <iostream>
#include"class roster.h"
#include <string>
using namespace std;


Student::Student() //is the Constructor half full or half empty (the constructor is empty)

{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->ageofStudent = 0;
	for (int i = 0; i < daystoComplete; i++)  this->daystoComp[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int ageofStudent, int daystoComp[], DegreeProgram degreeProgram)



{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->ageofStudent = ageofStudent;
	for (int i = 0; i < daystoComplete; i++) this->daystoComp[i] = daystoComp[i];
	this->degreeProgram = degreeProgram;
}



Student::~Student() {}//all Hail this Deconstructor

//the amazing getters with out them we would have no data
string Student::getID()
{
	return this->studentID;

}


string Student::getFirstName()
{
	return this->firstName;

}

string Student::getLastName()
{
	return this->lastName;

}

string Student::getEmailAddress()
{

	return this->emailAddress;
}


int Student::getAgeofStudent()
{

	return this->ageofStudent;

}

int* Student::getDaystoComp()
{

	return this->daystoComp;

}

DegreeProgram Student::getDegreeProgram()
{

	return this->degreeProgram;

}


//the setters are good too.. they set the data

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

void Student::setAgeofStudent(int ageofStudent)
{
	this->ageofStudent = ageofStudent;

}

void Student::setDaystoComp(int daystoComp[])
{
	this->daystoComp[0] = daystoComp[0];
	this->daystoComp[1] = daystoComp[1];
	this->daystoComp[2] = daystoComp[2];
}

void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }


void Student::printHeader()

{
	cout << "Student ID|First Name|	Last Name||	Email Address|Age|Days to Complete Course|Degree Program\n";

}


void Student::print()

{
	for (int i = 0; i <= 0; i++)
	{
		cout << Student::getID(); cout << '\t';
		
			
			cout << Student::getFirstName(); cout << '\t';
			cout << Student::getLastName(); cout << '\t';
			cout << Student::getEmailAddress(); cout << '\t';
			cout << Student::getAgeofStudent(); cout << '\t';
			cout << Student::getDaystoComp()[0]; cout << ',';
			cout << Student::getDaystoComp()[1]; cout << ',';
			cout << Student::getDaystoComp()[2]; cout << '\t';
			cout << degreeProgramStrings[Student::getDegreeProgram()]; cout << std::endl;
		
		
	}
}