#pragma once

#include "clsScreen.h"
#include "clsTeacher.h"
#include "clsInputValidate.h"

class clsFindTecherScreen : protected clsScreen
{


private:


	static void _PrintTeacher(clsTeacher Teacher)
	{
		cout << "\nTeacher Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Teacher.FirstName;
		cout << "\nLastName    : " << Teacher.LastName;
		cout << "\nFull Name   : " << Teacher.FullName();
		cout << "\nEmail       : " << Teacher.Email;
		cout << "\nPhone       : " << Teacher.Phone;
		cout << "\nUser Name   : " << Teacher.TeacherName;
		cout << "\nPassword    : " << Teacher.Password;
		cout << "\nPermissions : " << Teacher.Permissions;
		cout << "\n___________________\n";
	}

	static string _ReadTeacherUsername()
	{
		string TeacherUserName = "";
		cout << "Please enter Teacher Username : ";
		TeacherUserName = clsInputValidate::ReadString();


		while (!clsTeacher::IsTeacherExist(TeacherUserName))
		{
			cout << "This Teacher Is Not Exist , Please enter another one : ";
			TeacherUserName = clsInputValidate::ReadString();
		}

		return TeacherUserName;
	}

public:

	static void ShowFindTeacherScreen()
	{

		_DrawScreenHeader("\t Find Teacher Screen");

		string TeacherUserName = "";
		cout << "Please enter Teacher Username : ";
		TeacherUserName = clsInputValidate::ReadString();


		while (!clsTeacher::IsTeacherExist(TeacherUserName))
		{
			cout << "This Teacher Is Not Exist , Please enter another one : ";
			TeacherUserName = clsInputValidate::ReadString();
		}

		

		clsTeacher Teacher = clsTeacher::Find(TeacherUserName);

		if (!Teacher.IsEmpty())
		{
			cout << "\nTeacher Found";
		}
		else
		{
			cout << "\nTeacher Was Not Found";

		}

		_PrintTeacher(Teacher);

		

	}

};

