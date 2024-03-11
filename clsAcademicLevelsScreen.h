#pragma once


#include "clsScreen.h"
#include "clsSchoolStudent.h"
#include "clsInputValidate.h"
#include <iomanip>

#include "clsKindergartenScreen.h"
#include "clsElementarySchoolScreen.h"
#include "clsJuniorHighSchoolScreen.h"
#include "clsHighSchoolScreen.h"

class clsAcademicLevelsScreen : protected clsScreen
{
private:

	static short _ReadNumber()
	{
		cout << "\t\t\t\t\t" << "Please enter number between [1] and [4] : ";
		short Number;

		Number = clsInputValidate::ReadShortNumberBetween(1, 4, "Number is out of the range,please enter again :");
		return Number;	
		
	}

	enum enTypeOfAcademicLevel
	{
		enKindergarten = 1, enElementarySchool = 2,
		enJuniorHighSchool = 3, enHighSchool = 4
	};

	static void _ShowKindergartenScreen()
	{
		clsKindergartenScreen::ShowMainMenueScreen();
	}

	static void _ShowElementarySchoolScreen()
	{
		clsElementarySchoolScreen::ShowMainMenueScreen();
	}

	static void _ShowJuniorHighSchoolScreen()
	{
		clsJuniorHighSchoolScreen::ShowMainMenueScreen();
	}

	static void _ShowHighSchoolScreen()
	{
		clsHighSchoolScreen::ShowMainMenueScreen();
	}

	static void _GoToTheAcademicLevelsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowAcademicLevelsMenueScreen();
	}

	static void _SelectedAcademicLevel(enTypeOfAcademicLevel Option)
	{
		switch (Option)
		{
		case enTypeOfAcademicLevel::enKindergarten:
		{
			system("cls");
			_ShowKindergartenScreen();
			_GoToTheAcademicLevelsMenue();
			break;
		}
		case enTypeOfAcademicLevel::enElementarySchool:
		{
			system("cls");
			_ShowElementarySchoolScreen();
			_GoToTheAcademicLevelsMenue();
			break;
		}
		case enTypeOfAcademicLevel::enJuniorHighSchool:
		{
			system("cls");
			_ShowJuniorHighSchoolScreen();
			_GoToTheAcademicLevelsMenue();
			break;
		}
		case enTypeOfAcademicLevel::enHighSchool:
		{
			system("cls");
			_ShowHighSchoolScreen();
			_GoToTheAcademicLevelsMenue();
			break;
		}
		}
	}




public:

	static void ShowAcademicLevelsMenueScreen()
	{
		system("cls");

		_DrawScreenHeader("\tAcademic Levels Screen");

		cout << "\t\t\t\t\t" << "========================================\n\n";

		cout << "\t\t\t\t\t" << "[1] Kindergarten.\n";
		cout << "\t\t\t\t\t" << "[2] Elementary School.\n";
		cout << "\t\t\t\t\t" << "[3] Junior High School.\n";
		cout << "\t\t\t\t\t" << "[4] High School.\n";

		cout << "\t\t\t\t\t" << "========================================\n\n";

		_SelectedAcademicLevel((enTypeOfAcademicLevel)_ReadNumber());

	}


};

