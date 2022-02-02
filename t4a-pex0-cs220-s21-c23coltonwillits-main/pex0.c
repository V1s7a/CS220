/** pex0.c
* ===========================================================
* Name: Colton Willits, 1/12/21
* Section: T4
* Project: C Profciency
* Purpose: 
* Documentation Statement: None
* =========================================================== */
#define _CRT_SECURE_NO_WARNINGS
#include "pex0functs.h"

int main(int argc, char *argv[])
{

    char filename[] = "";
    int rows, columns;
    if (argc == 3)
    {
        strcpy(filename, argv[1]);
        rows = argv[2];
        columns = argv[3];
    }
    else
    {
        printf("Invalid Argumets");
    }

    char sentence[] = "";
    printf("Please enter a sentence.");
    fgets(sentence, 80, stdin);
    parseIt(sentence);
    printf("%s\n", sentence);

    char *ptr = (char *) malloc(80);
    *ptr = modifyIt(sentence);

    char sentenceTwo[] = "";
    printf("Please enter a new sentence.\n");
    fgets(sentenceTwo, 80, stdin);
    char *ptr2 = (char *) malloc(80); 
    strcpy(*ptr2, modifyIt(sentenceTwo));
    printf("%s\n", ptr2);

    StudentRecType *records = (StudentRecType * ) malloc(30);
    getInfo(&records);
    for (int i = 0; i < sizeof(records); i++)
    {
        printf("Name: %s Age: %d", records[i].name, records[i].age);
    }
    //not sure how to do step r through x.

    printf("Time to complete: 4hrs");
}
