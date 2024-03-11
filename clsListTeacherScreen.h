#pragma once
#include <iomanip>


#include "clsScreen.h"
#include "clsTeacher.h"

class clsListTeacherScreen : protected clsScreen
{
private:
	

	static void _PrintTeacherRecordLine(clsTeacher Teacher)
	{
		cout << setw(8) << left << "" << "| " << setw(18) << left << Teacher.TeacherName;
		cout << "| " << setw(20) << left << Teacher.FullName();
		cout << "| " << setw(5) << left << Teacher.Age;
		cout << "| " << setw(12) << left << Teacher.Phone;
		cout << "| " << setw(18) << left << Teacher.Email;
		cout << "| " << setw(12) << left << Teacher.Password;
		cout << "| " << setw(12) << left << Teacher.Permissions;
	}


public:


	static void ShowListTeachersScreen()
	{
		vector <clsTeacher> vTeachers = clsTeacher::GetTeachersList();

		string Title = "\t Teachers List Screen";
		string SubTitle = "\t    (" + to_string(vTeachers.size()) + ") Teacher(s).";


		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "\n\t________________________________________________________________";
		cout << "_______________________________________________\n";
		

		cout << setw(8) << left << "" << "| " << left << setw(18) << "Teacher Username";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(5) << "Age";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(18) << "Email";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permissions";


		cout << setw(8) << left << "\n\t________________________________________________________________";
		cout << "_______________________________________________\n";



		if (vTeachers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsTeacher Techer : vTeachers)
			{

				_PrintTeacherRecordLine(Techer);
				cout << endl;
			}

		cout << setw(8) << left << "\n\t________________________________________________________________";
		cout << "_______________________________________________\n";


	}


};

