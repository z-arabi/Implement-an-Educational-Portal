#include <limits.h>
#include "prof.h"
#include "student.h"
#include "er.h"
#include "lab.h"
#include "theorical.h"
#include "course.h"
#include "person.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "gtest/gtest.h"
namespace
{

TEST(APHW4Test,mytest0)
{
    Prof prof1("Amir","Jahanshahi",1);
    Student s1("Albert","einstein",1,18.00,80);
    Student s2("Maryam","Mirzakhani",2,18.3,85);
    Student s3("Steven","Hawking",3,16.5,110);
    Theorical t1,t2,t3,t4,t5,t24;
    Lab t11,t12,t13,t14;
    Course AP(&prof1,"AP",3,1);
    AP(s1,t1,1);
    AP(s2,t2,1);
    AP(s3,t3,1);
    t1.scoring(19,10,9,2);
    t2.scoring(12,20,0,1);
    t3.scoring(15,15,15,2);
    t1.calculate_final();
    t2.calculate_final();
    t3.calculate_final();
    std::cout << t1.final << " t1 final\n"; //13.4
    std::cout << t2.final << " t2 final\n"; //12.8
    std::cout << t3.final << " t3 final\n"; //15
    std::cout << t3.final << " t3 final\n"; //15
    std::cout << AP.population << " AP.population\n"; //3
    std::cout << prof1.get_mean() << " prof mean course\n"; //13.73
    Student s4("zahra","arabi",4,14.5,120);
    AP(s4,t4,1);
    t4.scoring(10,10,10,0);
    t4.calculate_final();
    std::cout << t4.final << " t4 final\n"; //10
    std::cout << AP.population << " AP.population\n"; //4
    std::cout << prof1.get_mean() << " prof mean course\n"; //12.8
    std::cout << prof1.n_classes << " prof classes------------\n"; //1
    Course labAP(&prof1,"labAP",1,0);
    labAP(s1,t11,1);
    labAP(s2,t12,1);
    labAP(s3,t13,1);
    labAP(s4,t14,1);
    t11.scoring(9,10,19,2);
    t12.scoring(12,20,10,1);
    t13.scoring(15,15,15,2);
    t14.scoring(20,10,10,0);
    t11.calculate_final();
    t12.calculate_final();
    t13.calculate_final();
    t14.calculate_final();
    std::cout << t11.final << " t11 final\n"; //14.1
    std::cout << t12.final << " t12 final\n"; //11.8
    std::cout << t3.final << " t13 final\n"; //15
    std::cout << t14.final << " t14 final\n"; //14
    std::cout << labAP.population << " labAP.population\n"; //3
    std::cout << labAP.average() << " labAP.average\n"; //13.3
    std::cout << prof1.get_mean() << " prof mean course\n"; //13
    for(int i{};i<prof1.scores.size();i++)
    {
        std::cout << prof1.scores[i] << " * ";
    }
    std::cout << "\n";
    // std::cout << s4.n_classes << " s4 classes\n";
    // for(int i{};i<s4.n_classes;i++)
    // {
    //     std::cout << s4.courses[i]->name << " * ";
    // }
    // std::cout << "\n";
    // for(int i{};i<s4.n_theo;i++)
    // {
    //     std::cout << s4.theoric_er[i]->calculate_final() << " * ";
    // }
    // std::cout << "\n";
    // AP(s4,t4,0);
    // std::cout << s4.n_classes << " s4 classes\n";
    // for(int i{};i<s4.n_classes;i++)
    // {
    //     std::cout << s4.courses[i]->name << " * ";
    // }
    // std::cout << "\n";
    // for(int i{};i<s4.n_theo;i++)
    // {
    //     std::cout << s4.theoric_er[i]->calculate_final() << " * ";
    // }
    // std::cout << "\n";

    Prof prof2("s","h",2);
    Course OS(&prof2,"os",3,1);
    OS(s4,t24,1);
    t24.scoring(9,10,19,2);
    std::cout << t24.calculate_final() << "\n"; //11.4
    std::cout << OS.population << " OS.population\n"; //1
    std::cout << OS.average() << " OS.average\n"; //11.4
    std::cout << prof2.get_mean() << " prof mean course\n"; //11.4

    std::cout << s4.n_classes << " s4 classes\n";
    for(int i{};i<s4.n_classes;i++)
    {
        std::cout << s4.courses[i]->name << " * ";
    }
    std::cout << "\n";
    for(int i{};i<s4.n_theo;i++)
    {
        std::cout << s4.theoric_er[i]->calculate_final() << " * ";
    }
    std::cout << "\n";
    AP(s4,t4,0);
    std::cout << s4.n_classes << " s4 classes\n";
    for(int i{};i<s4.n_classes;i++)
    {
        std::cout << s4.courses[i]->name << " * ";
    }
    std::cout << "\n";
    for(int i{};i<s4.n_theo;i++)
    {
        std::cout << s4.theoric_er[i]->calculate_final() << " * ";
    }
    std::cout << "----------\n";
    labAP(s1,t11,0);
    for(int i{};i<s1.n_lab;i++)
    {
        std::cout << s1.lab_er[i]->calculate_final() << " * ";
    }
    std::cout << "\n";
}

TEST(APHW4Test,InitiAmirzing0)
{
    Prof prof1("Amir","Jahanshahi",1);
    Student s1("Albert","einstein",1,18.00,80);
    Student s2("Maryam","Mirzakhani",2,18.3,85);
    Student s3("Steven","Hawking",3,16.5,110);
    Theorical t1,t2,t3,t4,t5;
    Course AP(&prof1,"AP",3,1);
    AP(s1,t1,1);
    AP(s2,t2,1);
    AP(s3,t3,1);
    t1.scoring(18,18,18,2);
    t2.scoring(12,12,12,1);
    t3.scoring(15,15,15,2);
    t1.calculate_final();
    t2.calculate_final();
    t3.calculate_final();
    EXPECT_EQ(18,t1.final);
    EXPECT_EQ(12,t2.final);
    EXPECT_EQ(15,t3.final);
}

TEST(APHW4Test,virtual_calculate_final_test1)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  t1.scoring(18,18,18,2);
  t2.scoring(12,12,12,1);
  t3.scoring(15,15,15,2);
  ER* test_er{&t1};
  test_er->calculate_final();
  EXPECT_EQ(18,test_er->final);
  test_er = &t2;
  test_er->calculate_final();
  EXPECT_EQ(12,test_er->final);
  test_er = &t3;
  test_er->calculate_final();
  EXPECT_EQ(15,test_er->final);
}

