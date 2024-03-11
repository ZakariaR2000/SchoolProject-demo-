#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsSchoolStudentKindergarten.h"
#include "clsSchoolStudentElementary.h"
#include "clsSchoolStudentJuniorHigh.h"
#include "clsSchoolStudentHigh.h"


class clsFindStudentScreen : protected clsScreen
{
private:

	static void _PrintStudntRecordLine(clsSchoolStudentKindergarten Student)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name    : " << Student.FullName();
		cout << "\nAge          : " << Student.Age;
		cout << "\nEmail        : " << Student.Email;
		cout << "\nPhone        : " << Student.Phone;
		cout << "\nClassroom    : " << Student.Classroom();
		cout << "\nAccNumOfStud : " << Student.AccountNumberOfStudent();
		cout << "\nBalance      : " << Student.AccountBalance;
		cout << "\nTagstatus    : " << Student.Tagstatus;
		cout << "\n___________________\n";

	}

	static void _PrintStudntRecordLine(clsSchoolStudentElementary Student)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name    : " << Student.FullName();
		cout << "\nAge          : " << Student.Age;
		cout << "\nEmail        : " << Student.Email;
		cout << "\nPhone        : " << Student.Phone;
		cout << "\nClassroom    : " << Student.Classroom();
		cout << "\nAccNumOfStud : " << Student.AccountNumberOfStudent();
		cout << "\nBalance      : " << Student.AccountBalance;
		cout << "\nTagstatus    : " << Student.Tagstatus;
		cout << "\n___________________\n";

	}

	static void _PrintStudntRecordLine(clsSchoolStudentJuniorHigh Student)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name    : " << Student.FullName();
		cout << "\nAge          : " << Student.Age;
		cout << "\nEmail        : " << Student.Email;
		cout << "\nPhone        : " << Student.Phone;
		cout << "\nClassroom    : " << Student.Classroom();
		cout << "\nAccNumOfStud : " << Student.AccountNumberOfStudent();
		cout << "\nBalance      : " << Student.AccountBalance;
		cout << "\nTagstatus    : " << Student.Tagstatus;
		cout << "\n___________________\n";

	}

	static void _PrintStudntRecordLine(clsSchoolStudentHigh Student)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name    : " << Student.FullName();
		cout << "\nAge          : " << Student.Age;
		cout << "\nEmail        : " << Student.Email;
		cout << "\nPhone        : " << Student.Phone;
		cout << "\nClassroom    : " << Student.Classroom();
		cout << "\nAccNumOfStud : " << Student.AccountNumberOfStudent();
		cout << "\nBalance      : " << Student.AccountBalance;
		cout << "\nTagstatus    : " << Student.Tagstatus;
		cout << "\n___________________\n";

	}




public:

	static void ShowFindStudentKindergartenScreen()
	{
		_DrawScreenHeader("Find Student Screen");

		cout << "Please enter Account Of Student  :  ";

		string AccountOfStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentKindergarten::IsStudentExist(AccountOfStudent))
		{
			cout << "Please enter again : ";
			string AccountOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentKindergarten Student = clsSchoolStudentKindergarten::Find(AccountOfStudent);

		if (!Student.IsEmpty())
		{
			cout << "Student Found";
		}
		else
		{
			cout << "Student was not Found";
		}

		_PrintStudntRecordLine(Student);

		
	}

	static void ShowFindStudentElementaryScreen()
	{
		_DrawScreenHeader("Find Student Screen");

		cout << "Please enter Account Of Student  :  ";

		string AccountOfStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentElementary::IsStudentExist(AccountOfStudent))
		{
			cout << "Please enter again : ";
			string AccountOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentElementary Student = clsSchoolStudentElementary::Find(AccountOfStudent);

		if (!Student.IsEmpty())
		{
			cout << "Student Found";
		}
		else
		{
			cout << "Student was not Found";
		}

		_PrintStudntRecordLine(Student);


	}

	static void ShowFindStudentJuniorHighScreen()
	{
		_DrawScreenHeader("Find Student Screen");

		cout << "Please enter Account Of Student  :  ";

		string AccountOfStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentJuniorHigh::IsStudentExist(AccountOfStudent))
		{
			cout << "Please enter again : ";
			string AccountOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentJuniorHigh Student = clsSchoolStudentJuniorHigh::Find(AccountOfStudent);

		if (!Student.IsEmpty())
		{
			cout << "Student Found";
		}
		else
		{
			cout << "Student was not Found";
		}

		_PrintStudntRecordLine(Student);


	}

	static void ShowFindStudentHighScreen()
	{
		_DrawScreenHeader("Find Student Screen");

		cout << "Please enter Account Of Student  :  ";

		string AccountOfStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentHigh::IsStudentExist(AccountOfStudent))
		{
			cout << "Please enter again : ";
			string AccountOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentHigh Student = clsSchoolStudentHigh::Find(AccountOfStudent);

		if (!Student.IsEmpty())
		{
			cout << "Student Found";
		}
		else
		{
			cout << "Student was not Found";
		}

		_PrintStudntRecordLine(Student);


	}



};

