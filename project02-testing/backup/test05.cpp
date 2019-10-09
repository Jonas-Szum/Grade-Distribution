/*test05.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const College& college, int& DFW, int& N);
// Decimal DFW rate
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 05", "[Project01]" ) 
{ 
College decimalCollege("DecimalCollege");
Dept decimalDept("Decimal");
int DFWforD; 
int NforD;
double supposedDecimal; //.57317 * 100 = 57.317 
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
             /*A-F*/ 5, 12, 19, 0, 0,
             /*I,S,U,W,NR*/ 3, 0, 0, 0, 20);
Course Zero2("ZER", "A$AP Yam", 502, 01, "Theys",
             /*A-F*/ 12, 9, 26, 0, 0, 
             /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
zeroDept.Courses.push_back(Zero1);
zeroDept.Courses.push_back(Zero2);

Dept hundoDept("Hundo");
Course Hundo1("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 10, 5,
             /*I,S,U,W,NR*/ 3, 0, 0, 12, 20);
Course Hundo2("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 12, 20,
             /*I,S,U,W,NR*/ 0, 0, 0, 17, 0);
hundoDept.Courses.push_back(Hundo1);
hundoDept.Courses.push_back(Hundo2);

decimalCollege.Depts.push_back(decimalDept);
decimalCollege.Depts.push_back(zeroDept);
decimalCollege.Depts.push_back(hundoDept);

supposedDecimal = GetDFWRate(decimalCollege, DFWforD, NforD);
REQUIRE(DFWforD == 142);
REQUIRE(NforD == 292);
REQUIRE(abs(supposedDecimal - 48.63) < .01);


}
