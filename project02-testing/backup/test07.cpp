/*test07.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const College& college, int& DFW, int& N);
// 100% DFW rate
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 07", "[Project01]" ) 
{ 
College hundoCollege("HundoCollege");
Dept HundoDept1("Hundo");
int DFWforH; 
int NforH;
double supposedHundo;
Course HundoC1("DEC", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 0, 0, 0, 40, 3,
             /*I,S,U,W,NR*/ 7, 0, 0, 4, 1); 
Course HundoC2("DEC", "Tay-K", 505, 01, "Hummel",
             /*A-F*/ 0, 0, 0, 8, 5,
             /*I,S,U,W,NR*/ 2, 0, 0, 6, 0);
HundoDept1.Courses.push_back(HundoC1);
HundoDept1.Courses.push_back(HundoC2);

Dept HundoDept2("Zero");
Course HundoC3("ZER", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 0, 0, 0, 15, 10,
             /*I,S,U,W,NR*/ 3, 0, 0, 5, 20);
Course HundoC4("ZER", "A$AP Yam", 502, 01, "Theys",
             /*A-F*/ 0, 0, 0, 6, 14, 
             /*I,S,U,W,NR*/ 0, 0, 0, 7, 0);
HundoDept2.Courses.push_back(HundoC3);
HundoDept2.Courses.push_back(HundoC4);

Dept HundoDept3("Hundo");
Course HundoC5("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 10, 5,
             /*I,S,U,W,NR*/ 3, 0, 0, 12, 20);
Course HundoC6("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 12, 20,
             /*I,S,U,W,NR*/ 0, 0, 0, 17, 0);
HundoDept3.Courses.push_back(HundoC5);
HundoDept3.Courses.push_back(HundoC6);

hundoCollege.Depts.push_back(HundoDept1);
hundoCollege.Depts.push_back(HundoDept2);
hundoCollege.Depts.push_back(HundoDept3);

supposedHundo = GetDFWRate(hundoCollege, DFWforH, NforH);
REQUIRE(DFWforH == 199);
REQUIRE(NforH == 199);
REQUIRE(abs(supposedHundo - 100) < .01);
}
