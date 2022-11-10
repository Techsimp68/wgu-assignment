#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using namespace std;
using std::endl;

class Student
{


public:
    const static int daystoComplete = 3;

private:
	
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int ageofStudent;
	int daystoComp[daystoComplete];
	DegreeProgram degreeProgram;

public:

	Student();//The Constructor
		Student (string studentID, string firstName, string lastName, string emailAddress, int ageofStudent, int daystoComp[], DegreeProgram degreeProgram);//Full Constructor
		~Student();// all hail the Destructor

        //creation of the getters
        string getID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAgeofStudent();
        int* getDaystoComp();
        DegreeProgram getDegreeProgram();

        //creation of the setters
        void setID(string ID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAgeofStudent(int ageofStudent);
        void setDaystoComp(int daystoComp[]);
        void setDegreeProgram(DegreeProgram dp);
        
        static void printHeader();

        void print(); //will display student's data

};