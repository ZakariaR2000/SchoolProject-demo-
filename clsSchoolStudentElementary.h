
#pragma once

#include<iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include "fstream"

class clsSchoolStudentElementary : public clsPerson
{


private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _Classroom = "Elementary School";
	string _AccountNumberOfStudent;
	string _Tagstatus;
	float _AccountBalance;
	float _Marks;
	bool _MarkedForDelete = false;

	static clsSchoolStudentElementary _GetEmptyStudentObject()
	{
		return clsSchoolStudentElementary(enMode::EmptyMode, "", "", 0, "", "", "", 0, 0, "");
	}

	static clsSchoolStudentElementary _ConvertLineToStudentObject(string Line, string Seperator = "#//#")
	{
		vector <string> vStudent = clsString::Split(Line, Seperator);

		return clsSchoolStudentElementary(enMode::UpdateMode, vStudent[0],
			vStudent[1], stof(vStudent[2]), vStudent[3], vStudent[4], vStudent[5],
			stof(vStudent[6]), stof(vStudent[7]), vStudent[8]);
	}

	static string _ConverStudentsObjectToLine(clsSchoolStudentElementary Student, string Seperator = "#//#")
	{
		string stDataLine = "";

		stDataLine += Student.FirstName + Seperator;
		stDataLine += Student.LastName + Seperator;
		stDataLine += to_string(Student.Age) + Seperator;
		stDataLine += Student.Email + Seperator;
		stDataLine += Student.Phone + Seperator;
		stDataLine += Student.AccountNumberOfStudent() + Seperator;
		stDataLine += to_string(Student.AccountBalance) + Seperator;
		stDataLine += to_string(Student.Marks) + Seperator;
		stDataLine += Student.Tagstatus;

		return stDataLine;


	}

	static vector<clsSchoolStudentElementary> _LoadStudentsDataFromFile()
	{
		vector<clsSchoolStudentElementary> _vStudents;

		fstream MyFile;
		MyFile.open("StudentElementary.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSchoolStudentElementary Students = _ConvertLineToStudentObject(Line);
				_vStudents.push_back(Students);
			}
			MyFile.close();
		}
		return _vStudents;
	}

	static void _SaveStudentsDataToFile(vector <clsSchoolStudentElementary> vStudent)
	{
		string DataLine;

		fstream MyFile;
		MyFile.open("StudentElementary.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsSchoolStudentElementary& S : vStudent)
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
		vector<clsSchoolStudentElementary> _vStudent;
		_vStudent = _LoadStudentsDataFromFile();

		for (clsSchoolStudentElementary& S : _vStudent)
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

		MyFile.open("StudentElementary.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}

public:

	clsSchoolStudentElementary(enMode Mode, string FirstName, string LastName, short Age, string Email, string Phone,
		string AccountNumberOfStudent, float AccountBalance,
		float Marks, string Tagstatus) :
		clsPerson(FirstName, LastName, Age, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumberOfStudent = AccountNumberOfStudent;
		_AccountBalance = AccountBalance;
		_Tagstatus = Tagstatus;
		_Marks = Marks;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	string AccountNumberOfStudent()
	{
		return _AccountNumberOfStudent;
	}

	string Classroom()
	{
		return _Classroom;
	}

	void GetEmptyClassroom()
	{
		_Classroom = "";
	}


	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void SetMarks(float Marks)
	{
		_Marks = Marks;
	}
	float GetMarks()
	{
		return _Marks;
	}
	__declspec(property(get = GetMarks, put = SetMarks)) float Marks;


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
		cout << "\nClassroom    : " << _Classroom;
		cout << "\nAccNumOfStud : " << _AccountNumberOfStudent;
		cout << "\nBalance      : " << AccountBalance;
		cout << "\nMarks        : " << Marks;
		cout << "\nTagstatus    : " << Tagstatus;
		cout << "\n___________________\n";

	}

	static clsSchoolStudentElementary Find(string AccountNumberOfStudent)
	{
		fstream MyFile;
		MyFile.open("StudentElementary.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSchoolStudentElementary Student = _ConvertLineToStudentObject(Line);
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
		clsSchoolStudentElementary Student = Find(AccountNumberOfStudent);

		return (!Student.IsEmpty());
	}


	enum enSaveResults { svFalidEmptyObject = 0, svSucceeded = 1, svFaildStudentNumberIsExist = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
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
			if (clsSchoolStudentElementary::IsStudentExist(_AccountNumberOfStudent))
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

	static clsSchoolStudentElementary CreateNewStudentObject(string AccountNumberOfStudent)
	{
		return clsSchoolStudentElementary(enMode::AddNewMode, "", "", 0, "", "", AccountNumberOfStudent,
			0, 0, "");
	}

	bool Delete()
	{
		vector<clsSchoolStudentElementary> vStudents = _LoadStudentsDataFromFile();

		for (clsSchoolStudentElementary& S : vStudents)
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

	static vector<clsSchoolStudentElementary> GetStudentList()
	{
		return _LoadStudentsDataFromFile();
	}

	static float GetTotalBalancies()
	{
		vector<clsSchoolStudentElementary> vStudents = GetStudentList();

		float TotalBalancies = 0;

		for (clsSchoolStudentElementary& S : vStudents)
		{
			TotalBalancies += S.AccountBalance;
		}
		return TotalBalancies;
	}

	static float GetAverageGrades()
	{
		vector<clsSchoolStudentElementary> vStudents = GetStudentList();

		float Counter = 0;

		for (clsSchoolStudentElementary& S : vStudents)
		{
			Counter += S.Marks;
		}
		return Counter /= vStudents.size();
	}



};



