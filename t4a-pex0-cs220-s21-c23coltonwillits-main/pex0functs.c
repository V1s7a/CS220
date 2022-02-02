/** pex0functs.c
* ===========================================================
* Name: Colton Willits, 1/12/21
* Section: T4
* Project: C Profciency
* Purpose: 

* =========================================================== */

#include "pex0functs.h"

void parseIt(char x[])
{

    for (int i = 0; i < strlen(x); i++)
    {
        switch (x[i])
        {
        case ' ':
            x[i] = '-';
            break;
        case 't':
            x[i] = ' ';
            break;
        case 'T':
            x[i] = ' ';
        default:
            break;
        }
    }
};

char modifyIt(char x[])
{
    char ptr[80];
    strcpy(ptr, "start->");
    strcat(ptr, x);
    strcat(ptr, "<-end");
    return ptr;
};

void getInfo(StudentRecType *x){
    fgets(x->name, 46, stdin);
    fscanf(stdin, "%d", x->age);
    return;
};

void fillIt(int x[]){

};

void dumpIt(int x[]){

};
