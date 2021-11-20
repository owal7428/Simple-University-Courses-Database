//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: main.cpp
//-----------------------------------------------------------------------------

#include "HashOpenAddressing.h"
#include "HashChaining.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main (int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid number of arguments." << endl;
        cout << "Usage: ./<program name> <csv file> <hashTable size>" << endl;

        return 0;
    }

    //Note: hashtable size needs to be the number of lines in the file - 1 to account for the top line being skipped

    string filename = argv[1];

    HashChaining chainHash(stoi(argv[2]));
    //HashOpenAddressing openHash(stoi(argv[2]));

    while (true)
    {
        cout << endl;
        cout << "========Main Menu========" << endl;
        cout << "1. Populate hash tables" << endl;
        cout << "2. Search for a course" << endl;
        cout << "3. Search for a professor" << endl;
        cout << "4. Display all courses" << endl;
        cout << "5. Exit" << endl;
        cout << endl;

        int choice;
        cout << "Enter an option: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            cout << "[OPEN ADDRESSING] Hash table populated" << endl;
            cout << "--------------------------------------" << endl;
            //openHash.bulkInsert(filename);
            cout << "[CHAINING] Hash table populated" << endl;
            cout << "-------------------------------" << endl;
            chainHash.bulkInsert(filename);
        }
        else if (choice == 2)
        {

        }
        else if (choice == 3)
        {

        }
        else if (choice == 4)
        {

        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Improper input" << endl;
        }
    }

    return 0;
}