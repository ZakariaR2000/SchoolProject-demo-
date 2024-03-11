#pragma once

#include "clsScreen.h"
#include "clsTeacher.h"
#include "clsInputValidate.h"

class clsUpdateTeacherScreen : protected clsScreen
{

private:

	static void _ReadTeacherInfo(clsTeacher& Teacher)
	{
		cout << "\nEnter First Name : ";
		Teacher.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name : ";
		Teacher.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Age : ";
		Teacher.Age = clsInputValidate::ReadShortNumber();

		cout << "\nEnter Email : ";
		Teacher.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		Teacher.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password : ";
		Teacher.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions : ";
		Teacher.Permissions = _ReadPermissionToSet();




	}

	static void _PrintTeacher(clsTeacher Teacher)
	{
		cout << "\nUser Card:";
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

	static int _ReadPermissionToSet()
	{
		int Permission = 0;
		char Answer = 'n';

		cout << "Do you to give full permissions? n/y";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
			return -1;




		cout << "Show Teacher List? n/y?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsTeacher::enPermission::pListTeachers;
		}

		cout << "Add New Teacher? n/y?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsTeacher::enPermission::pAddNewTeacher;
		}

		cout << "Delete Teacher? n/y?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsTeacher::enPermission::pDeleteTeacher;
		}

		cout << "Update Teacher? n/y?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsTeacher::enPermission::pUpdateTeacher;
		}

		cout << "Find Teacher? n/y?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsTeacher::enPermission::pFindTeacher;
		}

		cout << "\nTransaction? Y/N?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permission += clsTeacher::enPermission::pTransaction;
		}

		cout << "\nManage Users? Y/N";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permission += clsTeacher::enPermission::pManageTeachers;
		}

	}




public:

	static void ShowUpdateTeacherScreen()
	{
		_DrawScreenHeader("\t Update Teacher Screen");

		string TeacherName = "";
		cout << "Please enter the Teacher Name : ";
		TeacherName = clsInputValidate::ReadString();

		while (!clsTeacher::IsTeacherExist(TeacherName))
		{
			cout << "This teacher is not existx , please enter another one : ";
			TeacherName = clsInputValidate::ReadString();
		}

		clsTeacher Teacher = clsTeacher::Find(TeacherName);

		_PrintTeacher(Teacher);

		char Answer = 'n';
		cout << "Are you sure you want to update this Teacher? Y/N ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate User Info:";
			cout << "\n____________________\n";


			_ReadTeacherInfo(Teacher);


			clsTeacher::enSaveResults SaveResult;

			SaveResult = Teacher.Save();

			switch (SaveResult)
			{
			
			case clsTeacher::enSaveResults::svSucceeded:
			{
				cout << "\nUser Updated Successfully :-)\n";

				_PrintTeacher(Teacher);
				break;
			}

			

			case clsTeacher::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError User was not saved because it's Empty";
				break;	
			}
			}

		}
	}

};

