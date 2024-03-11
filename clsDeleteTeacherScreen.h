#pragma once

#include "clsScreen.h"
#include "clsTeacher.h"

class clsDeleteTeacherScreen : protected clsScreen
{
private:

	static void _PrintTeacher(clsTeacher Teacher)
	{
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName     : " << Teacher.FirstName;
        cout << "\nLastName      : " << Teacher.LastName;
        cout << "\nFull Name     : " << Teacher.FullName();
        cout << "\nEmail         : " << Teacher.Email;
        cout << "\nPhone         : " << Teacher.Phone;
        cout << "\nTeacher Name  : " << Teacher.TeacherName;
        cout << "\nPassword      : " << Teacher.Password;
        cout << "\nPermissions   : " << Teacher.Permissions;
        cout << "\n___________________\n";
	}


public:

	static void ShowDeleteTeacherScreen()
	{
        _DrawScreenHeader("\t Delete Teacher Screen ");

        string TeacherName = "";
        cout << "Please enter Teacher Name : ";
        TeacherName = clsInputValidate::ReadString();

        while (!clsTeacher::IsTeacherExist(TeacherName))
        {
            cout << "This Teacher is not Exists , enter another one : ";
            TeacherName = clsInputValidate::ReadString();
        }

        clsTeacher Teacher = clsTeacher::Find(TeacherName);
        _PrintTeacher(Teacher);

        char Answer = 'n';
        cout << "Are you sure you wanna delete this Teacher ? y/n";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Teacher.Delete())
            {
                cout << "Deleted Seccussfully";
                _PrintTeacher(Teacher);
            }
            else
            {
                cout << "Error To Delete";
            }
        }


	}

};

