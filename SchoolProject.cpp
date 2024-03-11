#include <iostream>
#include "clsSchoolStudent.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUtil.h"

#include "clsAcademicLevelsScreen.h"
using namespace std;


void ReadStudentInfo(clsSchoolStudent& Student)
{
		

	cout << "\nEnter FirstName: ";
	Student.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName: ";
	Student.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Age: ";
	Student.Age = clsInputValidate::ReadShortNumber();

	cout << "\nEnter Email: ";
	Student.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Student.Phone = clsInputValidate::ReadString();

	cout << "\nEnter Classroom: ";
	Student.Classroom = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Student.AccountBalance = clsInputValidate::ReadFloatNumber();

	cout << "\nEnter Tagstatus: ";
	Student.Tagstatus = clsInputValidate::ReadString();

}

void Update()
{
	string AccountStudent = "";
	cout << "Please enter the Account Student : ";
	AccountStudent = clsInputValidate::ReadString();


	while (!clsSchoolStudent::IsStudentExist(AccountStudent))
	{
		cout << "this student is not found , please enter another one : ";
		AccountStudent = clsInputValidate::ReadString();
	}

	clsSchoolStudent Student1 = clsSchoolStudent::Find(AccountStudent);
	Student1.Print();

	cout << "\n\n Update Student ";
	cout << "\n___________________\n";

	ReadStudentInfo(Student1);

	clsSchoolStudent::enSaveResults SaveResults;
	SaveResults = Student1.Save();

	switch (SaveResults)
	{
	case clsSchoolStudent::enSaveResults::svSucceeded:
	{
		cout << "\Student Updated Successfully :-)\n";
		Student1.Print();
		break;
	}
	case clsSchoolStudent::enSaveResults::svFalidEmptyObject:
	{
		cout << "\nError account was not saved because it's Empty";
		break;
	}

	}
}


void DeleteStudent()
{
	string AccountStudent = "";
	cout << "Please enter Account Number Of Student : ";

	AccountStudent = clsInputValidate::ReadString();

	while (!clsSchoolStudent::IsStudentExist(AccountStudent))
	{
		cout << "This student is not in the School , Pleas enter anothe one : ";
		AccountStudent = clsInputValidate::ReadString();
	}

	clsSchoolStudent Student = clsSchoolStudent::Find(AccountStudent);
	Student.Print();

	char Answer = 'y';
	cout << "Do you sure you wont to delete this student Y/N ??";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{

		if (Student.Delete())
		{
			cout << "Delete Successfully";
			Student.Print();
		}
		else
		{
			cout << "\nError Student Was not Deleted\n";
		}
	}


}

void PrintStudntRecordLine(clsSchoolStudent Student)
{
	cout << "| " << left << setw(10) << Student.AccountNumberOfStudent();
	cout << "| " << left << setw(16) << Student.FullName();
	cout << "| " << left << setw(5) << Student.Age;
	cout << "| " << left << setw(20) << Student.Email;
	cout << "| " << left << setw(11) << Student.Phone;
	cout << "| " << left << setw(15) << Student.Classroom;
	cout << "| " << left << setw(10) << Student.AccountBalance;
	cout << "| " << left << setw(10) << Student.Tagstatus;

}

void PrintStudentRecordBalanceLine(clsSchoolStudent Student)
{
	cout << "\t\t\t\t\t";

	cout << "| " << left << setw(20) << Student.AccountNumberOfStudent();
	cout << "| " << left << setw(20) << Student.FullName();
	cout << "| " << left << setw(13) << Student.AccountBalance;

}

void ShowTotalBalances()
{
	vector<clsSchoolStudent> vStudents = clsSchoolStudent::GetStudentList();

	cout << "\n\t\t\t\t\t\t\t\t(" << vStudents.size() << ") Student(s)";

	cout << "\n\t\t\t\t\t_____________________________________________________________\n\n\t\t\t\t\t";

	cout << "| " << left << setw(20) << " Acc. Student";
	cout << "| " << left << setw(20) << "Student Name";
	cout << "| " << left << setw(20) << "Balancy";

	cout << "\n\t\t\t\t\t_____________________________________________________________\n";


	float TotalBalancies = clsSchoolStudent::GetTotalBalancies();

	if (vStudents.size() == 0)
		cout << "there is no any student in this system right now.";
	else
	{
		for (clsSchoolStudent& S : vStudents)
		{
			PrintStudentRecordBalanceLine(S);
			cout << endl;
		}
	}
	cout << "\t\t\t\t\t_____________________________________________________________\n";


	cout<<"\t\t\t\t\t" << left << setw(20) << "Total Balancies = " << TotalBalancies << endl;
	cout<<"\t\t\t\t\t" << left << setw(20) << clsUtil::NumberToText(TotalBalancies);

}




int main()
{


	clsAcademicLevelsScreen::ShowAcademicLevelsMenueScreen();

	system("pause>0");
 
	return 0;
}

