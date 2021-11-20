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
    
    if (file.fail())    //Checks if file exists
    {
        cout << "Failed to open the file." << endl;
        return;
    }

    int numCollisions = 0;
    int numSearches = 0;

    bool topOfFile = true;

    string inputstr;

    while (file >> inputstr)    //Loops through every line of the csv file
    {
        if (topOfFile == true)  //Checks if the current line is the top
        {
            topOfFile = false;  //Skips the line if it is
            continue;
        }

        istringstream tempstr(inputstr);
        string array[7];

        int i = 0;
        while (getline(tempstr, inputstr, ',')) //Loops through every word in the current line
        {
            array[i] = inputstr;
            i++;
        }

        string profName = array[5] + " " + array[6];            //Gets the full name of the professor in one string
        profDb.addProfessor(array[4], profName);                //Adds professor to the profDB if it doesn't already exist
        Professor *newProf = profDb.searchProfessor(profName);  //Creates temp professor object

        Course *newCourse = new Course(stoi(array[0]), array[1], stoi(array[2]), array[3], newProf);    //Creates new course object
        newProf -> coursesTaught.push_back(newCourse);                                                  //Adds the new course object to courses taught

        int index = hash(stoi(array[2]));

        if (hashTable[index])   //Checks for collision
        {
            numCollisions++;

            Course *temp = hashTable[index];

            while (temp -> next != nullptr) //Loops through linked list until empty node is found
            {
                numSearches++;
                temp = temp -> next;
            }

            numSearches++;

            temp -> next = newCourse;       //Places newCourse into the LL
            newCourse -> previous = temp;
        }
        else
        {
            hashTable[index] = newCourse;
        }
    }

    cout << "Collisions using chaining: " << numCollisions << endl;
    cout << "Search operations using chaining: " << numSearches << endl;
}

/*
================
search
================
*/
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
            displayCourseInfo(temp);
            temp = temp -> next;
        }
    }
}

//Prints out the info about a course
void HashChaining::displayCourseInfo(Course* c)
{
    cout << c -> year << " " << c -> courseName << " " << c -> courseNum << " " << c -> prof << endl;
}