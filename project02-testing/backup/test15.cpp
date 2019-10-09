/*test15.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases: double GetDFWRate(const College& college, int& DFW, int& N);
// undefined DFW rate
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;


TEST_CASE( "Test 15", "[Project01]" ) 
{ 
College hundoCollege("HundoCollege");
Dept HundoDept1("Hundo");
int DFWforH; 
int NforH;
double supposedHundo;
Course HundoC1("DEC", "Soulja Boy", 500, 01, "Hummel",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 5, 0); 
Course HundoC2("DEC", "Tay-K", 505, 01, "Hummel",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 10, 0);
HundoDept1.Courses.push_back(HundoC1);
HundoDept1.Courses.push_back(HundoC2);

Dept HundoDept2("Zero");
Course HundoC3("ZER", "A$AP Rocky", 501, 01, "Theys",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 3, 0);
Course HundoC4("ZER", "A$AP Yam", 502, 01, "Theys",
             /*A-F*/ 0, 0, 0, 0, 0, 
             /*I,S,U,W,NR*/ 0, 0, 0, 7, 0);
HundoDept2.Courses.push_back(HundoC3);
HundoDept2.Courses.push_back(HundoC4);

Dept HundoDept3("Hundo");
Course HundoC5("HUN", "Eminem", 401, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 6, 0);
Course HundoC6("HUN", "Token", 402, 01, "Hallenbeck",
             /*A-F*/ 0, 0, 0, 0, 0,
             /*I,S,U,W,NR*/ 0, 0, 0, 15, 0);
HundoDept3.Courses.push_back(HundoC5);
HundoDept3.Courses.push_back(HundoC6);

hundoCollege.Depts.push_back(HundoDept1);
hundoCollege.Depts.push_back(HundoDept2);
hundoCollege.Depts.push_back(HundoDept3);

supposedHundo = GetDFWRate(hundoCollege, DFWforH, NforH);
REQUIRE(DFWforH == 0);
REQUIRE(NforH == 0);
REQUIRE(abs(supposedHundo - 0) < .01);
}
