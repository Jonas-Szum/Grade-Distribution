/*main.cpp*/

//
// Jonas Szum
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #03
// 
//


// gain access to Catch framework:
//#include "catch.hpp"
#include "gradeutil.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <sstream>

using std::cout; using std::endl; using std::vector;
using std::ifstream; using std::pair; using std::map;
using std::cin; using std::stringstream;
////using namespace std;

int getNumClasses(const Dept& myDept) 
  {
      return myDept.Courses.size();
  }
  
int getNumStudents(const Dept& myDept) 
  {
      int count = 0;
      for(const Course& myCourse : myDept.Courses)
          count += myCourse.getNumStudents();
      return count;
  }

int getNumClasses(const College& myCollege) 
  {
      int count = 0;
      for(const Dept& myDept : myCollege.Depts)
          count += myDept.Courses.size();
      return count;
  }
  
int getNumStudents(const College& myCollege) 
  {
  int count = 0;
      for(const Dept& myDept : myCollege.Depts)
          count += getNumStudents(myDept);
      return count;
  }
  
void mapToVec(const map<string, Dept>& myMap, vector<Dept>& myVec)
{
    for(const pair<string, Dept>& pairSD : myMap)
        myVec.push_back(pairSD.second); //pushes back a dept to the college array
}

/*
 * All functions take the college from main. They also take an iterator that
 * will be pointing to some element of the myCollege.Depts vector. If it
 * is not pointing to any element (if it's at the end), that means the user
 * selected "all"
 * 
 * Addendum: I had to add a bool deptFlag; because originally, I had searched for the department
 * in my main function. I cancelled the command if it wasn't found, but the autograder didn't like that
 * 
 */ 
 
/*
 * mySummary: prints the summary (number of students, number of courses, grade distribution, and DFW rate) 
 * of the given college, or a singular department
*/
void mySummary(const College& myCollege, const vector<Dept>::iterator& allIfEnd, const bool& deptFlag)
{   
    if(!deptFlag)
    {
        cout << "**dept not found" << endl;
        return;
    }
    if(allIfEnd == myCollege.Depts.end()) //if we use all departments
    {
        for(const Dept& myDept : myCollege.Depts)
        {
            cout << myDept.Name << ":" << endl;
            cout << " # courses taught: " << getNumClasses(myDept) << endl;
            cout << " # students taught: " << getNumStudents(myDept) << endl;
            GradeStats myStats = GetGradeDistribution(myDept);
            cout << " grade distribution (A-F): " << myStats.PercentA << "%, " << myStats.PercentB << "%, "
                                                  << myStats.PercentC << "%, " << myStats.PercentD << "%, "
                                                  << myStats.PercentF << "%" << endl;
            int dummy1, dummy2;
            cout << " DFW rate: " << GetDFWRate(myDept, dummy1, dummy2) << "%" << endl;
        }
    }
    else
    {
        Dept myDept = *allIfEnd;
        cout << myDept.Name << ":" << endl;
        cout << " # courses taught: " << getNumClasses(myDept) << endl;
        cout << " # students taught: " << getNumStudents(myDept) << endl;
        GradeStats myStats = GetGradeDistribution(myDept);
        cout << " grade distribution (A-F): " << myStats.PercentA << "%, " << myStats.PercentB << "%, "
                                              << myStats.PercentC << "%, " << myStats.PercentD << "%, "
                                              << myStats.PercentF << "%" << endl;
        int dummy1, dummy2;
        cout << " DFW rate: " << GetDFWRate(myDept, dummy1, dummy2) << "%" << endl;   
    }
}

