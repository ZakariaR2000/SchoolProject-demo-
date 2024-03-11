#pragma once

#include "clsScreen.h"
#include <iomanip>

#include "clsSchoolStudentKindergarten.h"
#include "clsSchoolStudentElementary.h"
#include "clsSchoolStudentJuniorHigh.h"
#include "clsSchoolStudentHigh.h"

class clsListStudentScreen : protected clsScreen
{
private:

	static void _PrintStudntRecordLine(clsSchoolStudentKindergarten Student)
	{
		cout << "| " << left << setw(10) << Student.AccountNumberOfStudent();
		cout << "| " << left << setw(16) << Student.FullName();
		cout << "| " << left << setw(4) << Student.Age;
		cout << "| " << left << setw(16) << Student.Email;
		cout << "| " << left << setw(11) << Student.Phone;
		cout << "| " << left << setw(8) << Student.AccountBalance;
		cout << "| " << left << setw(5) << Student.Marks;
		cout << "| " << left << setw(10) << Student.Tagstatus;

	}

	static void _PrintStudntRecordLine(clsSchoolStudentElementary Student)
	{
		cout << "| " << left << setw(10) << Student.AccountNumberOfStudent();
		cout << "| " << left << setw(16) << Student.FullName();
		cout << "| " << left << setw(4) << Student.Age;
		cout << "| " << left << setw(16) << Student.Email;
		cout << "| " << left << setw(11) << Student.Phone;
		cout << "| " << left << setw(8) << Student.AccountBalance;
		cout << "| " << left << setw(5) << Student.Marks;
		cout << "| " << left << setw(10) << Student.Tagstatus;

	}

	static void _PrintStudntRecordLine(clsSchoolStudentJuniorHigh Student)
	{
		cout << "| " << left << setw(10) << Student.AccountNumberOfStudent();
		cout << "| " << left << setw(16) << Student.FullName();
		cout << "| " << left << setw(4) << Student.Age;
		cout << "| " << left << setw(16) << Student.Email;
		cout << "| " << left << setw(11) << Student.Phone;
		cout << "| " << left << setw(8) << Student.AccountBalance;
		cout << "| " << left << setw(5) << Student.Marks;
		cout << "| " << left << setw(10) << Student.Tagstatus;

	}

	static void _PrintStudntRecordLine(clsSchoolStudentHigh Student)
	{
		cout << "| " << left << setw(10) << Student.AccountNumberOfStudent();
		cout << "| " << left << setw(16) << Student.FullName();
		cout << "| " << left << setw(4) << Student.Age;
		cout << "| " << left << setw(16) << Student.Email;
		cout << "| " << left << setw(11) << Student.Phone;
		cout << "| " << left << setw(8) << Student.AccountBalance;
		cout << "| " << left << setw(5) << Student.Marks;
		cout << "| " << left << setw(10) << Student.Tagstatus;

	}




public:

	static void ShowStudentListKindergartenScreen()
	{
		_DrawScreenHeader("\tStudents List Screen");

		vector <clsSchoolStudentKindergarten> vStudents = clsSchoolStudentKindergarten::GetStudentList();


		cout << "\n\t\t\t\t\tClient List (" << vStudents.size() << ") Client(s)";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;


		cout << "| " << left << setw(10) << "Ac.Student";
		cout << "| " << left << setw(16) << "Student Name";
		cout << "| " << left << setw(4) << "Age";
		cout << "| " << left << setw(16) << "Email";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(8) << "Balance";
		cout << "| " << left << setw(5) << "Marks";
		cout << "| " << left << setw(10) << "Tagstatus";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;

		if (vStudents.size() == 0)
			cout << "No Student Available In the system!";
		else
			for (clsSchoolStudentKindergarten& S : vStudents)
			{
				_PrintStudntRecordLine(S);
				cout << endl;
			}


	}

	static void ShowStudentListElementaryScreen()
	{
		_DrawScreenHeader("\tStudents List Screen");

		vector <clsSchoolStudentElementary> vStudents = clsSchoolStudentElementary::GetStudentList();


		cout << "\n\t\t\t\t\tClient List (" << vStudents.size() << ") Client(s)";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;


		cout << "| " << left << setw(10) << "Ac.Student";
		cout << "| " << left << setw(16) << "Student Name";
		cout << "| " << left << setw(4) << "Age";
		cout << "| " << left << setw(16) << "Email";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(8) << "Balance";
		cout << "| " << left << setw(5) << "Marks";
		cout << "| " << left << setw(10) << "Tagstatus";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;

		if (vStudents.size() == 0)
			cout << "No Student Available In the system!";
		else
			for (clsSchoolStudentElementary& S : vStudents)
			{
				_PrintStudntRecordLine(S);
				cout << endl;
			}


	}

	static void ShowStudentListJuniorHighScreen()
	{
		_DrawScreenHeader("\tStudents List Screen");

		vector <clsSchoolStudentJuniorHigh> vStudents = clsSchoolStudentJuniorHigh::GetStudentList();


		cout << "\n\t\t\t\t\tClient List (" << vStudents.size() << ") Client(s)";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;


		cout << "| " << left << setw(10) << "Ac.Student";
		cout << "| " << left << setw(16) << "Student Name";
		cout << "| " << left << setw(4) << "Age";
		cout << "| " << left << setw(16) << "Email";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(8) << "Balance";
		cout << "| " << left << setw(5) << "Marks";
		cout << "| " << left << setw(10) << "Tagstatus";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;

		if (vStudents.size() == 0)
			cout << "No Student Available In the system!";
		else
			for (clsSchoolStudentJuniorHigh& S : vStudents)
			{
				_PrintStudntRecordLine(S);
				cout << endl;
			}


	}

	static void ShowStudentListHighScreen()
	{
		_DrawScreenHeader("\tStudents List Screen");

		vector <clsSchoolStudentHigh> vStudents = clsSchoolStudentHigh::GetStudentList();


		cout << "\n\t\t\t\t\tClient List (" << vStudents.size() << ") Client(s)";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;


		cout << "| " << left << setw(10) << "Ac.Student";
		cout << "| " << left << setw(16) << "Student Name";
		cout << "| " << left << setw(4) << "Age";
		cout << "| " << left << setw(16) << "Email";
		cout << "| " << left << setw(11) << "Phone";
		cout << "| " << left << setw(8) << "Balance";
		cout << "| " << left << setw(5) << "Marks";
		cout << "| " << left << setw(10) << "Tagstatus";

		cout << "\n_____________________________________________________________";
		cout << "____________________________________________________\n" << endl;

		if (vStudents.size() == 0)
			cout << "No Student Available In the system!";
		else
			for (clsSchoolStudentHigh& S : vStudents)
			{
				_PrintStudntRecordLine(S);
				cout << endl;
			}


	}





};

