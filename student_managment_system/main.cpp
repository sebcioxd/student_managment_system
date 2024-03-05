#include <iostream>
#include <vector>
#include "student.h"
#include <cmath>
#include <fstream>
#include <sstream>

void add_student(std::vector<Student>& myNewVector); // pass by reference cuz we wanna modify the original vector not to make a copy of it and it being useless outside of the function.
void display_students(std::vector<Student>& myNewVector); //funcion to display student list;
void remove_student(std::vector<Student>& myNewVector); //function to remove student from the list;
void write_to_file(std::vector<Student>& myNewVector);




int main(int argc, char* argv[]) {
	std::string input;
	char answ;
	
	std::vector<Student> studentList; // vector to store in the students list

	// CLI interface;
	std::cout << "Welcome to student managment system, here you can display, remove, add and update students!" << "\n";
	std::cout << "<-------------------------------------->\n";
	
	while (true)
	{
		std::cout << "Press, 'd' for display, 'a' to add the students, 'r' to remove the students,\n 'w' to write the students into file or 1 to exit the SMS!\n";
		std::cin >> input;
		if (input.length() != 1) //check if input has more chars than 1;
		{
			std::cout << "Please provide correct character!"; //if no then exit the program;
			exit(0);
		}
		
		answ = input[0]; //assign the answ to the first val of the input;
		switch (answ)
		{
		case 'd':
			display_students(studentList);
			break;
		case 'a':
			add_student(studentList);
			break;
		case 'r':
			remove_student(studentList);
			break;
		case 'w':
			write_to_file(studentList);
			break;
		case 1:
			exit(0);
			break;
		default:
			std::cout << "Couldnt initalize the input you provided\n";
			exit(0);
			break;
		}
	}
}


void add_student(std::vector<Student>& myNewVector) {
	int students, id, age;
	float grade;
	std::string name;

	std::cout << "How many students you want to add?: ";
	std::cin >> students;
	if (!std::cin) {
		std::cout << "students has to be an integer!";
		exit(0);
	}

	for (int i = 0; i < students; ++i)
	{
		std::cout << "Student no. " << i + 1 << "\n";
		
		std::cout << "enter info like this: id age grade name , with spaces separating them: ";
		std::cin >> id >> age >> grade >> name;
		if (!std::cin) {
			std::cout << "Your input was wrong! (id, age, grade) has to be an integer!";
			exit(0);
		}

		Student newStudent(id, age, grade, name); //create Object with our passed data by user;
		myNewVector.push_back(newStudent); // push the data into our vector;

		
	}
}


void display_students(std::vector<Student>& myNewVector) {
	int studentsSize = myNewVector.size(); // get the size of the vector to itterate throught it;

	for (int i = 0; i < studentsSize; ++i)
	{
		std::cout << "Student number " << i+1 << "\n";
		//get the index of the vector, and then get the id that is stored in the index.
		// it looks smth like this: 0:{id, age, grade, name} 1:{id, age, grade, name} 
		// now we getting the index.age for example.

		std::cout << "ID: " << myNewVector[i].get_id() << "\n"; 
		std::cout << "Age: " << myNewVector[i].get_age() << "\n";
		std::cout << "Grade: " << myNewVector[i].get_grade() << "\n";
		std::cout << "Name: " << myNewVector[i].get_name() << "\n";
		std::cout << "\n";
	}
}

void remove_student(std::vector<Student>& myNewVector) {
	int answ;
	int studentsSize = myNewVector.size();
	std::cout << "Please provide student number you want to remove: ";
	std::cin >> answ;
	if (!std::cin) {
		std::cout << "Input has to be an integer!";
		exit(0);
	}
	if (answ > studentsSize) {
		std::cout << "We couldnt find this student number in the list!\n";
	}
	else {
		myNewVector.erase(myNewVector.begin() + answ - 1);
		std::cout << "Removed the " << answ << "th student from the list\n";
	}
	
}

void write_to_file( std::vector<Student>& myNewVector) {
	int studentsSize = myNewVector.size();
	std::fstream file;
	file.open("file.txt", std::ios::in | std::ios::out);

	if (file.good())
	{
		for ( auto& student : myNewVector) {
			// Convert each student object to a string representation
			std::ostringstream oss;
			oss << "ID: " << student.get_id() << "," <<  "AGE: "<< student.get_age() << "," << "GRADE: " << student.get_grade() << "," << "NAME: " << student.get_name();
			std::string studentString = oss.str();

			// Write the student string to the file
			file << studentString << std::endl;
		}
	}
	else {
		std::cout << "Error opening the file!";
	}

	file.close();
}


