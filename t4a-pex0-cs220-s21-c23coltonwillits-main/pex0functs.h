/** pex0functs.h
* ===========================================================
* Name: Colton Willits, 1/12/21
* Section: T4
* Project: C Profciency
* Purpose: 
* =========================================================== */
#ifndef PEX0FUNCTS_H
#define PEX0FUNCTS_H
#include <stdio.h>
#include <string.h>

typedef struct StudentRecType_Struct
{
    char name[64];
    int age;
} StudentRecType;

/**
* @brief Modifies user sentence " " = "-", t or T = " "
* @param x user sentence
* @return none
*/
void parseIt(char x[]);

/**
* @brief modifies sentence by addin start and end tags.
* @param x is sentence to be passed.
* @return modified sentence
*/
char modifyIt(char x[]);

/**
* @brief sets member info
* @param x the StudentRecType data structure
* @return none
*/
void getInfo(StudentRecType *x);

/**
* @brief populates arrays with random numbers 1 through 100
* @param x 2d array of data.
* @return nothing
*/
void fillIt(int x[]);

/**
* @brief outputs data to text file
* @param x 2d array of data
* @return nothing
*/
void dumpIt(int x[]);

#endif // !PEX0FUNCTS_H