/*
 * mySearch: searches a department or the entire college. Searches based on course number
 * or instructor prefix, depending on what the user enters
*/
void mySearch(const College& myCollege, const vector<Dept>::iterator& allIfEnd, const bool& deptFlag)
{
    vector<Course> myCourses;
    string userInput;
    int userInt;
    cout << "course # or instructor prefix? ";
    cin >> userInput;
    if(!deptFlag)
    {
        cout << "**dept not found" << endl;
        return;
    }
    stringstream ss(userInput);
    ss >> userInt;
    
    if(!ss.fail())
    {
        int userInt = stoi(userInput);
        if(allIfEnd == myCollege.Depts.end())
            myCourses = FindCourses(myCollege, userInt);
        else
            myCourses = FindCourses(*allIfEnd, userInt);
    }
    else
    {
        if(allIfEnd == myCollege.Depts.end())
            myCourses = FindCourses(myCollege, userInput);
        else
            myCourses = FindCourses(*allIfEnd, userInput);
    }
    
    if(myCourses.size() == 0)
    {
        cout << "**none found" << endl;
        return;
    }
    
    //Note, the vector doesn't need sorting in this function because it's pre-sorted by FindCourses()
    for(const Course& myCourse : myCourses)
    {
        cout << myCourse.Dept << " " << myCourse.Number 
             << " (section " << myCourse.Section << "): " 
             << myCourse.Instructor << endl;
        cout << " # students: " << myCourse.getNumStudents() << endl;
        //find the course type and print it
        cout << " course type: ";
        int gradingType = myCourse.getGradingType();
        if(gradingType == Course::Letter) cout << "letter" << endl;   //find grading type
        else if(gradingType == Course::Satisfactory) cout << "satisfactory" << endl;
        else cout << "unknown" << endl;
        //print the grade stats for this course
        GradeStats myStats = GetGradeDistribution(myCourse);
        cout << " grade distribution (A-F): " << myStats.PercentA << "%, " << myStats.PercentB << "%, "
                                              << myStats.PercentC << "%, " << myStats.PercentD << "%, "
                                              << myStats.PercentF << "%" << endl;
        int dummy1, dummy2;
        cout << " DFW rate: " << GetDFWRate(myCourse, dummy1, dummy2) << "%" << endl;
    }
}

/*
 * myUnknown: searches and prints the information of all classes of unknown grading type. Again, this could
 * be college-wide or department-wide
*/
void myUnknown(const College& myCollege, const vector<Dept>::iterator& allIfEnd, const bool& deptFlag)
{
    if(!deptFlag)
    {
        cout << "**dept not found" << endl;
        return;
    }
    vector<Course> myCourses;
    if(allIfEnd == myCollege.Depts.end()) //all classes
    {
        for(const Dept& myDept : myCollege.Depts)
            for(const Course& myCourse : myDept.Courses)
                if(myCourse.getGradingType() == Course::Unknown)
                    myCourses.push_back(myCourse);
        //sort the vector according to the assignment
        sort(myCourses.begin(), myCourses.end(),
             [](const Course& c1, const Course& c2)
             {
                 if(c1.Dept < c2.Dept) return true; //sort by dept
                 if(c1.Dept > c2.Dept) return false;
                 if(c1.Number < c2.Number) return true; //if depts are equal, sort by number
                 if(c1.Number > c2.Number) return false;
                 if(c1.Section < c2.Section) return true; //if numbers are equal, sort by section
                 if(c1.Section > c2.Section) return false;
                 return true;
             });
    }
    else
    {
        for(const Course& myCourse : (*allIfEnd).Courses)
            if(myCourse.getGradingType() == Course::Unknown)
                myCourses.push_back(myCourse);
        //sort the vector according to the assignment
        sort(myCourses.begin(), myCourses.end(),
             [](const Course& c1, const Course& c2)
             {
                 if(c1.Number < c2.Number) return true; //sort by number
                 if(c1.Number > c2.Number) return false;
                 if(c1.Section < c2.Section) return true; //if numbers are equal, sort by section
                 if(c1.Section > c2.Section) return false;
                 return true;
             });
    }
    
    if(myCourses.size() == 0)
    {
        cout << "**none found" << endl;
        return;
    }
    
    for(const Course& myCourse : myCourses)
    {
        cout << myCourse.Dept << " " << myCourse.Number 
             << " (section " << myCourse.Section << "): " 
             << myCourse.Instructor << endl;
        cout << " # students: " << myCourse.getNumStudents() << endl;
        cout << " course type: unknown" << endl; //they're all unknown, so I dont need to check
        GradeStats myStats = GetGradeDistribution(myCourse);
        cout << " grade distribution (A-F): " << myStats.PercentA << "%, " << myStats.PercentB << "%, "
                                              << myStats.PercentC << "%, " << myStats.PercentD << "%, "
                                              << myStats.PercentF << "%" << endl;
        int dummy1, dummy2;
        cout << " DFW rate: " << GetDFWRate(myCourse, dummy1, dummy2) << "%" << endl;
    }    
}

