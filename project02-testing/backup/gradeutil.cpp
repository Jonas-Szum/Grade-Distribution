/*gradeutil.cpp*/

//
// <<Jonas Szum>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #02: GradeUtil API
// 

#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "gradeutil.h"

using namespace std;


//
// API:
//
/*
 * Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
 * / *A-F* / 0, 0, 0, 0, 0, 
 * / *I,S,U,W,NR* / 2, 88, 0, 0, 1);
 * 
 * 
 */
// 
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
bool commaPred(char myStr) {return myStr == ',';}

Course ParseCourse(string csvline)
{
  string::iterator strBegin;
  string::iterator strEnd;
  
  strBegin = csvline.begin();
  strEnd = find_if(csvline.begin(), csvline.end(), commaPred);
  string department(strBegin, strEnd);

  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValNum(strBegin, strEnd);
  int number = stoi(strValNum);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValSec(strBegin, strEnd);
  int section = stoi(strValSec);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string title(strBegin, strEnd);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValA(strBegin, strEnd);
  int numA = stoi(strValA);
  
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValB(strBegin, strEnd);
  int numB = stoi(strValB);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValC(strBegin, strEnd);
  int numC = stoi(strValC);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValD(strBegin, strEnd);
  int numD = stoi(strValD);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValF(strBegin, strEnd);
  int numF = stoi(strValF);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValI(strBegin, strEnd);
  int numI = stoi(strValI);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValNR(strBegin, strEnd);
  int numNR = stoi(strValNR);
  
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValS(strBegin, strEnd);
  int numS = stoi(strValS);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValU(strBegin, strEnd);
  int numU = stoi(strValU);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string strValW(strBegin, strEnd);
  int numW = stoi(strValW);
    
  strBegin = strEnd + 1;
  strEnd = find_if(strBegin, csvline.end(), commaPred);
  string instructor(strBegin, strEnd);  
    
  //Course myCourse
  return Course(department, title, number, section, instructor, 
                numA, numB, numC, numD, numF,
                numI, numS, numU, numW, numNR);
}


//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N)
{
  DFW = 0.0;
  N   = 0.0;
  

  if(c.getGradingType() != 0 )//enum Letter = 0
      return 0.0;
  else
  {
      DFW += c.NumD + c.NumF + c.NumW;
      N += c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
      return (DFW/(double)N)*100.0;
  }
}

double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;

  for(const Course& c : dept.Courses)
  {
      if(c.getGradingType() == 0 ) //Letter = 0
      {
          DFW += c.NumD + c.NumF + c.NumW;
          N += c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
      }
  }
  if(N > 0)
  {
      return (DFW/(double)N)*100.0;
  }
  return 0.0;
}

double GetDFWRate(const College& college, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
  double total = 0.0;
  
  for(const Dept& dept : college.Depts)
  {    
      for(const Course& c : dept.Courses)
      {
              if(c.getGradingType() == 0 ) //Letter = 0
          {
              DFW += c.NumD + c.NumF + c.NumW;
              N += c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
          }
      }
  }
  if(N > 0)
  {
      total = (DFW/(double)N)*100.0;
  } 
  return total;
}  


//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//GradeStats(int n, int numA, int numB, int numC, int numD, int numF, 
//           double percentA, double percentB, double percentC, double percentD, double percentF)
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
GradeStats GetGradeDistribution(const Course& c)
{
  if(c.getGradingType() != 0) //Letter = 0
      return GradeStats(0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0);
  int n = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
  int numA = c.NumA;
  int numB = c.NumB;
  int numC = c.NumC;
  int numD = c.NumD;
  int numF = c.NumF;
  double percentA = 100.0*numA/(double)n;
  double percentB = 100.0*numB/(double)n;
  double percentC = 100.0*numC/(double)n;
  double percentD = 100.0*numD/(double)n;
  double percentF = 100.0*numF/(double)n;
  return GradeStats(n, numA, numB, numC, numD, numF,
                    percentA, percentB, percentC, percentD, percentF);  
}

GradeStats GetGradeDistribution(const Dept& dept)
{
  int n = 0;
  int numA = 0;
  int numB = 0;
  int numC = 0;
  int numD = 0;
  int numF = 0;
  double percentA;
  double percentB;
  double percentC;
  double percentD;
  double percentF;
    
  for(const Course& c : dept.Courses)
  {
      n += c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
      numA += c.NumA;
      numB += c.NumB;
      numC += c.NumC;
      numD += c.NumD;
      numF += c.NumF;
  }
  if(n != 0)
  {
      percentA = 100.0*numA/(double)n;
      percentB = 100.0*numB/(double)n;
      percentC = 100.0*numC/(double)n;
      percentD = 100.0*numD/(double)n;
      percentF = 100.0*numF/(double)n;
      return GradeStats(n, numA, numB, numC, numD, numF,
                        percentA, percentB, percentC, percentD, percentF);
  }
  return GradeStats(0, 0, 0, 0, 0, 0,
                    0.0, 0.0, 0.0, 0.0, 0.0);
}

