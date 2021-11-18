//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: ProfBST.cpp
//-----------------------------------------------------------------------------

#include "ProfBST.h"

#include <iostream>

using namespace std;

ProfBST::ProfBST()
{

}

//-----------------------------------------------------------------------------
//~ProfBST:     Self deletion method
//Parameters:   None
//Returns:      Nothing
//-----------------------------------------------------------------------------

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

    delete node;                //Deletes node (eat shit)!
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
