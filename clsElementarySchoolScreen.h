#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListStudentScreen.h"
#include "clsAddNewStudentScreen.h"
#include "clsDeleteStudentScreen.h"
#include "clsUpdateStudentScreen.h"
#include "clsAverageGradesScreen.h"


class clsElementarySchoolScreen : protected clsScreen
{


private:

	static short _ReadNumberOfOption()
	{
		short Number;
		cout << "\t\t\t\t\t" << "Please enter the number between [1] and [9] .";
		Number = clsInputValidate::ReadShortNumberBetween(1, 9);
		return Number;
	}

	enum enTypeOfOption
	{
		enListStudents = 1, enAddNewStudent = 2, enDeleteStudent = 3, enUpdateStudent = 4,
		enFindStudent = 5, enAcademicLevels = 6, enAverageGrades = 7, enManageTeachers = 8,
		enLogout = 9
	};


	static void _ShowListStudentsScreen()
	{
		clsListStudentScreen::ShowStudentListElementaryScreen();
		//cout << "List Screen well be here ";

	}

	static void _ShowAddNewStudentScreen()
	{
		//cout << "Add New student Screen well be here ";
		clsAddNewStudentScreen::ShowAddNewStudentElementaryScreen();
	}

	static void _ShowDeleteStudentScreen()
	{
		//cout << "Delete Screen well be here ";
		clsDeleteStudentScreen::ShowDeleteStudentElementaryScreen();

	}

	static void _ShowUpdateStudentScreen()
	{
		//cout << "Update Screen well be here ";
		clsUpdateStudentScreen::ShowUpdateStudentElementaryScreen();
	}

	static void _ShowFindStudentScreen()
	{
		//cout << "Find Screen well be here ";
		clsFindStudentScreen::ShowFindStudentElementaryScreen();
	}

	static void _ShowAverageGradesScreen()
	{
		//cout << "Average grades Screen well be here ";
		clsAverageGradesScreen::ShowAverageElementaryGrades();
	}

	static void _ShowManageTeachersScreen()
	{
		cout << "Manage Screen well be here ";
	}

	static void _ShowLogoutScreen()
	{
		cout << "Logout well be here ";
	}

	static void _GoToTheMainMenueScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenueScreen();
	}

	static void _GoToTheSelectedScreen(enTypeOfOption Option)
	{
		switch (Option)
		{
		case enTypeOfOption::enListStudents:
		{
			system("cls");
			_ShowListStudentsScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enAddNewStudent:
		{
			system("cls");
			_ShowAddNewStudentScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enDeleteStudent:
		{
			system("cls");
			_ShowDeleteStudentScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enUpdateStudent:
		{
			system("cls");
			_ShowUpdateStudentScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enFindStudent:
		{
			system("cls");
			_ShowFindStudentScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enAverageGrades:
		{
			system("cls");
			_ShowAverageGradesScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enManageTeachers:
		{
			system("cls");
			_ShowManageTeachersScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enLogout:
		{
			system("cls");
			_ShowLogoutScreen();
			break;
		}
		}
	}


public:

	static void ShowMainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Main Menue Screen");

		cout << "\t\t\t\t\t" << "========================================\n\n";

		cout << "\t\t\t\t\t" << "[1] Show List Students Screen.\n";
		cout << "\t\t\t\t\t" << "[2] Add New Student Screen.\n";
		cout << "\t\t\t\t\t" << "[3] Delete Student Screen.\n";
		cout << "\t\t\t\t\t" << "[4] Update Student Screen.\n";
		cout << "\t\t\t\t\t" << "[5] Find Student .\n";
		cout << "\t\t\t\t\t" << "[7] Show Average grades.\n";
		cout << "\t\t\t\t\t" << "[8] Manage Teachers.\n";
		cout << "\t\t\t\t\t" << "[9] Show Logout Screen.\n";

		cout << "\n\t\t\t\t\t" << "========================================\n";

		_GoToTheSelectedScreen((enTypeOfOption)_ReadNumberOfOption());


	}
};



