//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: ProfBST.cpp
//-----------------------------------------------------------------------------

#include "ProfBST.h"

#include <iostream>

using namespace std;

//Does basically nothing, not even gonna waste my time on this one
ProfBST::ProfBST()
{
    root = NULL;    //Seriously, one line?!
}

//-----------------------------------------------------------------------------
//~ProfBST:         Self deletion method
//Parameters:       None
//Returns:          Nothing
//-----------------------------------------------------------------------------
//Why am I even doing this for one line of code?!?

ProfBST::~ProfBST()
{
    deleteAll(root);    //Starts the deleteAll recursive loop at the root node
}


//-----------------------------------------------------------------------------
//deleteAll:        Helper function for ~ProfBST
//Parameters:       Pointer to professor object
//Returns:          Void
//-----------------------------------------------------------------------------

void deleteAll(Professor* node)
{
    deleteAll(node -> left);    //Post-order traversal for the BST
    deleteAll(node -> right);   

    delete node;                //Deletes node (yeeet)!
}


//-----------------------------------------------------------------------------
//addProfessor:     Adds a new node to the BST
//Parameters:       Two string variables
//Returns:          Void
//-----------------------------------------------------------------------------

void ProfBST::addProfessor(string profId, string profName)
{
    if (searchProfessor(profId))    //Checks to see if the professor already exists in the tree
        return;                     //Exits function if it does
    
    Professor *newProfessor = new Professor();  //Creates the new Professor object

    newProfessor -> profName = profName;        //Sets all of the variables for the new object
    newProfessor -> profId = profId;
    newProfessor -> right = nullptr;
    newProfessor -> left = nullptr;
    
    if (!root)                  //Checks if the root node exists or not
        root = newProfessor;    //If it does not, it makes the root equal to the new node
    
    else
        addHelper(newProfessor, root);      //Recursive loop to place new object in the correct position
    
    
}
//-----------------------------------------------------------------------------
//addHelper:        Searches for the correct place to insert new node
//Parameters:       Node to be inserted, Node that is being checked
//Returns:          Void
//-----------------------------------------------------------------------------

void addHelper(Professor *&node, Professor *root)
{
    if (root == nullptr)        //If the current node being searched is null, insert here
    {
        root = node;
        return;
    }
    
    if (node -> profId > root -> profId)    //Checks if the current node should go left
        addHelper(node, root -> right);     //Or right of current root
    
    else if (node -> profId < root -> profId)
        addHelper(node, root -> left);
    
    return;
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
