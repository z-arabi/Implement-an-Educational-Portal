#include "person.h"

Person::Person()
{
    // std::cout << "person constructor\n";
    id = 0;
    first_name = {};
    last_name = {};
    courses = new Course*[n_classes];
}

Person::Person(Person& p)
{
    id = p.id;
    first_name = p.first_name;
    last_name = p.last_name;
    n_classes = p.n_classes;
    courses = new Course*[n_classes];
    for (int i{};i<n_classes;i++)
    {
        courses[i] = p.courses[i];
    }
}

Person::~Person()
{
    // std::cout << "person destructor\n";
    delete[] courses;
}

void Person::add_course(Course* course)
{
    n_classes += 1;
    Course** courselist = new Course*[n_classes];
    for(int i{};i<n_classes-1;i++)
    {
        courselist[i]=courses[i];
    }
    courselist[n_classes-1] = course;
    delete[] courses;
    courses = new Course*[n_classes];
    courses = courselist;
}

void Person::remove_course(Course* course)
{
    int ind{};
    for(int i{};i<n_classes;i++)
    {
        if(courses[i] == course)
        {
            ind = i;
            std::cout << ind << " ind is\n";
            break;
        }
    }
    n_classes -= 1;
    Course** courselist = new Course*[n_classes];
    for(int i{};i<ind;i++)
    {
        courselist[i]=courses[i];
    }
    for(int i{ind+1};i<n_classes+1;i++)
    {
        courselist[i-1]=courses[i];
    }
    delete[] courses;
    courses = new Course*[n_classes];
    courses = courselist;
}