void myDFW(const College& myCollege, const vector<Dept>::iterator& allIfEnd, const bool& deptFlag)
{
    int dummy1, dummy2;
    vector<Course> myCourses;
    double threshold;
    cout << "dfw threshold? ";
    cin >> threshold;
    
    if(!deptFlag)
    {
        cout << "**dept not found" << endl;
        return;
    }
    if(allIfEnd == myCollege.Depts.end()) //if the user entered "all"
    {
        for(const Dept& myDept : myCollege.Depts) //search the entire college
            for(const Course& myCourse : myDept.Courses)
            {
                double x = GetDFWRate(myCourse, dummy1, dummy2);
                if(x > threshold) 
                    myCourses.push_back(myCourse);
            }
        
        sort(myCourses.begin(), myCourses.end(),
            [&](const Course& c1, const Course& c2)
            {
                double DFW1 = GetDFWRate(c1, dummy1, dummy2);
                double DFW2 = GetDFWRate(c2, dummy1, dummy2);
                if(DFW1 < DFW2) return false; //less than and not equal
                if(DFW1 > DFW2) return true; // greater than and not equal
                if(c1.Dept < c2.Dept) return true; //if DFW are the same, sort by Dept
                if(c1.Dept > c2.Dept) return false;
                if(c1.Number < c2.Number) return true; //if depts are equal, sort by number
                if(c1.Number > c2.Number) return false;
                if(c1.Section < c2.Section) return true; //if numbers are equal, sort by section
                if(c1.Section > c2.Section) return false;
                return true;
            });   
    }
    
    else //if the user entered a dept name
    {
        Dept myDept = *allIfEnd;
        for(const Course& myCourse : myDept.Courses) //search the department
            {
                double x = GetDFWRate(myCourse, dummy1, dummy2);
                if(x > threshold)
                    myCourses.push_back(myCourse);
            }
        
        sort(myCourses.begin(), myCourses.end(),
             [&](const Course& c1, const Course& c2)
             {
                 double DFW1 = GetDFWRate(c1, dummy1, dummy2);
                 double DFW2 = GetDFWRate(c2, dummy1, dummy2);
                 if(DFW1 < DFW2) return false; //less than and not equal
                 if(DFW1 > DFW2) return true; // greater than and not equal
                 if(c1.Dept < c2.Dept) return true; //if DFW are the same, sort by Dept
                 if(c1.Dept > c2.Dept) return false;
                 if(c1.Number < c2.Number) return true; //if depts are equal, sort by number
                 if(c1.Number > c2.Number) return false;
                 if(c1.Section < c2.Section) return true; //if numbers are equal, sort by section
                 if(c1.Section > c2.Section) return false;
                 return true;
             });   
    }
    
    if(myCourses.size() == 0)
    {
        cout << "**none found" << endl;
        return;
    }
    for(const Course& myCourse : myCourses)
    {
        cout << myCourse.Dept << " " << myCourse.Number 
             << " (section " << myCourse.Section << "): " 
             << myCourse.Instructor << endl;
        cout << " # students: " << myCourse.getNumStudents() << endl;
        cout << " course type: ";
        //get the grading type for the course
        int gradingType = myCourse.getGradingType();
        if(gradingType == Course::Letter) cout << "letter" << endl;   //find grading type
        else if(gradingType == Course::Satisfactory) cout << "satisfactory" << endl;
        else cout << "unknown" << endl;
        
        //print the grade stats for this course
        GradeStats myStats = GetGradeDistribution(myCourse);
        cout << " grade distribution (A-F): " << myStats.PercentA << "%, " << myStats.PercentB << "%, "
                                              << myStats.PercentC << "%, " << myStats.PercentD << "%, "
                                              << myStats.PercentF << "%" << endl;
        int dummy1, dummy2;
        cout << " DFW rate: " << GetDFWRate(myCourse, dummy1, dummy2) << "%" << endl;
    }
}

