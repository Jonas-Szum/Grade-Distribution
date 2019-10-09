/*test08.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: GradeStats GetGradeDistribution(const Course& c);
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


TEST_CASE( "Test 08", "[Project01]" ) 
{
Course NoZero("CS", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 5, 10, 20, 40, 3,
             /*I,S,U,W,NR*/ 7, 0, 0, 4, 1); 
GradeStats NoZeroStats = GetGradeDistribution(NoZero);
REQUIRE(NoZeroStats.N == 78);
REQUIRE(NoZeroStats.NumA == 5);
REQUIRE(NoZeroStats.NumB == 10);
REQUIRE(NoZeroStats.NumC == 20);
REQUIRE(NoZeroStats.NumD == 40);
REQUIRE(NoZeroStats.NumF == 3);
REQUIRE(abs(NoZeroStats.PercentA - 6.41) < .01);
REQUIRE(abs(NoZeroStats.PercentB - 12.82) < .01);
REQUIRE(abs(NoZeroStats.PercentC - 25.64) < .01);
REQUIRE(abs(NoZeroStats.PercentD - 51.28) < .01);
REQUIRE(abs(NoZeroStats.PercentF - 3.84) < .01);

Course ZeroA("PHYS", "A$AP Ferg", 501, 01, "Hallenbeck",
             /*A-F*/ 0, 21, 8, 10, 5,
             /*I,S,U,W,NR*/ 3, 0, 0, 12, 20); 
GradeStats ZeroAStats = GetGradeDistribution(ZeroA); 
REQUIRE(ZeroAStats.N == 44);
REQUIRE(ZeroAStats.NumA == 0);
REQUIRE(ZeroAStats.NumB == 21);
REQUIRE(ZeroAStats.NumC == 8);
REQUIRE(ZeroAStats.NumD == 10);
REQUIRE(ZeroAStats.NumF == 5);
REQUIRE(abs(ZeroAStats.PercentA - 0) < .01);
REQUIRE(abs(ZeroAStats.PercentB - 47.72) < .01);
REQUIRE(abs(ZeroAStats.PercentC - 18.18) < .01);
REQUIRE(abs(ZeroAStats.PercentD - 22.72) < .01);
REQUIRE(abs(ZeroAStats.PercentF - 11.36) < .01);

Course PassFail("SOC", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 3, 50, 12, 0, 20); 
GradeStats PassFailStats = GetGradeDistribution(PassFail);
REQUIRE(PassFailStats.N == 0);
REQUIRE(PassFailStats.NumA == 0);
REQUIRE(PassFailStats.NumB == 0);
REQUIRE(PassFailStats.NumC == 0);
REQUIRE(PassFailStats.NumD == 0);
REQUIRE(PassFailStats.NumF == 0);
REQUIRE(abs(PassFailStats.PercentA - 0) < .01);
REQUIRE(abs(PassFailStats.PercentB - 0) < .01);
REQUIRE(abs(PassFailStats.PercentC - 0) < .01);
REQUIRE(abs(PassFailStats.PercentD - 0) < .01);
REQUIRE(abs(PassFailStats.PercentF - 0) < .01);
}
