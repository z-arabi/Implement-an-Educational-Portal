#ifndef PROF_H
#define PROF_H

#include "vector"

#include "person.h"
class Course;

class Prof : public Person
{
    public:
        Prof(std::string first_name,std::string last_name,int id);
        Prof():Prof("","",0){}
        Prof(Prof& p);
        ~Prof(){}
        float get_mean();  // Each of professor's courses has mean. This function returns mean of those means.

        std::vector<float> scores{};
};

#endif