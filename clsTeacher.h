#pragma once

#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>


class clsTeacher : public clsPerson
{


private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _TeacherName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;

	static clsTeacher _ConvertLinetoTeacherObject(string Line, string Seperator = "#//#")
	{
		vector<string> vTeacherData;
		vTeacherData = clsString::Split(Line, Seperator);

		return clsTeacher(enMode::UpdateMode, vTeacherData[0], vTeacherData[1], stoi(vTeacherData[2]),
			vTeacherData[3], vTeacherData[4], vTeacherData[5], vTeacherData[6], stoi(vTeacherData[7]));

	}

	static string _ConvertTeacherObjectToLine(clsTeacher Teacher, string Seperator = "#//#")
	{

		string TeacherRecord = "";
		TeacherRecord += Teacher.FirstName + Seperator;
		TeacherRecord += Teacher.LastName + Seperator;
		TeacherRecord += to_string(Teacher.Age) + Seperator;
		TeacherRecord += Teacher.Email + Seperator;
		TeacherRecord += Teacher.Phone + Seperator;
		TeacherRecord += Teacher.TeacherName + Seperator;
		TeacherRecord += Teacher.Password + Seperator;
		TeacherRecord += to_string(Teacher.Permissions);

		return TeacherRecord;

	}


	static  vector <clsTeacher> _LoadTeachersDataFromFile()
	{

		vector <clsTeacher> vTeachers;

		fstream MyFile;
		MyFile.open("Teachers.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsTeacher User = _ConvertLinetoTeacherObject(Line);

				vTeachers.push_back(User);
			}

			MyFile.close();

		}

		return vTeachers;

	}

	static void _SaveTeachersDataToFile(vector <clsTeacher> vTeachrs)
	{

		fstream MyFile;
		MyFile.open("Teachers.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsTeacher U : vTeachrs)
			{
				if (U.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConvertTeacherObjectToLine(U);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsTeacher> _vTeachers;
		_vTeachers = _LoadTeachersDataFromFile();

		for (clsTeacher& U : _vTeachers)
		{
			if (U.TeacherName == TeacherName)
			{
				U = *this;
				break;
			}

		}

		_SaveTeachersDataToFile(_vTeachers);

	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConvertTeacherObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Teachers.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}


	static clsTeacher _GetEmptyUserObject()
	{
		return clsTeacher(enMode::EmptyMode, "", "", 0, "", "", "", "", 0);
	}



public:

	enum enPermission
	{
		eAll = -1, pListTeachers = 1, pAddNewTeacher = 2, pDeleteTeacher = 4,
		pUpdateTeacher = 8, pFindTeacher = 16, pTransaction = 32, pManageTeachers = 64
	};

	clsTeacher(enMode Mode, string FirstName, string LastName, short Age,
		string Email, string Phone, string TeacherName, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Age, Email, Phone)
	{
		_Mode = Mode;
		_TeacherName = TeacherName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	string GetTeacherName()
	{
		return _TeacherName;
	}
	void SetTeacherName(string TeacherName)
	{
		_TeacherName = TeacherName;
	}
	__declspec(property(get = GetTeacherName, put = SetTeacherName)) string TeacherName;


	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static clsTeacher Find(string TeacherName)
	{
		fstream MyFile;

		MyFile.open("Teachers.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsTeacher Teacher = _ConvertLinetoTeacherObject(Line);
				if (Teacher.TeacherName == TeacherName)
				{
					MyFile.close();
					return Teacher;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsTeacher Find(string TeacherName, string Password)
	{
		fstream MyFile;

		MyFile.open("Teachers.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsTeacher Teacher = _ConvertLinetoTeacherObject(Line);
				if (Teacher.TeacherName == TeacherName && Teacher.Password == Password)
				{
					MyFile.close();
					return Teacher;
				}
			}

			MyFile.close();

		}



	};
	
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildTeacherExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
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
			//This will add new record to file or database
			if (clsTeacher::IsTeacherExist(_TeacherName))
			{
				return enSaveResults::svFaildTeacherExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}

	static bool IsTeacherExist(string TeacherName)
	{

		clsTeacher Teacher = clsTeacher::Find(TeacherName);
		return (!Teacher.IsEmpty());
	}

	bool Delete()
	{
		vector <clsTeacher> _vUsers;
		_vUsers = _LoadTeachersDataFromFile();

		for (clsTeacher& U : _vUsers)
		{
			if (U.TeacherName == _TeacherName)
			{
				U._MarkedForDelete = true;
				break;
			}

		}

		_SaveTeachersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static clsTeacher GetAddNewTeacherObject(string TeacherName)
	{
		return clsTeacher(enMode::AddNewMode, "", "", 0, "", "", TeacherName, "", 0);
	}

	static vector <clsTeacher> GetTeachersList()
	{
		return _LoadTeachersDataFromFile();
	}


};

