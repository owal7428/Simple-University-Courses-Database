//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: HashOpenAddressing.cpp
//-----------------------------------------------------------------------------

#include "HashOpenAddressing.h"

using namespace std;

HashOpenAddressing::HashOpenAddressing(int size)
{

}

HashOpenAddressing::~HashOpenAddressing()
{

}

int HashOpenAddressing::hash(int courseNumber)
{

}

void HashOpenAddressing::bulkInsert(string filename)
{

}

void HashOpenAddressing::search(int courseYear, int courseNumber, string profId)
{

}

void HashOpenAddressing::displayAllCourses()
{
    for (int i = 0; i < hashTableSize; i++) //Loops through index of the hashTable
    {
        Course *temp = hashTable[i];
        displayCourseInfo(temp);
    }
}

void HashOpenAddressing::displayCourseInfo(Course* c)
{
	if (c == nullptr)
        cout << "Course was not found." << endl;
    
    else
        cout << c -> year << " " << c -> courseName << " " << c -> courseNum << " " << c -> prof -> profName << endl;
}