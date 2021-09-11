#include "student.h"

Student::Student(std::string first_name,std::string last_name,int id,float mean_score,int passed):Person{},mean_score{mean_score},passed{passed}
{
    // std::cout << "student constructor,items\n";
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
}

Student::Student(Student& s): Student(s.first_name,s.last_name,s.id,s.mean_score,s.passed)
{
    // std::cout << "student copy constructor\n";
    n_classes = s.n_classes;
    courses = new Course*[n_classes];
    for (int i{};i<n_classes;i++)
    {
        courses[i] = s.courses[i];
    }          
}

void Student::add_theo_course(Theorical* theo_course)
{
    n_theo += 1;
    Theorical** theoric_er_list = new Theorical*[n_theo];
    for(int i{};i<n_theo-1;i++)
    {
        theoric_er_list[i]=theoric_er[i];
    }
    theoric_er_list[n_theo-1] = theo_course;
    delete[] theoric_er;
    theoric_er = new Theorical*[n_theo];
    theoric_er = theoric_er_list;
}

void Student::remove_theo_course(Theorical* theo_course)
{
    int ind{};
    for(int i{};i<n_theo;i++)
    {
        if(theoric_er[i] == theo_course)
        {
            ind = i;
            std::cout << ind << " ind is\n";
            break;
        }
    }
    n_theo -= 1;
    Theorical** theoric_er_list = new Theorical*[n_theo];
    for(int i{};i<ind;i++)
    {
        theoric_er_list[i]=theoric_er[i];
    }
    for(int i{ind+1};i<n_theo+1;i++)
    {
        theoric_er_list[i-1]=theoric_er[i];
    }
    delete[] theoric_er;
    theoric_er = new Theorical*[n_theo];
    theoric_er = theoric_er_list;    
}

void Student::add_lab_course(Lab* lab_course)
{
    n_lab += 1;
    Lab** lab_er_list = new Lab*[n_lab];
    for(int i{};i<n_lab-1;i++)
    {
        lab_er_list[i]=lab_er[i];
    }
    lab_er_list[n_lab-1] = lab_course;
    delete[] lab_er;
    lab_er = new Lab*[n_lab];
    lab_er = lab_er_list;
}

void Student::remove_lab_course(Lab* lab_course)
{
    int ind{};
    for(int i{};i<n_lab;i++)
    {
        if(lab_er[i] == lab_course)
        {
            ind = i;
            std::cout << ind << " ind is\n";
            break;
        }
    }
    n_lab -= 1;
    Lab** lab_er_list = new Lab*[n_lab];
    for(int i{};i<ind;i++)
    {
        lab_er_list[i]=lab_er[i];
    }
    for(int i{ind+1};i<n_theo+1;i++)
    {
        lab_er_list[i-1]=lab_er[i];
    }
    delete[] lab_er;
    lab_er = new Lab*[n_lab];
    lab_er = lab_er_list;   
}

bool Student::operator!=(const Student& s)
{
    if (first_name == s.first_name && last_name == s.last_name && id == s.id)
        return false;
    return true;
}

bool Student::operator==(const Student& s)
{
    if (first_name == s.first_name && last_name == s.last_name && id == s.id)
        return true;
    return false;
}