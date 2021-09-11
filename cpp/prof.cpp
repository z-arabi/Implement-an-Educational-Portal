#include "prof.h"

Prof::Prof(std::string first_name,std::string last_name,int id):Person{}
{
    // std::cout << "prof constructor,items\n";
    this->first_name = first_name;
    this->last_name = last_name;
    this->id = id;
}

Prof::Prof(Prof& p): Prof(p.first_name,p.last_name,p.id)
{
    // std::cout << "prof copy constructor\n";
    scores = p.scores; // the vector type will be copied without problem
}

float Prof::get_mean()
{            
    float sum{};
    for(size_t i{};i<scores.size();i++)
    {
        sum += scores[i];
    }
    return sum/scores.size();
}