#pragma once


#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsSchoolStudentKindergarten.h"
#include "clsSchoolStudentElementary.h"
#include "clsSchoolStudentJuniorHigh.h"
#include "clsSchoolStudentHigh.h"



class clsUpdateStudentScreen : protected clsScreen
{
private:

	static void _ReadStudentInfo(clsSchoolStudentKindergarten& Student)
	{


		cout << "\nEnter FirstName: ";
		Student.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Student.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Age: ";
		Student.Age = clsInputValidate::ReadShortNumber();

		cout << "\nEnter Email: ";
		Student.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Student.Phone = clsInputValidate::ReadString();

		

		cout << "\nEnter Account Balance: ";
		Student.AccountBalance = clsInputValidate::ReadFloatNumber();

		cout << "\nEnter Mark : ";
		Student.Marks = clsInputValidate::ReadShortNumber();

		if (Student.Marks >= 50)
			Student.Tagstatus = "Successfully";
		else
			Student.Tagstatus = "Failed";

	}

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

	static void _ReadStudentInfo(clsSchoolStudentElementary& Student)
	{


		cout << "\nEnter FirstName: ";
		Student.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Student.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Age: ";
		Student.Age = clsInputValidate::ReadShortNumber();

		cout << "\nEnter Email: ";
		Student.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Student.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Student.AccountBalance = clsInputValidate::ReadFloatNumber();

		cout << "\nEnter Mark : ";
		Student.Marks = clsInputValidate::ReadShortNumber();

		if (Student.Marks >= 50)
			Student.Tagstatus = "Successfully";
		else
			Student.Tagstatus = "Failed";

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

	static void _ReadStudentInfo(clsSchoolStudentJuniorHigh& Student)
	{


		cout << "\nEnter FirstName: ";
		Student.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Student.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Age: ";
		Student.Age = clsInputValidate::ReadShortNumber();

		cout << "\nEnter Email: ";
		Student.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Student.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Student.AccountBalance = clsInputValidate::ReadFloatNumber();

		cout << "\nEnter Mark : ";
		Student.Marks = clsInputValidate::ReadShortNumber();

		if (Student.Marks >= 50)
			Student.Tagstatus = "Successfully";
		else
			Student.Tagstatus = "Failed";

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

	static void _ReadStudentInfo(clsSchoolStudentHigh& Student)
	{


		cout << "\nEnter FirstName: ";
		Student.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Student.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Age: ";
		Student.Age = clsInputValidate::ReadShortNumber();

		cout << "\nEnter Email: ";
		Student.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Student.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Student.AccountBalance = clsInputValidate::ReadFloatNumber();

		cout << "\nEnter Mark : ";
		Student.Marks = clsInputValidate::ReadShortNumber();

		if (Student.Marks >= 50)
			Student.Tagstatus = "Successfully";
		else
			Student.Tagstatus = "Failed";

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

	static void ShowUpdateStudentKindergartenScreen()
	{
		string AccountStudent = "";
		cout << "Please enter the Account Student : ";
		AccountStudent = clsInputValidate::ReadString();


		while (!clsSchoolStudentKindergarten::IsStudentExist(AccountStudent))
		{
			cout << "this student is not found , please enter another one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentKindergarten Student1 = clsSchoolStudentKindergarten::Find(AccountStudent);
		_PrintStudntRecordLine(Student1);

		cout << "\n\n Update Student ";
		cout << "\n___________________\n";

		_ReadStudentInfo(Student1);

		clsSchoolStudentKindergarten::enSaveResults SaveResults;
		SaveResults = Student1.Save();

		switch (SaveResults)
		{
		case clsSchoolStudentKindergarten::enSaveResults::svSucceeded:
		{
			cout << "\Student Updated Successfully :-)\n";
			_PrintStudntRecordLine(Student1);
			break;
		}
		case clsSchoolStudentKindergarten::enSaveResults::svFalidEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		}
	}

	static void ShowUpdateStudentElementaryScreen()
	{
		string AccountStudent = "";
		cout << "Please enter the Account Student : ";
		AccountStudent = clsInputValidate::ReadString();


		while (!clsSchoolStudentElementary::IsStudentExist(AccountStudent))
		{
			cout << "this student is not found , please enter another one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentElementary Student1 = clsSchoolStudentElementary::Find(AccountStudent);
		_PrintStudntRecordLine(Student1);

		cout << "\n\n Update Student ";
		cout << "\n___________________\n";

		_ReadStudentInfo(Student1);

		clsSchoolStudentElementary::enSaveResults SaveResults;
		SaveResults = Student1.Save();

		switch (SaveResults)
		{
		case clsSchoolStudentElementary::enSaveResults::svSucceeded:
		{
			cout << "\Student Updated Successfully :-)\n";
			_PrintStudntRecordLine(Student1);
			break;
		}
		case clsSchoolStudentElementary::enSaveResults::svFalidEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		}
	}

	static void ShowUpdateStudentJuniorHighScreen()
	{
		string AccountStudent = "";
		cout << "Please enter the Account Student : ";
		AccountStudent = clsInputValidate::ReadString();


		while (!clsSchoolStudentJuniorHigh::IsStudentExist(AccountStudent))
		{
			cout << "this student is not found , please enter another one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentJuniorHigh Student1 = clsSchoolStudentJuniorHigh::Find(AccountStudent);
		_PrintStudntRecordLine(Student1);

		cout << "\n\n Update Student ";
		cout << "\n___________________\n";

		_ReadStudentInfo(Student1);

		clsSchoolStudentJuniorHigh::enSaveResults SaveResults;
		SaveResults = Student1.Save();

		switch (SaveResults)
		{
		case clsSchoolStudentJuniorHigh::enSaveResults::svSucceeded:
		{
			cout << "\Student Updated Successfully :-)\n";
			_PrintStudntRecordLine(Student1);
			break;
		}
		case clsSchoolStudentJuniorHigh::enSaveResults::svFalidEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		}
	}

	static void ShowUpdateStudentHighScreen()
	{
		string AccountStudent = "";
		cout << "Please enter the Account Student : ";
		AccountStudent = clsInputValidate::ReadString();


		while (!clsSchoolStudentHigh::IsStudentExist(AccountStudent))
		{
			cout << "this student is not found , please enter another one : ";
			AccountStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentHigh Student1 = clsSchoolStudentHigh::Find(AccountStudent);
		_PrintStudntRecordLine(Student1);

		cout << "\n\n Update Student ";
		cout << "\n___________________\n";

		_ReadStudentInfo(Student1);

		clsSchoolStudentHigh::enSaveResults SaveResults;
		SaveResults = Student1.Save();

		switch (SaveResults)
		{
		case clsSchoolStudentHigh::enSaveResults::svSucceeded:
		{
			cout << "\Student Updated Successfully :-)\n";
			_PrintStudntRecordLine(Student1);
			break;
		}
		case clsSchoolStudentHigh::enSaveResults::svFalidEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		}
	}





};

