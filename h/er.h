#ifndef ER_H
#define ER_H

#include <iostream>
#include <string>

#include "person.h"
#include "student.h"
#include "prof.h"
class Student;
class Prof;
class Person;
class Course;

class ER
{
    public:
        ER();
        ~ER(){}

        virtual float calculate_final(){ std::cout<<"not overriden\n"; return 0;};  // function which calculate final score
        virtual void scoring(float,float,float,int){ std::cout<<"nothing\n"; }  // function which score parameters

        Course* course;   
        Prof* professor;
        Student* student;  
        int weight;       // weight of course
        int absences{};       // number of student's absences
        float final{};    
        bool passed{false};   // student passed the course? 
};

#endif