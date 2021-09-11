#include "lab.h"

Lab::Lab(Course* cours,Student* stud,Prof* profes,int wight):ER{}
{
    // std::cout << "LAB constructor,items\n";
    course = cours;
    student = stud;
    professor = profes;
    weight = wight;
}

Lab::Lab(Prof* profes):ER{}
{
    // std::cout << "Lab constructor,just professor\n";
    professor = profes;
} 

float Lab::calculate_final()
{
    std::cout << "calculating final score in Lab ER\n";
    final =  (10*final_exam+8*report+2*activities)/20 ;
    return final;
}

void Lab::scoring(float report,float activities,float final_exam,int absences)
{
    std::cout << "scoring in lab\n";
    this->report = report;
    this->activities = activities;
    this->final_exam = final_exam;
    this->absences = absences;
    calculate_final();
    professor->scores.push_back(final);
    if(final>=10 and final<=20)
        passed=true;
}