void myLetterA(const College& myCollege, const vector<Dept>::iterator& allIfEnd, const bool& deptFlag)
{
    int dummy1, dummy2;
    vector<Course> myCourses;
    double threshold;
    cout << "letter A threshold? ";
    cin >> threshold;
    if(!deptFlag)
    {
        cout << "**dept not found" << endl;
        return;
    }
    
    if(allIfEnd == myCollege.Depts.end()) //if the user entered "all"
    {
        for(const Dept& myDept : myCollege.Depts) //search the entire college
            for(const Course& myCourse : myDept.Courses)
            {
                GradeStats x = GetGradeDistribution(myCourse);
                if(x.PercentA > threshold)
                    myCourses.push_back(myCourse);
            }
        
        sort(myCourses.begin(), myCourses.end(),
            [&](const Course& c1, const Course& c2)
            {
                GradeStats DFW1 = GetGradeDistribution(c1);
                GradeStats DFW2 = GetGradeDistribution(c2);
                if(DFW1.PercentA < DFW2.PercentA) return false; //less than and not equal
                if(DFW1.PercentA > DFW2.PercentA) return true; // greater than and not equal
                if(c1.Dept < c2.Dept) return true; //if DFW are the same, sort by Dept
                if(c1.Dept > c2.Dept) return false;
                if(c1.Number < c2.Number) return true; //if depts are equal, sort by number
                if(c1.Number > c2.Number) return false;
                if(c1.Section < c2.Section) return true; //if numbers are equal, sort by section
                if(c1.Section > c2.Section) return false;
                return true;
            });   
    }
    
    else //if the user entered a dept name
    {
        Dept myDept = *allIfEnd;
        for(const Course& myCourse : myDept.Courses) //search the department
            {
                GradeStats x = GetGradeDistribution(myCourse);
                if(x.PercentA > threshold) 
                    myCourses.push_back(myCourse);
            }
        sort(myCourses.begin(), myCourses.end(),
             [&](const Course& c1, const Course& c2)
             {
                 GradeStats DFW1 = GetGradeDistribution(c1);
                 GradeStats DFW2 = GetGradeDistribution(c2);
                 if(DFW1.PercentA < DFW2.PercentA) return false; //less than and not equal
                 if(DFW1.PercentA > DFW2.PercentA) return true; // greater than and not equal
                 if(c1.Dept < c2.Dept) return true; //if DFW are the same, sort by Dept
                 if(c1.Dept > c2.Dept) return false;
                 if(c1.Number < c2.Number) return true; //if depts are equal, sort by number
                 if(c1.Number > c2.Number) return false;
                 if(c1.Section < c2.Section) return true; //if numbers are equal, sort by section
                 if(c1.Section > c2.Section) return false;
                 return true;
             });   
    }
    if(myCourses.size() == 0)
    {
        cout << "**none found" << endl;
        return;
    }
    
    for(const Course& myCourse : myCourses)
    {
        cout << myCourse.Dept << " " << myCourse.Number 
             << " (section " << myCourse.Section << "): " 
             << myCourse.Instructor << endl;
        cout << " # students: " << myCourse.getNumStudents() << endl;
        cout << " course type: letter" << endl;
        //print the grade stats for this course
        GradeStats myStats = GetGradeDistribution(myCourse);
        cout << " grade distribution (A-F): " << myStats.PercentA << "%, " << myStats.PercentB << "%, "
                                              << myStats.PercentC << "%, " << myStats.PercentD << "%, "
                                              << myStats.PercentF << "%" << endl;
        int dummy1, dummy2;
        cout << " DFW rate: " << GetDFWRate(myCourse, dummy1, dummy2) << "%" << endl;
    }    
}

