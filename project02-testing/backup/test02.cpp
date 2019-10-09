/*test02.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: Course ParseCourse(string csvline);
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


TEST_CASE( "Test 02", "[Project01]" ) 
{
Course testCourse = ParseCourse("BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Bob");
REQUIRE(testCourse.Dept == "BIOE");
REQUIRE(testCourse.Title == "Intro to Bioengineering");
REQUIRE(testCourse.Number == 101);
REQUIRE(testCourse.Section == 01);
REQUIRE(testCourse.Instructor == "Bob");
REQUIRE(testCourse.NumA == 22);
REQUIRE(testCourse.NumB == 8);
REQUIRE(testCourse.NumC == 2);
REQUIRE(testCourse.NumD == 1);
REQUIRE(testCourse.NumF == 0);
REQUIRE(testCourse.NumI == 1);
REQUIRE(testCourse.NumS == 0);
REQUIRE(testCourse.NumU == 0);
REQUIRE(testCourse.NumW == 5);
REQUIRE(testCourse.NumNR == 0);
}
