//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: ProfBST.cpp
//-----------------------------------------------------------------------------

#include "ProfBST.h"

#include <iostream>

using namespace std;

//Does basically nothing, not even gonna waste my time on fancy comments
ProfBST::ProfBST()
{
    root = NULL;
}

//-----------------------------------------------------------------------------
//~ProfBST:     Self deletion method
//Parameters:   None
//Returns:      Nothing
//-----------------------------------------------------------------------------
//Why am I even doing this for one line of code?!?

ProfBST::~ProfBST()
{
    deleteAll(root);    //Starts the deleteAll recursive loop at the root node
}


//-----------------------------------------------------------------------------
//deleteAll:    Helper function for ~ProfBST
//Parameters:   Pointer to professor object
//Returns:      Void
//-----------------------------------------------------------------------------

void deleteAll(Professor* node)
{
    deleteAll(node -> left);    //Post-order traversal for the BST
    deleteAll(node -> right);   

    delete node;                //Deletes node (yeeet)!
}

void ProfBST::addProfessor(string profId, string profName)
{

}

Professor* ProfBST::searchProfessor(string profId)
{

}

void ProfBST::publicSearchProfessor(string profId)
{

}

void ProfBST::displayProfessorInfo(Professor* p)
{

}