int main()
{
    College myCollege("UIC");
    cout << std::fixed;
    cout << std::setprecision(2);
    std::string filename = "";
    std::string tempString;
    int numCourses = 0;
    int numStudents = 0;
    std::string command;
    bool deptFlag = true; /*deptFlag because I'm not allowed to state that I haven't found a Dept until the
                           * user enters more information */

    cin >> filename; //get name of file from input
    ifstream myFile;
    myFile.open(filename.c_str());
    if(!myFile.good()) //make sure file is good
        return -1;
    
    //Get header information
    getline(myFile, tempString, ','); 
    cout << "** College of " << tempString << ", ";
    getline(myFile, tempString, ',');
    cout << tempString << " ";
    getline(myFile, tempString);
    cout << tempString << " **" << endl;
    //Finish getting header information
    getline(myFile, tempString); //do nothing with this information, just get rid of the line
    
    map<string, Dept> myDepts; //string is dept.Name;
    while(getline(myFile, tempString))
    {
        Course tempCourse = ParseCourse(tempString);
        numCourses++; //keep track of the number of courses
        numStudents += tempCourse.getNumStudents(); //keep track of the number of students
        
        Dept tempDept(tempCourse.Dept);
        pair<string, Dept> myPair = pair<string, Dept>(tempCourse.Dept, tempDept);
        myDepts.insert(myPair);
        myDepts[tempCourse.Dept].Courses.push_back(tempCourse); //construct the departments and courses
        
    }
    mapToVec(myDepts, myCollege.Depts);

    cout << "# of courses taught: " << numCourses << endl;
    cout << "# of students taught: " << numStudents << endl;
    GradeStats myStats = GetGradeDistribution(myCollege);
    cout << "grade distribution (A-F): " << myStats.PercentA << "%, " << myStats.PercentB << "%, "
                                         << myStats.PercentC << "%, " << myStats.PercentD << "%, " 
                                         << myStats.PercentF << "%" << endl;
    int dummy1, dummy2;
    cout << "DFW rate: " << GetDFWRate(myCollege, dummy1, dummy2) << "%" << endl << endl;
    
    cout << "Enter a command> ";
    cin >> command;
    while(command != "#")
    {
        deptFlag = true;
        if(command == "summary" || command == "search" || command == "unknown" || command == "dfw" || command == "letterA") 
        {
            cout << "dept name, or all? ";
            cin >> tempString;
            vector<Dept>::iterator it = myCollege.Depts.end(); //if tempString is "all", this will not change
            if(tempString != "all")
            {
                it = find_if(myCollege.Depts.begin(), myCollege.Depts.end(),
                                 [=](const Dept& myDept)
                                  {
                                      return myDept.Name == tempString;
                                  });
                if(it == myCollege.Depts.end())
                    {
                    deptFlag = false; //if there is no such department, skip any calls
                    //cout << "**dept not found" << endl; 
                    }
            }

            if(command == "summary")
                mySummary(myCollege, it, deptFlag);
            else if(command == "search")
                mySearch(myCollege, it, deptFlag);
            else if(command == "unknown")
                myUnknown(myCollege, it, deptFlag);
            else if(command == "dfw")
                myDFW(myCollege, it, deptFlag);
            else if(command == "letterA")
                myLetterA(myCollege, it, deptFlag);
            }
        else
            cout << "**unknown command" << endl;
        cout << "Enter a command> ";
        cin >> command;
    }
    return 0;
}
