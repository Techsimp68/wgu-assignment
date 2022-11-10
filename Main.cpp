#include <iostream>
#include "degree.h"
#include <vector>
#include "class roster.h"
#include <string>
#include <algorithm>



using namespace std;

int main()

{

	const string studentData[] =
	{

	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,David,Simpson,usmcengineer@live.com,29,25,45,10,SOFTWARE"
	};


	cout << "Scripting and Programming JYM1" << std::endl;
	cout << "Using C++" << std::endl;
	cout << "Student ID: 001259983" << std::endl;
	cout << "David Levi Simpson" << std::endl;
	cout << std::endl;

	const int numberofStudents = 5;


	Roster classRoster;
	//displays all students
	for (int i = 0; i < numberofStudents; i++)
		classRoster.parse(studentData[i]);
	cout << "Displaying all Students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	//Displays all students by degree program
	for (int i = 0; i < 4; i++)
	{
		cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);//*Cast to a Degree Program
	}


	//display students with invalid email
	cout << "Displaying students with invalid emails: " << std::endl;
	classRoster.printInvalidEmail();
	cout << std::endl;


	//displays average days in a course
	cout << "Displaying average days in course: " << std::endl;
	for (int i = 0; i < numberofStudents; i++)
	{

		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
	}

	//removes by ID;
	
	string userDegree;
	cout << "What Student needs to be removed?(use student ID) : " << std::endl;
	cin >> userDegree;
	std::for_each(userDegree.begin(), userDegree.end(), [](char & u) {
		u = ::toupper(u);
		});
	
	classRoster.removeID(userDegree);
	cout << std::endl;

	
	classRoster.printAll();//NEED TO PRINT IN ORDER
	cout << std::endl;

	cout << "Removing student with ID " << userDegree <<" please wait" << std::endl;
	classRoster.removeID(userDegree );
	cout << std::endl;


	system("pause");
	return 0;
}