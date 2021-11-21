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

    for (int i = 0; i < hashTableSize; i++) //Sets every index to nullptr
        hashTable[i] = nullptr;
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

            for (int i = 1; i < hashTableSize; i++)
            {
                numSearches++;
                int newIndex = hash(index + i * i);

                if (hashTable[newIndex] == nullptr)
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