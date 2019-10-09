/*test12.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: vector<Course> FindCourses(const Dept& dept, int courseNumber);
//
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 12", "[Project01]" )
{ 
Dept myDept("Decimal");
Course Decimal1("DEC", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 5, 10, 15, 10, 5,
             /*I,S,U,W,NR*/ 7, 38, 13, 4, 1);
Course Decimal2("DEC", "Tay-K", 500, 02, "Hummus",
             /*A-F*/ 25, 20, 15, 10, 5,
             /*I,S,U,W,NR*/ 2, 92, 12, 6, 0);
Course Zero1("DEC", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 3, 45, 8, 0, 20);
Course Zero2("DEC", "A$AP Yam", 502, 01, "Theyman",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 55, 12, 0, 0);
Course Hundo1("DEC", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 10, 15, 20, 25, 30,
             /*I,S,U,W,NR*/ 3, 0, 0, 2, 20);
Course Hundo2("DEC", "Token", 402, 01, "Hal9000",
             /*A-F*/ 30, 23, 15, 3, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 17, 0);
myDept.Courses.push_back(Hundo2);
myDept.Courses.push_back(Hundo1);
myDept.Courses.push_back(Zero2);
myDept.Courses.push_back(Zero1);
myDept.Courses.push_back(Decimal2);
myDept.Courses.push_back(Decimal1);
vector<Course> sizeTwo = FindCourses(myDept, 500);
REQUIRE(sizeTwo.size() == 2);
REQUIRE(sizeTwo[0].Instructor == "Hummel");
REQUIRE(sizeTwo[1].Instructor == "Hummus");

vector<Course> emptyVec = FindCourses(myDept, 300);
REQUIRE(emptyVec.size() == 0);
}
