#include "theorical.h"

Theorical::Theorical(Course* cours,Student* stud,Prof* profes,int wight):ER{}
{
    // std::cout << "THEO constructor,items\n";
    course = cours;
    student = stud;
    professor = profes;
    weight = wight;
}

Theorical::Theorical(Prof* profes):ER{}
{
    // std::cout << "THEO constructor,just professor\n";
    professor = profes;
}  

float Theorical::calculate_final()
{
    std::cout << "calculating final score in Theorical ER\n";
    final =  (8*final_exam+8*mid_term+4*homeWorks)/20 ;
    return final;            
}

void Theorical::scoring(float mid_term,float final_exam,float homeWorks,int absences)
{
    std::cout << "scoring in theorical\n";
    this->mid_term = mid_term;
    this->final_exam = final_exam;
    this->homeWorks = homeWorks;
    this->absences = absences;
    calculate_final();
    professor->scores.push_back(final);
    if(final>=10 and final<=20)
        passed=true;
}