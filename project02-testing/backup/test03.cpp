/*test03.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const Course& c, int& DFW, int& N);
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


TEST_CASE( "Test 03", "[Project01]" ) 
{
int DFWforD; // should be 47
int NforD; // should be 82
double supposedDecimal; //.57317 * 100 = 57.317
Course Decimal("CS", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 5, 10, 20, 40, 3,
             /*I,S,U,W,NR*/ 7, 0, 0, 4, 1); 

supposedDecimal = GetDFWRate(Decimal, DFWforD, NforD);

REQUIRE(DFWforD == 47);
REQUIRE(NforD == 82);
REQUIRE(abs(supposedDecimal - 57.317) < .01);


int DFWforZ;
int NforZ;
double supposedZero; //should be 0
Course ZeroRate("SOC", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 5, 12, 19, 0, 0,
             /*I,S,U,W,NR*/ 3, 0, 0, 0, 20); 

supposedZero = GetDFWRate(ZeroRate, DFWforZ, NforZ);

REQUIRE(DFWforZ == 0);
REQUIRE(NforZ == 36);
REQUIRE(abs(supposedZero - 0) < .01); //don't need - 0, but leave it in for clarity


int DFWforH;
int NforH;
double supposedHundo; // should be 100.0
Course Hundo("PHYS", "A$AP Ferg", 501, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 10, 5,
             /*I,S,U,W,NR*/ 3, 0, 0, 12, 20);

supposedHundo = GetDFWRate(Hundo, DFWforH, NforH);

REQUIRE(DFWforH == 27);
REQUIRE(NforH == 27);
REQUIRE(abs(supposedHundo - 100) < .01);
}
