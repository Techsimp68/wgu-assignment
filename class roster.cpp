#include <string>
#include "class roster.h"
#include "student.h"
#include "degree.h"

const string studentData[] =
{

"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,David,Simpson,usmcengineer@live.com,29,25,45,10,SOFTWARE"
};


void Roster::parse(string studentdata)
{

	//locates the studentID
	long long int rhs = studentdata.find(",");//Looks for the comma
	string sID = studentdata.substr(0, rhs);

	//locates the First Name
	long long int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string fn = studentdata.substr(lhs, rhs - lhs);

	//locates the Last Name
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string ln = studentdata.substr(lhs, rhs - lhs);

	//locates the Email Address
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string eaddress = studentdata.substr(lhs, rhs - lhs);

	//got to make sure they graduated high school so this finds the Student Age
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs));//converted string to int

	//Average in First Course
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int adic1 = stoi(studentdata.substr(lhs, rhs - lhs));

	//Average in Second Course
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int adic2 = stoi(studentdata.substr(lhs, rhs - lhs));

	//Average in Third Course
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int adic3 = stoi(studentdata.substr(lhs, rhs - lhs));

	//this is the amazing Degree Program
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string degree = studentdata.substr(lhs, rhs - lhs);

	DegreeProgram dp = DegreeProgram::SECURITY;

	
	if (degree == "NETWORK") {

		dp = NETWORK;

	}

	if (degree == "SOFTWARE") {

		dp = SOFTWARE;

	}


	add(sID, fn, ln, eaddress, age, adic1, adic2, adic3, dp);

	string studentId[] = { sID };
	string studentFirstNames[] = { fn };
	string studentLastName[] = { ln };
	string studentEmail[] = { eaddress };
	int studentAge[] = { age };
	int dayOne[] = { adic1 };
	int dayTwo[] = { adic2 };
	int dayThree[] = { adic3 };
	string studentDegree[] = { degree };
}
			
void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sCompDays1, int sCompDays2, int sCompDays3, DegreeProgram dp)

{

	int CompsDaysArray[3] = { sCompDays1, sCompDays2, sCompDays3 };

	classRosterArray[++lastIndex] = new Student(sID, sFirstName, sLastName, sEmail, sAge, CompsDaysArray, dp);// Full Constructor

}
		//This kicks the student out of school! or removes the student ID at least
void Roster::removeID(string sID)

{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == sID)
		{
			any = true;

			if (i < numberofStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numberofStudents - 1];
				classRosterArray[numberofStudents - 1] = temp;
			}

			Roster::lastIndex--;
		}
	}
	if (any)
	{
		cout << sID << " has been removed from roster." << std::endl;
	}
	else cout << sID << " could not be found." << std::endl;

}
		//prints all the school kids
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)classRosterArray[i]->print();
	{
		/*cout << classRosterArray[i]->getID(); cout << '\t';*/
		//if (classRosterArray[i]->getFirstName().size() > 6)classRosterArray[i]->print();
		/*{
			string studentFirstName = classRosterArray[i]->getFirstName();
			cout << classRosterArray[i]->getFirstName(); cout << '\t';
		}
		else
		{
			cout << classRosterArray[i]->getFirstName(); cout << '\t' << '\t';

		}*/
		//if (classRosterArray[i]->getLastName().size() > 6)classRosterArray[i]->print();
		/*{
			cout << classRosterArray[i]->getLastName(); cout << '\t';
		}
		else
		{
			cout << classRosterArray[i]->getLastName(); cout << '\t' << '\t';

		}*/
		//if (classRosterArray[i]->getEmailAddress().size() > 16)classRosterArray[i]->print();
		/*{
			cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		}
		else
		{
			cout << classRosterArray[i]->getEmailAddress(); cout << '\t' << '\t';

		}
		cout << classRosterArray[i]->getAgeofStudent(); cout << '\t';
		cout << classRosterArray[i]->getDaystoComp()[0]; cout << ',';
		cout << classRosterArray[i]->getDaystoComp()[1]; cout << ',';
		cout << classRosterArray[i]->getDaystoComp()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()]; cout << std::endl;*/

	}

}

		//averages how long they are taking to complete school
void Roster::printAverageDaysInCourse(string sID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)


		if (classRosterArray[i]->getID() == sID) {

			cout << classRosterArray[i]->getID() << ": ";
			cout << classRosterArray[i]->getDaystoComp()[0]
				+ classRosterArray[i]->getDaystoComp()[1]
				+ classRosterArray[i]->getDaystoComp()[2] / 3.0 << std::endl;
		}

	cout << std::endl;

}
		//finds the people that don't know their emails
void Roster::printInvalidEmail()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sEmail = classRosterArray[i]->getEmailAddress();

		if ((sEmail.find("@") != string::npos) && (sEmail.find('.') != string::npos)) {

			if (sEmail.find(' ') != string::npos) {

				cout << sEmail;
				cout << std::endl;

			}
		}
		else {

			cout << sEmail;
			cout << std::endl;
		}
	}
}		//so we can print them by the degree program they are taking
void Roster::printByDegreeProgram(DegreeProgram dp)
{

	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{

		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}

	cout << std::endl;

}

Roster::~Roster()				//all hail this destructor as well
{
	cout << "DESTRUCTOR cleaning up..." << std::endl << std::endl;
	for (int i = 0; i < numberofStudents; i++)
	{
		cout << "removing the students from class #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;

	}
}


