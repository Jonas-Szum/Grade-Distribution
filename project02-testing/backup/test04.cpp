/*test04.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const Dept& dept, int& DFW, int& N);
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


TEST_CASE( "Test 04", "[Project01]" ) 
{ 

Dept decimalDept("Decimal");
int DFWforD;
int NforD;
double supposedDecimal;
Course Decimal1("DEC", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 5, 10, 20, 40, 3,
             /*I,S,U,W,NR*/ 7, 0, 0, 4, 1); 
Course Decimal2("DEC", "Tay-K", 505, 01, "Hummel",
             /*A-F*/ 3, 12, 17, 8, 5,
             /*I,S,U,W,NR*/ 2, 0, 0, 6, 0);
decimalDept.Courses.push_back(Decimal1);
decimalDept.Courses.push_back(Decimal2);
supposedDecimal = GetDFWRate(decimalDept, DFWforD, NforD); 
REQUIRE(DFWforD == 66); 
REQUIRE(NforD == 133);
REQUIRE(abs(supposedDecimal - 49.624) < .01);

Dept zeroDept("Zero");
int DFWforZ;
int NforZ;
double supposedZero; //should be 0
Course Zero1("ZER", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 5, 12, 19, 0, 0,
             /*I,S,U,W,NR*/ 3, 0, 0, 0, 20);
Course Zero2("ZER", "A$AP Yam", 502, 01, "Theys",
             /*A-F*/ 12, 9, 26, 0, 0, 
             /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
zeroDept.Courses.push_back(Zero1);
zeroDept.Courses.push_back(Zero2);
supposedZero = GetDFWRate(zeroDept, DFWforZ, NforZ);
REQUIRE(DFWforZ == 0);
REQUIRE(NforZ == 83);
REQUIRE(abs(supposedZero - 0) < .01); //don't need - 0, but leave it in for clarity

Dept hundoDept("Hundo");
int DFWforH;
int NforH;
double supposedHundo; // should be 100.0
Course Hundo1("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 10, 5,
             /*I,S,U,W,NR*/ 3, 0, 0, 12, 20);
Course Hundo2("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 12, 20,
             /*I,S,U,W,NR*/ 0, 0, 0, 17, 0);
hundoDept.Courses.push_back(Hundo1);
hundoDept.Courses.push_back(Hundo2);
supposedHundo = GetDFWRate(hundoDept, DFWforH, NforH); 
REQUIRE(DFWforH == 76);
REQUIRE(NforH == 76);
REQUIRE(abs(supposedHundo - 100) < .01);


Dept UDept("Undefined");
int DFWforU;
int NforU;
double supposedU; 
Course U1("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
Course U2("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
UDept.Courses.push_back(U1);
UDept.Courses.push_back(U2);
supposedU = GetDFWRate(UDept, DFWforU, NforU);
REQUIRE(DFWforU == 0);
REQUIRE(NforU == 0);
REQUIRE(abs(supposedU - 0) < .01);
}
