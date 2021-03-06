//-----------------------------------------------------------------------------
// Simple-University-Courses-Database
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

    for (int i = 0; i < hashTableSize; i++) //Sets every index to nullptr
        hashTable[i] = nullptr;
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

Reads every line in the csv file give (except for the first line)
Creates new professor object if one doesn't already exist for the professor for a course
Creates new course object and adds it to the hash table
Resolves collisions using chaining (linked lists)
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

    while (getline(file, inputstr, '\n'))    //Loops through every line of the csv file
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
        string profId = array[4];

        profDb.addProfessor(profId, profName);                //Adds professor to the profDB if it doesn't already exist
        Professor *newProf = profDb.searchProfessor(profId);  //Creates temp professor object

        Course *newCourse = new Course(stoi(array[0]), array[1], stoi(array[2]), array[3], newProf);    //Creates new course object
        newProf -> coursesTaught.push_back(newCourse);                                                  //Adds the new course object to courses taught

        int index = hash(stoi(array[2]));

        if (hashTable[index] != nullptr)   //Checks for collision
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

Loops through every node in index until it finds one with matching info
If no node is found, nullptr is passed to displayCourseInfo
================
*/
void HashChaining::search(int courseYear, int courseNumber, string profId)
{
    int index = hash(courseNumber);
    int numSearches = 0;

    Course *temp = nullptr;

    Course *curr = hashTable[index];    //Used to traverse linked list
    
    while (curr != nullptr)
    {
        if (curr -> year == courseYear && curr -> courseNum == courseNumber && curr -> prof -> profId == profId)
        {
            temp = curr;    //If target node is found, set temp pointer equal to target pointer
            break;
        }

        curr = curr -> next;
        numSearches++;
    }

    if (temp != nullptr)
    {
        cout << "Search operations using chaining: " << numSearches << endl;
    }

    displayCourseInfo(temp);
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
    if (c == nullptr)
        cout << "Course was not found." << endl;
    
    else
        cout << c -> year << " " << c -> courseName << " " << c -> courseNum << " " << c -> prof -> profName << endl;
}