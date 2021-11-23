<img src="https://www.colorado.edu/cs/profiles/express/themes/ucb/images/cu-boulder-logo-text-black.svg" alt="CU Boulder Logo" width="500">

# CSCI 2270: Data Structures <br/> University Courses Database Project

## Introduction
The objective of this project is to write an application that reads a list of University courses from a data file and then inserts them into two separate hash tables. The first hash table will use the Open Addressing collision resolution scheme and the second hash table will use the Chaining collision resolution scheme. Users should be able to search the hash tables for a specific course number or display all of the courses. It’s your objective to compare and contrast the hashing collision resolution methods. Additionally, the application should maintain a list of courses taught by each professor by using a binary search tree data structure. Users should be able to search for a professor and view all of the courses taught by the Professor.

## Getting Started
1. Download the project pdf writeup located within this starter repo.<br/>
2. Download the PowerPoint slide deck [Getting Started With GitHub Classroom Workflow](https://docs.google.com/presentation/d/1B0yZb6twQ_NVL8PripCL7AkeIKSrR8_M/edit?usp=sharing&ouid=115561230768383364768&rtpof=true&sd=true).<br/>
3. Download the [GitHub presentation slide deck](https://drive.google.com/file/d/12mMxMGRrpnkSuz08FUlvkhC-9WJ4JHns/view?usp=sharing) created by Asa Ashraf.<br/>
4. View the GitHub lecture videos [Part I](https://drive.google.com/file/d/1P4iqEbt9Nx68-Nq0FxxpdBZCrbkx5cN3/view?usp=sharing) and [Part II](https://drive.google.com/file/d/1EFYq_qJsV3QNcx_W86nz2KFpQUhSn9jF/view?usp=sharing) given by Asa Ashraf.

## Answers to ReadMe Questions
1. I think that the chaining method of collision resolution works better. I think this because the chaining method is able to fill the hash table with less collisions and search operations than the open addressing method. It is also able to find a specific course using less search operations than open addressing as well.
2. I think than an alternative data structure to the BST for the database of professors could be another hash table filled with professor pointers. I think this would be useful because it would be much faster to search for a specific professor with a hash table than a BST.
3. One way that I would improve this application is changing the parameters on some of the functions. I would do this because many helper functions could be removed if the regular functions had more parameters.

## Disclaimer
Students are not allowed to share this code or make it public at any time, even after the course has completed.
