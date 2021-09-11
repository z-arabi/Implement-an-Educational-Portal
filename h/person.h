#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Course;
class ER;
class Theorical;
class Lab;

class Person
{
    public:
        Person();
        Person(Person& p);
        ~Person();
        virtual float get_mean(){ return 0; };
        void add_course(Course* course);
        void remove_course(Course* course);
        
        std::string first_name;
        std::string last_name;
        int id;   // id of person(for example for students it's student number)
        int n_classes{};  // number of person's courses    
        Course** courses; // a set of pointers to person's courses
};

#endif