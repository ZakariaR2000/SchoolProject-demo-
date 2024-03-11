#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsSchoolStudentKindergarten.h"
#include "clsSchoolStudentElementary.h"
#include "clsSchoolStudentJuniorHigh.h"
#include "clsSchoolStudentHigh.h"

class clsDeleteStudentScreen : protected clsScreen
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


	static void ShowDeleteStudentKindergartenScreen()
	{
		_DrawScreenHeader("Delete Student Screen");



		string AccountStudent = "";
		cout << "Please enter Account Number Of Student : ";

		AccountStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentKindergarten::IsStudentExist(AccountStudent))
		{
			cout << "This student is not in the School , Pleas enter anothe one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentKindergarten Student = clsSchoolStudentKindergarten::Find(AccountStudent);
		_PrintStudntRecordLine(Student);

		char Answer = 'n';
		cout << "Do you sure you wont to delete this student Y/N ??";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Student.Delete())
			{
				Student.GetEmptyClassroom();
				cout << "Delete Successfully";
				_PrintStudntRecordLine(Student);
			}
			else
			{
				cout << "\nError Student Was not Deleted\n";
			}
		}


	}

	static void ShowDeleteStudentElementaryScreen()
	{
		_DrawScreenHeader("Delete Student Screen");



		string AccountStudent = "";
		cout << "Please enter Account Number Of Student : ";

		AccountStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentElementary::IsStudentExist(AccountStudent))
		{
			cout << "This student is not in the School , Pleas enter anothe one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentElementary Student = clsSchoolStudentElementary::Find(AccountStudent);
		_PrintStudntRecordLine(Student);

		char Answer = 'n';
		cout << "Do you sure you wont to delete this student Y/N ??";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Student.Delete())
			{
				Student.GetEmptyClassroom();
				cout << "Delete Successfully";
				_PrintStudntRecordLine(Student);
			}
			else
			{
				cout << "\nError Student Was not Deleted\n";
			}
		}


	}

	static void ShowDeleteStudentJuniorHighScreen()
	{
		_DrawScreenHeader("Delete Student Screen");



		string AccountStudent = "";
		cout << "Please enter Account Number Of Student : ";

		AccountStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentJuniorHigh::IsStudentExist(AccountStudent))
		{
			cout << "This student is not in the School , Pleas enter anothe one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentJuniorHigh Student = clsSchoolStudentJuniorHigh::Find(AccountStudent);
		_PrintStudntRecordLine(Student);

		char Answer = 'n';
		cout << "Do you sure you wont to delete this student Y/N ??";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Student.Delete())
			{
				Student.GetEmptyClassroom();
				cout << "Delete Successfully";
				_PrintStudntRecordLine(Student);
			}
			else
			{
				cout << "\nError Student Was not Deleted\n";
			}
		}


	}

	static void ShowDeleteStudentHighScreen()
	{
		_DrawScreenHeader("Delete Student Screen");



		string AccountStudent = "";
		cout << "Please enter Account Number Of Student : ";

		AccountStudent = clsInputValidate::ReadString();

		while (!clsSchoolStudentHigh::IsStudentExist(AccountStudent))
		{
			cout << "This student is not in the School , Pleas enter anothe one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentHigh Student = clsSchoolStudentHigh::Find(AccountStudent);
		_PrintStudntRecordLine(Student);

		char Answer = 'n';
		cout << "Do you sure you wont to delete this student Y/N ??";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Student.Delete())
			{
				Student.GetEmptyClassroom();
				cout << "Delete Successfully";
				_PrintStudntRecordLine(Student);
			}
			else
			{
				cout << "\nError Student Was not Deleted\n";
			}
		}


	}




};

