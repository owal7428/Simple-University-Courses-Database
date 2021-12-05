//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: ProfBST.cpp
//-----------------------------------------------------------------------------

#include "ProfBST.h"

#include <iostream>

using namespace std;

//Constructor
ProfBST::ProfBST()
{
    root = nullptr;
}

/*
================
deleteAll

Helper function for ~ProfBST
Recursively goes through every node and deletes
================
*/
void deleteAll(Professor *&node)
{
    if (node == nullptr)
        return;
    
    deleteAll(node -> left);    //Post-order traversal for the BST
    deleteAll(node -> right);   

    delete node;    //Deletes node
}

//Destructor
ProfBST::~ProfBST()
{
    deleteAll(root);    //Starts the deleteAll recursive loop at the root node
    root = NULL;
}

/*
================
insertNode

Helper to addProfessor function
Recursively looks through BST to find correct location for new node
================
*/
Professor* insertNode(Professor *newNode, Professor *root)
{
    if (root == nullptr)    //Checks if location in tree is found
    {
        return newNode;    //Places the new node in that location
    }
 
    if (newNode -> profId > root -> profId)     //Recursively looks through tree
    {
        root->right = insertNode(newNode, root -> right); 
    }
    else
    {
        root -> left = insertNode(newNode, root -> left);
    }
 
    return root;
}

/*
================
addProfessor

Creates new Professor node and then inserts into BST object
================
*/
void ProfBST::addProfessor(string profId, string profName)
{
    if (searchProfessor(profId))    //Checks to see if the professor already exists in the tree
        return;
    
    Professor *newProfessor = new Professor();  //Creates the new Professor object

    newProfessor -> profName = profName;    //Sets all of the variables for the new object
    newProfessor -> profId = profId;
    newProfessor -> right = nullptr;
    newProfessor -> left = nullptr;
    
    if (!root)                  //Checks if the root node exists or not
        root = newProfessor;    //If it does not, it makes the root equal to the new node
    
    else
        insertNode(newProfessor, root);
}

/*
================
searchHelper

Recursively looks through the BST to find specific node
Returns null if the node is not found
================
*/
Professor* searchHelper(Professor *root, string profId)
{
    if (root == nullptr)
        return nullptr;
    
    if (profId == root -> profId)
        return root;
    
    else if (profId > root -> profId)
        return searchHelper(root -> right, profId);
    
    else
        return searchHelper(root -> left, profId);

}

//Calls the searchHelper function
Professor* ProfBST::searchProfessor(string profId)
{
    return searchHelper(root, profId);  
}

/*
================
publicSearchProfessor

Finds professor node with specific ID and prints the courses they've taught
================
*/
void ProfBST::publicSearchProfessor(string profId)
{
    Professor *temp = searchProfessor(profId);  //Creates temporary professor node

    if (!temp)  //Checks if professor exists or not
    {
        cout << "Professor not found." << endl;
        return;
    }

    displayProfessorInfo(temp);    
}

/*
================
publicSearchProfessor

Prints info of professor node passed through as a parameter
================
*/
void ProfBST::displayProfessorInfo(Professor* p)
{
    cout << "Name: " << p -> profName << endl;  //Prints name of professor

    for (int i = 0; i < p -> coursesTaught.size(); i++)  //Goes through every course the professor has taught
    {
        cout << "-" << p -> coursesTaught[i] -> courseNum << ": ";
        cout << p -> coursesTaught[i] -> courseName << ", ";
        cout << p -> coursesTaught[i] -> year << endl;
    }
}
