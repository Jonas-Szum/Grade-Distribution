/*test11.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: GradeStats GetGradeDistribution(const College& college);
// mixed grade distribution rate (one Dept all letter grades, one half&half, one all P/F)
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 11", "[Project01]" ) 
{ 
College decimalCollege("DecimalCollege");
Dept decimalDept("Decimal");
Course Decimal1("DEC", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 5, 10, 20, 40, 3,
             /*I,S,U,W,NR*/ 7, 0, 0, 4, 1); 
Course Decimal2("DEC", "Tay-K", 505, 01, "Hummel",
             /*A-F*/ 3, 12, 17, 8, 5,
             /*I,S,U,W,NR*/ 2, 0, 0, 6, 0);
decimalDept.Courses.push_back(Decimal1);
decimalDept.Courses.push_back(Decimal2);

Dept zeroDept("Zero");
Course Zero1("ZER", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 5, 12, 19, 5, 6,
             /*I,S,U,W,NR*/ 3, 0, 0, 0, 20);
Course Zero2("ZER", "A$AP Yam", 502, 01, "Theys",
             /*A-F*/ 0, 0, 0, 0, 0, 
             /*I,S,U,W,NR*/ 0, 55, 12, 0, 0);
zeroDept.Courses.push_back(Zero1);
zeroDept.Courses.push_back(Zero2);

Dept hundoDept("Hundo");
Course Hundo1("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 3, 42, 21, 2, 20);
Course Hundo2("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 60, 5, 17, 0);
hundoDept.Courses.push_back(Hundo1);
hundoDept.Courses.push_back(Hundo2);

decimalCollege.Depts.push_back(decimalDept); //pure letters
decimalCollege.Depts.push_back(zeroDept); //mixed
decimalCollege.Depts.push_back(hundoDept); //pure pass/fail

GradeStats deci = GetGradeDistribution(decimalCollege);
REQUIRE(deci.N == 170);
REQUIRE(deci.NumA == 13);
REQUIRE(deci.NumB == 34);
REQUIRE(deci.NumC == 56);
REQUIRE(deci.NumD == 53);
REQUIRE(deci.NumF == 14);
REQUIRE(abs(deci.PercentA - 7.64) < .01);
REQUIRE(abs(deci.PercentB - 20) < .01);
REQUIRE(abs(deci.PercentC - 32.94) < .01);
REQUIRE(abs(deci.PercentD - 31.17) < .01);
REQUIRE(abs(deci.PercentF - 8.23) < .01);

}
