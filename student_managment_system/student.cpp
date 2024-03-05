#include "student.h"
#include <vector>
#include <iostream>

Student::Student(int i, int a, float g, std::string n) {
	id = i;
	age = a;
	grade = g;
	name = n;
}

int Student::get_id() {
	return id;
}
int Student::get_age() {
	return age;
}
float Student::get_grade() {
	return grade;
}
std::string Student::get_name() {
	return name;
}

