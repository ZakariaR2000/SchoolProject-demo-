#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsSchoolStudentKindergarten.h"
#include "clsSchoolStudentElementary.h"
#include "clsSchoolStudentJuniorHigh.h"
#include "clsSchoolStudentHigh.h"

class clsAddNewStudentScreen : protected clsScreen
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




public:

	static void ShowAddNewStudentKindergartenScreen()
	{
		string AccountNumberOfStudent = "";
		cout << "Please enter Account Number Of New Student : ";
		AccountNumberOfStudent = clsInputValidate::ReadString();

		while (clsSchoolStudentKindergarten::IsStudentExist(AccountNumberOfStudent))
		{
			cout << "This Student is alread exists in School , Please enter another one : ";
			AccountNumberOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentKindergarten NewStudent = clsSchoolStudentKindergarten::CreateNewStudentObject(AccountNumberOfStudent);

		cout << "\n Add New Student Screen";
		cout << "\n___________________________\n";

		_ReadStudentInfo(NewStudent);

		clsSchoolStudentKindergarten::enSaveResults SaveResult;

		SaveResult = NewStudent.Save();

		switch (SaveResult)
		{
		case clsSchoolStudent::enSaveResults::svSucceeded:
		{
			cout << "Add New Student is Succeeded .";
			NewStudent.Print();
			break;
		}

		case clsSchoolStudent::enSaveResults::svFalidEmptyObject:
		{
			cout << "Opss , Thes object of Student is Empty .";
			break;
		}

		case clsSchoolStudent::enSaveResults::svFaildStudentNumberIsExist:
		{
			cout << "this account student is alread exits in School";
		}
		}
	}

	static void ShowAddNewStudentElementaryScreen()
	{
		string AccountNumberOfStudent = "";
		cout << "Please enter Account Number Of New Student : ";
		AccountNumberOfStudent = clsInputValidate::ReadString();

		while (clsSchoolStudentElementary::IsStudentExist(AccountNumberOfStudent))
		{
			cout << "This Student is alread exists in School , Please enter another one : ";
			AccountNumberOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentElementary NewStudent = clsSchoolStudentElementary::CreateNewStudentObject(AccountNumberOfStudent);

		cout << "\n Add New Student Screen";
		cout << "\n___________________________\n";

		_ReadStudentInfo(NewStudent);

		clsSchoolStudentElementary::enSaveResults SaveResult;

		SaveResult = NewStudent.Save();

		switch (SaveResult)
		{
		case clsSchoolStudent::enSaveResults::svSucceeded:
		{
			cout << "Add New Student is Succeeded .";
			NewStudent.Print();
			break;
		}

		case clsSchoolStudent::enSaveResults::svFalidEmptyObject:
		{
			cout << "Opss , Thes object of Student is Empty .";
			break;
		}

		case clsSchoolStudent::enSaveResults::svFaildStudentNumberIsExist:
		{
			cout << "this account student is alread exits in School";
		}
		}
	}

	static void ShowAddNewStudentJuniorHighScreen()
	{
		string AccountNumberOfStudent = "";
		cout << "Please enter Account Number Of New Student : ";
		AccountNumberOfStudent = clsInputValidate::ReadString();

		while (clsSchoolStudentJuniorHigh::IsStudentExist(AccountNumberOfStudent))
		{
			cout << "This Student is alread exists in School , Please enter another one : ";
			AccountNumberOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentJuniorHigh NewStudent = clsSchoolStudentJuniorHigh::CreateNewStudentObject(AccountNumberOfStudent);

		cout << "\n Add New Student Screen";
		cout << "\n___________________________\n";

		_ReadStudentInfo(NewStudent);

		clsSchoolStudentJuniorHigh::enSaveResults SaveResult;

		SaveResult = NewStudent.Save();

		switch (SaveResult)
		{
		case clsSchoolStudent::enSaveResults::svSucceeded:
		{
			cout << "Add New Student is Succeeded .";
			NewStudent.Print();
			break;
		}

		case clsSchoolStudent::enSaveResults::svFalidEmptyObject:
		{
			cout << "Opss , Thes object of Student is Empty .";
			break;
		}

		case clsSchoolStudent::enSaveResults::svFaildStudentNumberIsExist:
		{
			cout << "this account student is alread exits in School";
		}
		}
	}

	static void ShowAddNewStudentHighScreen()
	{
		string AccountNumberOfStudent = "";
		cout << "Please enter Account Number Of New Student : ";
		AccountNumberOfStudent = clsInputValidate::ReadString();

		while (clsSchoolStudentHigh::IsStudentExist(AccountNumberOfStudent))
		{
			cout << "This Student is alread exists in School , Please enter another one : ";
			AccountNumberOfStudent = clsInputValidate::ReadString();
		}

		clsSchoolStudentHigh NewStudent = clsSchoolStudentHigh::CreateNewStudentObject(AccountNumberOfStudent);

		cout << "\n Add New Student Screen";
		cout << "\n___________________________\n";

		_ReadStudentInfo(NewStudent);

		clsSchoolStudentHigh::enSaveResults SaveResult;

		SaveResult = NewStudent.Save();

		switch (SaveResult)
		{
		case clsSchoolStudent::enSaveResults::svSucceeded:
		{
			cout << "Add New Student is Succeeded .";
			NewStudent.Print();
			break;
		}

		case clsSchoolStudent::enSaveResults::svFalidEmptyObject:
		{
			cout << "Opss , Thes object of Student is Empty .";
			break;
		}

		case clsSchoolStudent::enSaveResults::svFaildStudentNumberIsExist:
		{
			cout << "this account student is alread exits in School";
		}
		}
	}




};

