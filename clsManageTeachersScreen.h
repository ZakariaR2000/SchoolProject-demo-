#pragma once
#include <iomanip>


#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListTeacherScreen.h"
#include "clsAddNewTecherScreen.h"
#include "clsDeleteTeacherScreen.h"
#include "clsUpdateTeacherScreen.h"
#include "clsFindTecherScreen.h"

class clsManageTeachersScreen : protected clsScreen
{


private:

	static short _ReadNumberOfOption()
	{
		short Number;
		cout << "\t\t\t\t\t" << "Please enter the number between [1] and [6] .";
		Number = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Number;
	}


	enum enTypeOfOption
	{
		enListTeachers = 1, enAddNewTeacher = 2, enDeleteTeacher = 3,
		enUpdateTeacher = 4, enFindTeacher = 5, enMainMenue = 6
	};


	static void _ShowListsTeachersScreen()
	{
		////cout << "List Screen well be here ";
		clsListTeacherScreen::ShowListTeachersScreen();
	}

	static void _ShowAddNewTeacherScreen()
	{
		//cout << "Add New student Screen well be here ";
		clsAddNewTecherScreen::ShowAddNewTecherScreen();

	}

	static void _ShowDeleteTeacherScreen()
	{
		//cout << "Delete Screen well be here ";
		clsDeleteTeacherScreen::ShowDeleteTeacherScreen();
	}

	static void _ShowUpdateTeacherScreen()
	{
		//cout << "Update Screen well be here ";
		clsUpdateTeacherScreen::ShowUpdateTeacherScreen();
	}

	static void _ShowFindTeacherScreen()
	{
		//cout << "Find Screen well be here ";
		clsFindTecherScreen::ShowFindTeacherScreen();
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
		case enTypeOfOption::enListTeachers:
		{
			system("cls");
			_ShowListsTeachersScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enAddNewTeacher:
		{
			system("cls");
			_ShowAddNewTeacherScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enDeleteTeacher:
		{
			system("cls");
			_ShowDeleteTeacherScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enUpdateTeacher:
		{
			system("cls");
			_ShowUpdateTeacherScreen();
			_GoToTheMainMenueScreen();
			break;
		}
		case enTypeOfOption::enFindTeacher:
		{
			system("cls");
			_ShowFindTeacherScreen();
			_GoToTheMainMenueScreen();
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

		cout << "\t\t\t\t\t" << "[1] List Teachers .\n";
		cout << "\t\t\t\t\t" << "[2] Add New Teachers.\n";
		cout << "\t\t\t\t\t" << "[3] Delete Teachers.\n";
		cout << "\t\t\t\t\t" << "[4] Update Teachers.\n";
		cout << "\t\t\t\t\t" << "[5] Find Teachers.\n";
		cout << "\t\t\t\t\t" << "[6] Main Menue.\n";
		
		cout << "\n\t\t\t\t\t" << "========================================\n";

		_GoToTheSelectedScreen((enTypeOfOption)_ReadNumberOfOption());

	}


};

