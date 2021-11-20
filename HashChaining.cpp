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

    for (int i = 0; i < hashTableSize; i++) //Loops through index of the hashTable
    {
        Course *temp = hashTable[i];
        
        while (temp != nullptr)     //Deletes linked list in every index
        {
            Course *next = temp -> next;
            delete temp;
            temp = next;
        }
    }

    delete[] hashTable; //Deletes array of pointers

}

//Hash algorithm
int HashChaining::hash(int courseNumber)
{
    return courseNumber % hashTableSize;
}

/*
================
bulkInsert
================
*/
void HashChaining::bulkInsert(string filename)
{
    ifstream file (filename);
    int index;

    bool topOfFile = true;
    
    if (file.fail())
    {
        cout << "Failed to open the file." << endl;
        return;
    }
    
    string inputstr;

    while (file >> inputstr)
    {
        if (topOfFile == true)
        {
            topOfFile = false;
            continue;
        }

        istringstream tempstr(inputstr);
        string array[7];

        int i = 0;
        while (getline(tempstr, inputstr, ','))
        {
            array[i] = inputstr;
            i++;
        }

        string profName = array[5] + " " + array[6];            //Gets the full name of the professor in one string
        profDb.addProfessor(array[4], profName);                //Adds professor to the profDB if it doesn't already exist
        Professor *newProf = profDb.searchProfessor(profName);  //Creates temp professor object

        
        Course *newCourse = new Course(stoi(array[0]), array[1], stoi(array[2]), array[3], newProf);    //Creates new course object
        newProf -> coursesTaught.push_back(newCourse);                                                  //Adds the new course object to courses taught

    }
}

void HashChaining::search(int courseYear, int courseNumber, string profId)
{
    int index = hash(courseNumber);
}

/*
================
displayAllCourses

Displays all of the courses in the hash table
================
*/
void HashChaining::displayAllCourses()
{
    for (int i = 0; i < hashTableSize; i++) //Loops through index of the hashTable
    {
        Course *temp = hashTable[i];
        
        while (temp != nullptr)     //Prints out every node in the index
        {
            cout << temp -> year << " " << temp -> courseName << " " << temp -> courseNum << " " << temp -> prof << endl;
            temp = temp -> next;
        }
    }
}

void HashChaining::displayCourseInfo(Course* c)
{

}