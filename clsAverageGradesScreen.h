#pragma once

#include "clsScreen.h"
#include "clsSchoolStudentKindergarten.h"
#include "clsSchoolStudentElementary.h"
#include "clsSchoolStudentJuniorHigh.h"
#include "clsSchoolStudentHigh.h"

class clsAverageGradesScreen : protected clsScreen
{

public:

	static void ShowAverageKindergartenGrades()
	{
		_DrawScreenHeader("\t Average Grades : ");

		cout << "\t\t\t\t\t THE AVERAGE OF STUDENTS IN KINDERGARTEN CLASS = ";

		cout << clsSchoolStudentKindergarten::GetAverageGrades();
	}

	static void ShowAverageElementaryGrades()
	{
		_DrawScreenHeader("\t Average Grades : ");

		cout << "\t\t\t\t\t THE AVERAGE OF STUDENTS IN Elementary CLASS = ";

		cout << clsSchoolStudentElementary::GetAverageGrades();
	}

	static void ShowAverageJuniorHighGrades()
	{
		_DrawScreenHeader("\t Average Grades : ");

		cout << "\t\t\t\t\t THE AVERAGE OF STUDENTS IN Elementary CLASS = ";

		cout << clsSchoolStudentJuniorHigh::GetAverageGrades();
	}

	static void ShowAverageHighGrades()
	{
		_DrawScreenHeader("\t Average Grades : ");

		cout << "\t\t\t\t\t THE AVERAGE OF STUDENTS IN Elementary CLASS = ";

		cout << clsSchoolStudentHigh::GetAverageGrades();
	}



	

};

