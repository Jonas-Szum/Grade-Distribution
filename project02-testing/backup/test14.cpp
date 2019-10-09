/*test14.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: vector<Course> FindCourses(const College& college, int courseNumber);
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


TEST_CASE( "Test 14", "[Project01]" ) 
{ 
College decimalCollege("DecimalCollege");
Dept decimalDept("Decimal");
Course Decimal1("DEC", "Soulja Boy", 505, 02, "Hummel",
             /*A-F*/ 5, 10, 20, 40, 3,
             /*I,S,U,W,NR*/ 7, 0, 0, 4, 1); 
Course Decimal2("DEC", "Tay-K", 506, 01, "Hummus",
             /*A-F*/ 3, 12, 17, 8, 5,
             /*I,S,U,W,NR*/ 2, 0, 0, 6, 0);
decimalDept.Courses.push_back(Decimal1);
decimalDept.Courses.push_back(Decimal2);

Course Zero1("ZER", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 5, 12, 19, 5, 6,
             /*I,S,U,W,NR*/ 3, 0, 0, 0, 20);
Course Zero2("ZER", "A$AP Yam", 502, 01, "Theyman",
             /*A-F*/ 0, 0, 0, 0, 0, 
             /*I,S,U,W,NR*/ 0, 55, 12, 0, 0);
decimalDept.Courses.push_back(Zero1);
decimalDept.Courses.push_back(Zero2);

Dept hundoDept("Hundo");
Course Hundo1("HUN", "Eminem", 501, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 3, 42, 21, 2, 20);
Course Hundo2("HUN", "Token", 505, 01, "Hummel",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 60, 5, 17, 0);
hundoDept.Courses.push_back(Hundo1);
hundoDept.Courses.push_back(Hundo2);

decimalCollege.Depts.push_back(hundoDept);
decimalCollege.Depts.push_back(decimalDept);

vector<Course> interCollege = FindCourses(decimalCollege, 505);
REQUIRE(interCollege.size() == 2);
REQUIRE(interCollege[0].Title == "Soulja Boy");
REQUIRE(interCollege[1].Title == "Token");

vector<Course> interCollege2 = FindCourses(decimalCollege, "Hum");
REQUIRE(interCollege2.size() == 3);
REQUIRE(interCollege2[1].Title == "Soulja Boy");
REQUIRE(interCollege2[2].Title == "Tay-K");
REQUIRE(interCollege2[0].Title == "Token");

REQUIRE(FindCourses(decimalCollege, 510).size() == 0);
REQUIRE(FindCourses(decimalCollege, "Hummus2").size() == 0);


}
