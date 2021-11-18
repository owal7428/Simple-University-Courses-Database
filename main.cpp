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

    ifstream file (argv[1]);

    if (file.fail())
    {
        cout << "Failed to open the file." << endl;

        return 0;
    }

    return 0;
}