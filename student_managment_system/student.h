#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>


class Student {
	private:
		int id, age;
		float grade;
		std::string name;
	public:
		Student(int, int, float, std::string);
		int get_id();
		int get_age();
		float get_grade();
		std::string get_name();
};

#endif