TEST(APHW4Test,max_test2)
{
  // Prof prof1("Amir","Jahanshahi",1);
  // Student s1("Albert","einstein",1,18.00,80);
  // Theorical t1;
  // Course AP(&prof1,"AP",3,1);
  // AP(s1,t1,1);

  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  t1.scoring(18,18,18,2);
  t2.scoring(12,12,12,1);
  t3.scoring(15,15,15,2);
  for(int i{};i<AP.population;i++)
  {
    std::cout << AP.educational_reports[i]->calculate_final() << " inloop\n";
  }
  EXPECT_EQ(18,AP.max());
}

TEST(APHW4Test,average_test3)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("Steven","Hawking",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }
  EXPECT_EQ(15,AP.average());
}

TEST(APHW4Test,max_test4)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Student s4("Steven","Hawking",5,18.7,112);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }
  EXPECT_EQ(18,AP.max());
  AP(s4,t4,1);
  t4.scoring(19,19,19,2);
  t4.calculate_final();
  EXPECT_EQ(19,AP.max());
}

TEST(APHW4Test,max_test5)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);

  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }

  AP(s3,t3,-1);
  EXPECT_EQ(15,AP.max());
}

TEST(APHW4Test,get_mean6)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  std::cout <<"**\n";
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  std::cout <<"****\n";
  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }
  Person* p1{&prof1};
  EXPECT_EQ(15,p1->get_mean());
  std::cout << "last\n";
  p1 = &s1;
  std::cout << "out\n";
  EXPECT_EQ(18,p1->get_mean());
}

}
