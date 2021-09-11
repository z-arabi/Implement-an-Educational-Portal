#ifndef STU_H
#define STU_H

#include "person.h"
class course;

class Student : public Person
{
    public:
        Student(std::string first_name,std::string last_name,int id,float mean_score,int passed);
        Student():Student("","",0,0,0){}
        Student(Student& s);
        ~Student(){}
        // It returns student's mean score
        float get_mean(){ return mean_score; }
         // It adds a unit to student's semestes
        void operator++(){ semesters++; }
        void add_theo_course(Theorical* theo_course);
        void remove_theo_course(Theorical* theo_course);
        void add_lab_course(Lab* lab_course);
        void remove_lab_course(Lab* lab_course);
        bool operator!=(const Student& s);
        bool operator==(const Student& s);

        float mean_score;   // mean of the student's courses
        int passed{};   // sum of weights of passed courses
        int semesters{1};
        Theorical** theoric_er{};   // a set of poinetrs which point to active theorical courses of student
        int n_theo{};            // number of active theorical courses of student
        Lab** lab_er{};       // a set of poinetrs which point to active labs of student
        int n_lab{};        // number of active labs of student
};

#endif