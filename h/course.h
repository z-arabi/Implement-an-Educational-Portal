#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

#include "er.h"
#include "theorical.h"
#include "lab.h"
#include "person.h"
#include "student.h"
#include "prof.h"


class Course
{
    public:
        Course(Prof* profesor,std::string name,int weight,bool theorical);
        Course():Course(0,"",0,0){}
        Course(Prof* profesor,Student* student,std::string name,int weight,bool theorical);
        ~Course();
        bool operator<(const Course& course); // comparing population of two course
        bool operator=(const Course& course);  // comparing population of two course
        void operator()(Student& student,Theorical& theo,int option);
        void operator()(Student& student,Lab& lab,int option);
        float max(); // returm max score in this course
        float average(); // return average of class

        Prof* professor;    // points to course professor
        std::string name;  // name of course
        int weight;     // weight of course
        bool theorical;  // this course is lab or theorical?
        int population{};    // number of class students
        ER** educational_reports;   // a set of pointers which point to students ERs.
        Student** students;   // a set of pointers which point to course students
		
};

#endif