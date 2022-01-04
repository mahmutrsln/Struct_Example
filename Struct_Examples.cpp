#include<iostream>
#include<cstring>


typedef struct Student {
	char name[50];
	char surname[50];
	double point;
} Student;

#define STUDENT_SIZE 3

enum Choices {
	Continue = 0,
	AddStudentChoice = 1,
	DisplayStudentChoice = 2,
	Exit = 3
};


void inputStudentInfo(Student*);
void displayStudentsInfo(Student*);
void displayProgramInfo(void);

static unsigned __int64 studentNumber = 0;

int main()
{
	Student stud[STUDENT_SIZE];
	Student* studPtr = stud;

	int choice = 0;

	while (choice != -1)
	{
		displayProgramInfo();
		std::cout << "secim : " << std::endl;;
		std::cin >> choice;

		switch (choice)
		{
		case Continue:
			break;
		case AddStudentChoice:
			inputStudentInfo(studPtr);
			break;
		case DisplayStudentChoice:
			displayStudentsInfo(studPtr);
			break;
		case Exit:
			choice = -1;
			break;
		default:
			break;
		}

	}



	return 0;
}


void inputStudentInfo(Student* studPtr) {

	char intName[50];
	char intSurName[50];


	std::cout << "Student name : " << std::endl;
	std::cin >> intName;
	strcpy((studPtr + studentNumber)->name, intName);

	std::cout << "Student surname : " << std::endl;
	std::cin >> intSurName;
	strcpy((studPtr + studentNumber)->surname, intSurName);

	std::cout << "Student point : " << std::endl;
	std::cin >> (studPtr + studentNumber)->point;

	studentNumber++;


}



void displayStudentsInfo(Student* studPtr)
{
	for (size_t i = 0; i < studentNumber; i++)
	{
		std::cout << "Student name : " << (*(studPtr + i)).name << std::endl;
		std::cout << "Student surname : " << (*(studPtr + i)).surname << std::endl;
		std::cout << "Student point : " << (*(studPtr + i)).point << std::endl;
	}
}


void displayProgramInfo()
{
	std::cout << "Add Student : 1" << std::endl;
	std::cout << "Display Student : 2" << std::endl;
	std::cout << "Exit : -1" << std::endl;
	std::cout << std::endl;
}