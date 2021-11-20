//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: HashChaining.cpp
//-----------------------------------------------------------------------------

#include "HashChaining.h"

using namespace std;

//Constructor
HashChaining::HashChaining(int size)
{
    hashTableSize = size;   //Sets value of hashTableSize

    hashTable = new Course*[hashTableSize]; //Sets the size of hashTable
}

//Deconstructor
HashChaining::~HashChaining()
{
    profDb.~ProfBST();  //Deletes the BST of professors

    for (int i = 0; i < hashTableSize; i++)     //Loops through index of the hashTable
    {
        Course *temp = hashTable[i];
        
        while (temp != nullptr)     //Deletes linked list in every index
        {
            Course *next = temp -> next;
            delete temp;
            temp = next;
        }
    }

    delete[] hashTable;     //Deletes array of pointers

}

int HashChaining::hash(int courseNumber)
{
    return courseNumber % hashTableSize;
}

void HashChaining::bulkInsert(string filename)
{

}

void HashChaining::search(int courseYear, int courseNumber, string profId)
{

}

void HashChaining::displayAllCourses()
{

}

void HashChaining::displayCourseInfo(Course* c)
{

}