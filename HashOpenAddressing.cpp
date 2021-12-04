//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: HashOpenAddressing.cpp
//-----------------------------------------------------------------------------

#include "HashOpenAddressing.h"

using namespace std;

//Constructor
HashOpenAddressing::HashOpenAddressing(int size)
{
    hashTableSize = size;   //Sets value of hashTableSize

    hashTable = new Course*[hashTableSize]; //Sets the size of hashTable

    for (int i = 0; i < hashTableSize; i++) //Sets every index to nullptr
        hashTable[i] = nullptr;
}

//Deconstructor
HashOpenAddressing::~HashOpenAddressing()
{
    profDb.~ProfBST();  //Deletes the BST of professors

    delete[] hashTable; //Deletes array of pointers
}

//Hash function
int HashOpenAddressing::hash(int courseNumber)
{
    return courseNumber % hashTableSize;
}

/*
================
bulkInsert

Reads every line in the csv file give (except for the first line)
Creates new professor object if one doesn't already exist for the professor for a course
Creates new course object and adds it to the hash table
Resolves collisions using open addressing (quadratic probing)
================
*/
void HashOpenAddressing::bulkInsert(string filename)
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

        string profName = array[5] + " " + array[6];    //Gets the full name of the professor in one string
        string profId = array[4];

        profDb.addProfessor(profId, profName);                //Adds professor to the profDB if it doesn't already exist
        Professor *newProf = profDb.searchProfessor(profId);  //Creates temp professor object

        Course *newCourse = new Course(stoi(array[0]), array[1], stoi(array[2]), array[3], newProf);    //Creates new course object
        newProf -> coursesTaught.push_back(newCourse);                                                  //Adds the new course object to courses taught

        int index = hash(stoi(array[2]));

        if (hashTable[index] != nullptr)   //Checks for collision
        {
            numCollisions++;

            for (int i = 1; i < hashTableSize; i++) //Implementation of quadratic probing
            {
                numSearches++;
                int newIndex = hash(index + i * i); //Finds new index to check

                if (hashTable[newIndex] == nullptr) //Checks if new index is empty
                {
                    hashTable[newIndex] = newCourse;
                    break;
                }
            }
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

Looks through every index in the hash table using quadratic probing until correct course is found
If no node is found, nullptr is passed to displayCourseInfo
================
*/
void HashOpenAddressing::search(int courseYear, int courseNumber, string profId)
{
    int index = hash(courseNumber);
    int numSearches = 0;

    Course *temp = nullptr;

    for (int i = 0; i < hashTableSize; i++)
    {
        numSearches++;
        int newIndex = hash(index + i * i); //Finds new index using quadratic probing

        if (hashTable[newIndex] == nullptr)
            continue;

        else if (hashTable[newIndex] -> year == courseYear && hashTable[newIndex] -> courseNum == courseNumber && hashTable[newIndex] -> prof -> profId == profId)
        {
            temp = hashTable[newIndex];
            break;
        }
    }

    if (temp != nullptr)
    {
        cout << "Search operations using open addressing: " << numSearches << endl;
    }

    displayCourseInfo(temp);
}

//Loops through every index in the hash table and prints info in that index 
void HashOpenAddressing::displayAllCourses()
{
    for (int i = 0; i < hashTableSize; i++) //Loops through index of the hashTable
    {
        Course *temp = hashTable[i];
        displayCourseInfo(temp);
    }
}

//Prints out all info in a course
void HashOpenAddressing::displayCourseInfo(Course* c)
{
	if (c == nullptr)
        cout << "Course was not found." << endl;
    
    else
        cout << c -> year << " " << c -> courseName << " " << c -> courseNum << " " << c -> prof -> profName << endl;
}