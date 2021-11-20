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

    HashChaining chainHash(stoi(argv[2]));
    HashOpenAddressing openHash(stoi(argv[2]));

    while (true)
    {
        cout << "========Main Menu========" << endl;
        cout << "1. Populate hash tables" << endl;
        cout << "2. Search for a course" << endl;
        cout << "3. Search for a professor" << endl;
        cout << "4. Display all courses" << endl;
        cout << "5. Exit" << endl;

        int choice = 0;
    }

    return 0;
}