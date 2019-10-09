/*test06.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const College& college, int& DFW, int& N);
// Zero DFW rate
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 06", "[Project01]" ) 
{ 
College zeroCollege("ZeroCollege");
Dept ZeroDept1("Dept1");
int DFWforZ; 
int NforZ;
double supposedZero;
Course ZeroC1("DEC", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 5, 10, 20, 0, 0,
             /*I,S,U,W,NR*/ 7, 0, 0, 0, 1); 
Course ZeroC2("DEC", "Tay-K", 505, 01, "Hummel",
             /*A-F*/ 3, 12, 17, 0, 0,
             /*I,S,U,W,NR*/ 2, 0, 0, 0, 0);
ZeroDept1.Courses.push_back(ZeroC1);
ZeroDept1.Courses.push_back(ZeroC2);

Dept ZeroDept2("Dept2");
Course ZeroC3("ZER", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 5, 12, 19, 0, 0,
             /*I,S,U,W,NR*/ 3, 0, 0, 0, 20);
Course ZeroC4("ZER", "A$AP Yam", 502, 01, "Theys",
             /*A-F*/ 12, 9, 26, 0, 0, 
             /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
ZeroDept2.Courses.push_back(ZeroC3);
ZeroDept2.Courses.push_back(ZeroC4);

Dept ZeroDept3("Dept3");
Course ZeroC5("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 10, 12, 21, 0, 0,
             /*I,S,U,W,NR*/ 3, 0, 0, 0, 20);
Course ZeroC6("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 20, 14, 1, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
ZeroDept3.Courses.push_back(ZeroC5);
ZeroDept3.Courses.push_back(ZeroC6);

zeroCollege.Depts.push_back(ZeroDept1);
zeroCollege.Depts.push_back(ZeroDept2);
zeroCollege.Depts.push_back(ZeroDept3);

supposedZero = GetDFWRate(zeroCollege, DFWforZ, NforZ);
REQUIRE(DFWforZ == 0);
REQUIRE(NforZ == 228);
REQUIRE(abs(supposedZero - 0) < .01);
}
