#ifndef THEO_H
#define THEO_H

#include "er.h"
class Course;

class Theorical : public ER
{
    public:
        Theorical(Course* cours,Student* stud,Prof* profes,int wight);
        Theorical(Prof* profes);
        Theorical():Theorical(0,0,0,0){}
        ~Theorical(){}
        float calculate_final() override; // 8 points for final exam,8 points for mid_term,4 points for homeWorks
        void scoring(float mid_term,float final_exam,float homeWorks,int absences) override;

        float mid_term;
        float final_exam;
        float homeWorks;
};

#endif