GradeStats GetGradeDistribution(const College& college)
{
  int n = 0;
  int numA = 0;
  int numB = 0;
  int numC = 0;
  int numD = 0;
  int numF = 0;
  double percentA;
  double percentB;
  double percentC;
  double percentD;
  double percentF;
  for(const Dept& dept : college.Depts)
  {
      for(const Course& c : dept.Courses)
      {
          n += c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
          numA += c.NumA;
          numB += c.NumB;
          numC += c.NumC;
          numD += c.NumD;
          numF += c.NumF;
      }
  }
  if(n != 0)
  {
      percentA = 100.0*numA/(double)n;
      percentB = 100.0*numB/(double)n;
      percentC = 100.0*numC/(double)n;
      percentD = 100.0*numD/(double)n;
      percentF = 100.0*numF/(double)n;
      return GradeStats(n, numA, numB, numC, numD, numF,
                        percentA, percentB, percentC, percentD, percentF);
  }
  return GradeStats(0, 0, 0, 0, 0, 0,
                    0.0, 0.0, 0.0, 0.0, 0.0);
  
}


//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
  vector<Course>  courses;
  
  for(const Course& course : dept.Courses)
  {
      if(course.Number == courseNumber)
          courses.push_back(course);
  }
  sort(courses.begin(), courses.end(),
               [](const Course& a, const Course& b)
               {
                    if(a.Number > b.Number) return false;
                    if(a.Number < b.Number) return true;
                    if(a.Number == b.Number && a.Section > b.Section) return false;
                    if(a.Number == b.Number && a.Section <= b.Section) return true;
                    return true;
               });
  return courses;
}


//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.
//
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
  
  vector<Course>  courses;
  int strLen = instructorPrefix.length();
  for(const Course& course : dept.Courses)
  {
      string temp = course.Instructor.substr(0, strLen);
      if(instructorPrefix == temp)
          courses.push_back(course);
  }
  sort(courses.begin(), courses.end(),
               [](const Course& a, const Course& b)
               {
                    if(a.Number > b.Number) return false;
                    if(a.Number < b.Number) return true;
                    if(a.Number == b.Number && a.Section > b.Section) return false;
                    if(a.Number == b.Number && a.Section <= b.Section) return true;
                    return true;
               });
  return courses;
}


//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, int courseNumber)
{
  vector<Course>  courses;
  for(const Dept& dept : college.Depts)
  {
      for(const Course& course : dept.Courses)
      {
          if(course.Number == courseNumber)
              courses.push_back(course);
      }
  }
  sort(courses.begin(), courses.end(),
               [](const Course& a, const Course& b)
               {
                    if(a.Dept.compare(b.Dept) > 0) return false;
                    if(a.Dept.compare(b.Dept) < 0) return true;
                    if(a.Dept.compare(b.Dept) == 0 && a.Number > b.Number) return false;
                    if(a.Dept.compare(b.Dept) == 0 && a.Number < b.Number) return true;
                    if(a.Dept.compare(b.Dept) == 0 && a.Number == b.Number && a.Section > b.Section) return false;
                    if(a.Dept.compare(b.Dept) == 0 && a.Number == b.Number && a.Section <= b.Section) return true;
                    return true;
               });
  
  return courses;
}


//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by instructor, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
  vector<Course>  courses;
  int strLen = instructorPrefix.length();
  for(const Dept& dept : college.Depts)
  {
      for(const Course& course : dept.Courses)
      {
          string temp = course.Instructor.substr(0, strLen);
          if(instructorPrefix == temp)
              courses.push_back(course);
      }
  }
  sort(courses.begin(), courses.end(),
               [](const Course& a, const Course& b)
               {
                    if(a.Instructor.compare(b.Instructor) > 0) return false;
                    if(a.Instructor.compare(b.Instructor) < 0) return true;
                    if(a.Instructor.compare(b.Instructor) == 0 && a.Number > b.Number) return false;
                    if(a.Instructor.compare(b.Instructor) == 0 && a.Number < b.Number) return true;
                    if(a.Instructor.compare(b.Instructor) == 0 && a.Number == b.Number && a.Section > b.Section) return false;
                    if(a.Instructor.compare(b.Instructor) == 0 && a.Number == b.Number && a.Section <= b.Section) return true;
                    return true;
               });
  return courses;
}
