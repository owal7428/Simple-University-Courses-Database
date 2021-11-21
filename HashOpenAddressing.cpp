//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: HashOpenAddressing.cpp
//-----------------------------------------------------------------------------

#include "HashOpenAddressing.h"

using namespace std;

HashOpenAddressing::HashOpenAddressing(int size)
{
    hashTableSize = size;   //Sets value of hashTableSize

    hashTable = new Course*[hashTableSize]; //Sets the size of hashTable
}

HashOpenAddressing::~HashOpenAddressing()
{
    profDb.~ProfBST();  //Deletes the BST of professors

    delete[] hashTable; //Deletes array of pointers
}

int HashOpenAddressing::hash(int courseNumber)
{
    return courseNumber % hashTableSize;
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