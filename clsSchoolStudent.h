#pragma once

#include<iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include "fstream"
class clsSchoolStudent : public clsPerson
{


private:

	enum enMode {EmptyMode = 0 , UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	string _Classroom;
	string _AccountNumberOfStudent;
	string _Tagstatus;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsSchoolStudent _GetEmptyStudentObject()
	{
		return clsSchoolStudent(enMode::EmptyMode, "", "", 0, "", "", "", "", 0, "");
	}

	static clsSchoolStudent _ConvertLineToStudentObject(string Line, string Seperator = "#//#")
	{
		vector <string> vStudent = clsString::Split(Line, Seperator);

		return clsSchoolStudent(enMode::UpdateMode, vStudent[0], vStudent[1], stof(vStudent[2]), vStudent[3]
			, vStudent[4], vStudent[5], vStudent[6], stof(vStudent[7]), vStudent[8]);
	}

	static string _ConverStudentsObjectToLine(clsSchoolStudent Student, string Seperator = "#//#")
	{
		string stDataLine = "";

		stDataLine += Student.FirstName + Seperator;
		stDataLine += Student.LastName + Seperator;
		stDataLine += to_string(Student.Age) + Seperator;
		stDataLine += Student.Email + Seperator;
		stDataLine += Student.Phone + Seperator;
		stDataLine += Student.AccountNumberOfStudent() + Seperator;
		stDataLine += Student.Classroom + Seperator;
		stDataLine += to_string(Student.AccountBalance) + Seperator;
		stDataLine += Student.Tagstatus;

		return stDataLine;


	}

	static vector<clsSchoolStudent> _LoadStudentsDataFromFile()
	{
		vector<clsSchoolStudent> _vStudents;

		fstream MyFile;
		MyFile.open("Students.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile , Line))
			{
				clsSchoolStudent Students = _ConvertLineToStudentObject(Line);
				_vStudents.push_back(Students);
			}
			MyFile.close();
		}
		return _vStudents;
	}

	static void _SaveStudentsDataToFile(vector <clsSchoolStudent> vStudent)
	{
		string DataLine;

		fstream MyFile;
		MyFile.open("Students.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsSchoolStudent& S : vStudent)
			{
				if (S.MarkedForDelete() == false)
				{
					DataLine = _ConverStudentsObjectToLine(S);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsSchoolStudent> _vStudent;
		_vStudent = _LoadStudentsDataFromFile();

		for (clsSchoolStudent& S : _vStudent)
		{
			if (S.AccountNumberOfStudent() == AccountNumberOfStudent())
			{
				S = *this;
				break;
			}
		}

		_SaveStudentsDataToFile(_vStudent);
	}

	void _AddNew()
	{
		_AddNewLineToFile(_ConverStudentsObjectToLine(*this));
	}

	void _AddNewLineToFile(string Line)
	{
		fstream MyFile;

		MyFile.open("Students.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

public:

	clsSchoolStudent(enMode Mode, string FirstName, string LastName, short Age, string Email, string Phone,
		string AccountNumberOfStudent, string Classroom, float AccountBalance , string Tagstatus) :
		clsPerson(FirstName, LastName , Age, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumberOfStudent = AccountNumberOfStudent;
		_Classroom = Classroom;
		_AccountBalance = AccountBalance;
		_Tagstatus = Tagstatus;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	string AccountNumberOfStudent()
	{
		return _AccountNumberOfStudent;
	}


	void SetClassroom(string Classroom)
	{
		_Classroom = Classroom;
	}
	string GetClassroom()
	{
		return _Classroom;
	}
	__declspec(property(get = GetClassroom, put = SetClassroom)) string Classroom;


	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	
	void SetTagstatus(string Tagstatus)
	{
		_Tagstatus = Tagstatus;
	}
	string GetTagstatus()
	{
		return _Tagstatus;
	}
	__declspec(property(get = GetTagstatus, put = SetTagstatus)) string Tagstatus;

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}


	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName    : " << FirstName;
		cout << "\nLastName     : " << LastName;
		cout << "\nFull Name    : " << FullName();
		cout << "\nAge          : " << Age;
		cout << "\nEmail        : " << Email;
		cout << "\nPhone        : " << Phone;
		cout << "\nClassroom    : " << Classroom;
		cout << "\nAccNumOfStud : "  << _AccountNumberOfStudent;
		cout << "\nBalance      : " << AccountBalance;
		cout << "\nTagstatus    : " << Tagstatus;
		cout << "\n___________________\n";

	}

	static clsSchoolStudent Find(string AccountNumberOfStudent)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSchoolStudent Student = _ConvertLineToStudentObject(Line);
				if (Student.AccountNumberOfStudent() == AccountNumberOfStudent)
				{
					MyFile.close();
					return Student;
				}
				
			}
			MyFile.close();
		}
		return _GetEmptyStudentObject();
	}

	static bool IsStudentExist(string AccountNumberOfStudent)
	{
		clsSchoolStudent Student = Find(AccountNumberOfStudent);

		return (!Student.IsEmpty());
	}


	enum enSaveResults {svFalidEmptyObject = 0 , svSucceeded = 1 , svFaildStudentNumberIsExist = 2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if(IsEmpty())
			{
				return enSaveResults::svFalidEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			if (clsSchoolStudent::IsStudentExist(_AccountNumberOfStudent))
			{
				return enSaveResults::svFaildStudentNumberIsExist;
			}
			else

			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		}
	}

	static clsSchoolStudent CreateNewStudentObject(string AccountNumberOfStudent)
	{
		return clsSchoolStudent(enMode::AddNewMode, "", "", 0, "", "", AccountNumberOfStudent,
			"", 0, "");
	}

	bool Delete()
	{
		vector<clsSchoolStudent> vStudents = _LoadStudentsDataFromFile();

		for (clsSchoolStudent& S : vStudents)
		{
			if (S.AccountNumberOfStudent() == _AccountNumberOfStudent)
			{
				S._MarkedForDelete = true;
				break;
			}
		}

		_SaveStudentsDataToFile(vStudents);
		*this = _GetEmptyStudentObject();
		return true;
	}

	static vector<clsSchoolStudent> GetStudentList()
	{
		return _LoadStudentsDataFromFile();
	}

	static float GetTotalBalancies()
	{
		vector<clsSchoolStudent> vStudents = GetStudentList();

		float TotalBalancies = 0;

		for (clsSchoolStudent& S : vStudents)
		{
			TotalBalancies += S.AccountBalance;
		}
		return TotalBalancies;
	}

};

