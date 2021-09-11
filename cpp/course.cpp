#include "course.h"

Course::Course(Prof* profesor,std::string name,int weight,bool theorical):professor{profesor},name{name},weight{weight},theorical{theorical}
{
    // std::cout << "course constructor,to define a course\n";
    population = 0;
    educational_reports = new ER*[population];
    professor->add_course(this);
    students = new Student*[population];
}

Course::Course(Prof* profesor,Student* student,std::string name,int weight,bool theorical):Course(profesor,name,weight,theorical)
{
    // std::cout << "course constructor,a student takes this course\n";
    population = 1 ;
    delete[] students;
    delete[] educational_reports;
    educational_reports = new ER*[population];
    professor->n_classes += 1;
    professor->add_course(this);
    students = new Student*[population];
    student->n_classes += 1;
    student->add_course(this);
    if (theorical)
    {
        Theorical theo(this,student,professor,weight);
        student->add_theo_course(&theo);
    }else
    {
        Lab lab(this,student,professor,weight);
        student->add_lab_course(&lab);
    }
               
}

Course::~Course()
{
    // std::cout << "course destructor\n";
    delete[] educational_reports;
    delete[] students;
}

bool Course::operator<(const Course& course)
{
    if(population<course.population)
        return true;
    return false;
}

bool Course::operator=(const Course& course)
{
    if(population == course.population)
        return true;
    return false;
}

void Course::operator()(Student& student,Theorical& theo,int option)
{
    Theorical theo_er(this,&student,professor,weight);
    theo = theo_er;
    if(option)
    {
        // add student to the course
        population += 1;
        ER** educational_reports_m = new ER*[population];
        for(int i{};i<population-1;i++)
        {
            educational_reports_m[i]=educational_reports[i];
        }
        educational_reports_m[population-1]=&theo;
        
        Student** students_m = new Student*[population];
        for(int i{};i<population-1;i++)
        {
            students_m[i]=students[i];
        }
        students_m[population-1]=&student;

        delete[] students;
        delete[] educational_reports;
        educational_reports = new ER*[population];
        students = new Student*[population];
        educational_reports = educational_reports_m;
        students = students_m;

        student.add_course(this);
        student.add_theo_course(&theo);
    }else
    {
        // remove student from class
        student.remove_course(this);
        student.remove_theo_course(&theo);

        int ind{};
        for(int i{};i<population;i++)
        {
            if(*(students[i]) == student)
            {
                ind = i;
                break;
            }
        }
        population -= 1;
        ER** educational_reports_m = new ER*[population];
        for(int i{};i<ind;i++)
        {
            educational_reports_m[i]=educational_reports[i];
        }
        for(int i{ind+1};i<population+1;i++)
        {
            educational_reports_m[i-1]=educational_reports[i];
        }
        delete[] educational_reports;
        educational_reports = new ER*[population];
        educational_reports = educational_reports_m;   

        Student** students_m = new Student*[population];
        for(int i{};i<ind;i++)
        {
            students_m[i]=students[i];
        }
        for(int i{ind+1};i<population+1;i++)
        {
            students_m[i-1]=students[i];
        }
        delete[] students;
        students = new Student*[population];
        students = students_m;
    }           
} 

void Course::operator()(Student& student,Lab& lab,int option)
{
    Lab lab_er(this,&student,professor,weight);
    lab = lab_er;
    if(option)
    {
        // add student to the course
        population += 1;
        ER** educational_reports_m = new ER*[population];
        for(int i{};i<population-1;i++)
        {
            educational_reports_m[i]=educational_reports[i];
        }
        educational_reports_m[population-1]=&lab;
        
        Student** students_m = new Student*[population];
        for(int i{};i<population-1;i++)
        {
            students_m[i]=students[i];
        }
        students_m[population-1]=&student;

        delete[] students;
        delete[] educational_reports;
        educational_reports = new ER*[population];
        students = new Student*[population];
        educational_reports = educational_reports_m;
        students = students_m;

        student.add_course(this);
        student.add_lab_course(&lab);
    }else
    {
        // remove student from class
        student.remove_course(this);
        student.remove_lab_course(&lab);

        int ind{};
        for(int i{};i<population;i++)
        {
            if(*(students[i]) == student)
            {
                ind = i;
                break;
            }
        }
        population -= 1;
        ER** educational_reports_m = new ER*[population];
        for(int i{};i<ind;i++)
        {
            educational_reports_m[i]=educational_reports[i];
        }
        for(int i{ind+1};i<population+1;i++)
        {
            educational_reports_m[i-1]=educational_reports[i];
        }
        delete[] educational_reports;
        educational_reports = new ER*[population];
        educational_reports = educational_reports_m;   

        Student** students_m = new Student*[population];
        for(int i{};i<ind;i++)
        {
            students_m[i]=students[i];
        }
        for(int i{ind+1};i<population+1;i++)
        {
            students_m[i-1]=students[i];
        }
        delete[] students;
        students = new Student*[population];
        students = students_m;
    }           
}

float Course::max()
{
    float max{},mid{};
    for(int i{};i<population;i++)
    {
        mid = educational_reports[i]->calculate_final();
        if(mid > max)
            max = mid;
    }
    return max;
}

float Course::average()
{
    float sum{};
    for(int i{};i<population;i++)
    {
        float final = educational_reports[i]->calculate_final();  
        sum += final;
    }
    return sum/population;
}