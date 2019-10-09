/*test09.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: GradeStats GetGradeDistribution(const Dept& dept);
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


TEST_CASE( "Test 09", "[Project01]" ) 
{ 

Dept decimalDept("Decimal");
Course Decimal1("DEC", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 5, 10, 20, 40, 3,
             /*I,S,U,W,NR*/ 7, 0, 0, 4, 1); 
Course Decimal2("DEC", "Tay-K", 505, 01, "Hummel",
             /*A-F*/ 3, 12, 17, 8, 5,
             /*I,S,U,W,NR*/ 2, 0, 0, 6, 0);
decimalDept.Courses.push_back(Decimal1);
decimalDept.Courses.push_back(Decimal2);
GradeStats deci = GetGradeDistribution(decimalDept);
REQUIRE(deci.N == 123);
REQUIRE(deci.NumA == 8);
REQUIRE(deci.NumB == 22);
REQUIRE(deci.NumC == 37);
REQUIRE(deci.NumD == 48);
REQUIRE(deci.NumF == 8);
REQUIRE(abs(deci.PercentA - 6.50) < .01);
REQUIRE(abs(deci.PercentB - 17.88) < .01);
REQUIRE(abs(deci.PercentC - 30.08) < .01);
REQUIRE(abs(deci.PercentD - 39.02) < .01);
REQUIRE(abs(deci.PercentF - 6.50) < .01);

Dept HalfDept("Half");
Course PassFail("ZER", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 3, 23, 42, 0, 20);
Course AThroughF("ZER", "A$AP Yam", 502, 01, "Theys",
             /*A-F*/ 12, 9, 26, 0, 4, 
             /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
HalfDept.Courses.push_back(PassFail);
HalfDept.Courses.push_back(AThroughF);
GradeStats Half = GetGradeDistribution(HalfDept);
REQUIRE(Half.N == 51);
REQUIRE(Half.NumA == 12);
REQUIRE(Half.NumB == 9);
REQUIRE(Half.NumC == 26);
REQUIRE(Half.NumD == 0);
REQUIRE(Half.NumF == 4);
REQUIRE(abs(Half.PercentA - 23.52) < .01);
REQUIRE(abs(Half.PercentB - 17.64) < .01);
REQUIRE(abs(Half.PercentC - 50.98) < .01);
REQUIRE(abs(Half.PercentD - 0) < .01);
REQUIRE(abs(Half.PercentF - 7.84) < .01);


Dept PFDept("PassFail"); 
Course PFCourse1("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 3, 32, 16, 12, 20);
Course PFCourse2("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 47, 0, 3, 0);
PFDept.Courses.push_back(PFCourse1);
PFDept.Courses.push_back(PFCourse2);
GradeStats None = GetGradeDistribution(PFDept);
REQUIRE(None.N == 0);
REQUIRE(None.NumA == 0);
REQUIRE(None.NumB == 0);
REQUIRE(None.NumC == 0);
REQUIRE(None.NumD == 0);
REQUIRE(None.NumF == 0);
REQUIRE(abs(None.PercentA - 0) < .01);
REQUIRE(abs(None.PercentB - 0) < .01);
REQUIRE(abs(None.PercentC - 0) < .01);
REQUIRE(abs(None.PercentD - 0) < .01);
REQUIRE(abs(None.PercentF - 0) < .01);

}
