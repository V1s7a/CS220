/** rpnUtils.c
 * ===========================================================
 * Name: Student
 * Section:
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */
#define _CRT_SECURE_NO_WARNINGS
#include "rpnUtils.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void testHarness1() {
    // Part I test harness.

    LinkedList* list = createLinkedList();
    printf("Created Linked List\n");

    // data to be appended
    double* a = (double*)malloc(sizeof(double));
    *a = 1;
    double* b = (double*)malloc(sizeof(double));
    *b = 2;
    double* c = (double*)malloc(sizeof(double));
    *c = 3;

    appendElementLinkedList(list, a, REAL_NUMBER);
    appendElementLinkedList(list, b, REAL_NUMBER);
    appendElementLinkedList(list, c, REAL_NUMBER);
    printf("Appended 3 items to linked list\n");

    // get length of list
    printf("Length: %d\n", lengthOfLinkedList(list));

    // print list
    printLinkedList(list);

    // get element data from list
    double* q = (double*)malloc(sizeof(double));
    *q = 1;
    ElementType* type = (ElementType*)malloc(sizeof(ElementType));
    *type = REAL_NUMBER;
    Node* elementNode = getElementLinkedList(list, q, type);
    printf("Element data at position 1: %d\n", elementNode->data);

    // delete element from list
    printf("deleting node in position 1\n");
    deleteElementLinkedList(list, 1);
    printLinkedList(list);

    // insert element into list
    int* x = 10;
    printf("Inserting data value 10 at position 1\n");
    insertElementLinkedList(list, 1, x, REAL_NUMBER);
    printLinkedList(list);

    // change element in list
    int* y = 12;
    printf("Changing element at position 2 to value of 12\n");
    changeElementLinkedList(list, 2, y, REAL_NUMBER);
    printLinkedList(list);

    // delete list
    printf("Deleting list\n");
    deleteLinkedList(list);
    printf("List deleted\n");
    return;
}

void rpnCalc() {
    // initialize stack
    StackAsLinkedList* theStack = stackInit();

    // get data from user
    printf("RPN Expression: ");
    char string[100];
    //scanf("%s\n", string);
    fgets(string, 100, stdin);
    // check to exit
    if (strcmp(string, "\n") == 0) {
        exit(0);
    }
    QueueAsLinkedList* queue = NULL;
    queue = queueInit();
    // tokenize string
    int val = tokenize(queue, string);
    if (val == 1)
    {
        exit(1);
    }
    
    // print queue and operators
    while (!queueIsEmpty(queue))
    {
        ElementType* myType = (ElementType*) malloc(sizeof(ElementType));
        void* element = queueDequeue(queue, myType);
        if (*myType == REAL_NUMBER)
        {
            double* blonde = (double*) malloc(sizeof(double));
            *blonde = *((double*) element);
            stackPush(theStack, element, REAL_NUMBER);

        }else
        {
            printf(" Operator: '");
            switch (*((operators*)element))
            {
            case add:
                printf("+");
                break;
            case subtract:
                printf("-");
                break;
            case multiply:
                printf("*");
                break;
            case divide:
                printf("/");
                break;
            case power:
                printf("^");
                break;
            default:
                break;
            }   
            printf("' | Stack before operation: ");
            stackPrint(theStack);

            double* x = stackPop(theStack, myType);
            double* y = stackPop(theStack, myType);
            
            switch (*((operators*)element))
            {
            case add:
                *x = *y + *x;
                break;
            case subtract:
                *x = *y - *x;
                break;
            case multiply:
                *x = *y * *x;
                break;
            case divide:
                *x = *x / *y;
                break;
            case power:
                *x = pow(*x,*y);
                break;
            }
            stackPush(theStack, x, REAL_NUMBER);

        }
        
        
    }
    ElementType elementType = 0;
    double* ans = stackPop(theStack, &elementType);
    printf("Answer: %.3lf\n", *ans);

    // free memory
    deleteStack((LinkedList*)theStack);
    deleteQueue(queue);
    // recall rpnCalc to start new instance.
    rpnCalc();
}

int tokenize(QueueAsLinkedList* queue, char* input) {
    double* elementNumber = NULL;
    elementNumber = (double*)malloc(sizeof(double));
    operators* ops = NULL;
    ops = (operators*)malloc(sizeof(operators));
    ElementType elementType;
    int numberCount = 0, operatorCount = 0;
    for (int i = 0; i < strlen(input) - 2; i++) {
        elementType = -1;
        if (input[i] != ' ') {
            if (input[i] == '+') {
                elementType = MATH_OPERATOR;
                *ops = add;
            } else if (input[i] == '*') {
                elementType = MATH_OPERATOR;
                *ops = multiply;
            } else if (input[i] == '/') {
                elementType = MATH_OPERATOR;
                *ops = divide;
            } else if (input[i] == '^') {
                elementType = MATH_OPERATOR;
                *ops = power;
            } else if (input[i] == '-') {
                if ((i <= strlen(input - 1) && input[i + 1] == ' ') || i > strlen(input) - 1) {
                    elementType = MATH_OPERATOR;
                    *ops = subtract;
                } else {
                    int j = i + 1;
                    while (input[j] == '.' || isdigit(input[j])) {
                        j++;
                    }
                    elementType = REAL_NUMBER;
                    *elementNumber = (double) atof(&(input[i]));
                    //fprintf(stderr, "Read %lf\n", *elementNumber);
                    i = i + j - 1;
                }

            } else if (input[i] == '.' || isdigit(input[i])) {
                int j = i + 1;
                while (input[j] == '.' || isdigit(input[j])) {
                    j++;
                }
                elementType = REAL_NUMBER;
                
                double number = atof(&(input[i]));
                *elementNumber = number;
                //fprintf(stderr, "Read %lf\n", *elementNumber);
                i = i + j - 1;
            }
        

            if (elementType == -1)
            {
                //print invalid input.
                return 1;
            }else{
                if (elementType == MATH_OPERATOR)
                {
                    queueEnqueue(queue, ops, elementType);
                    //fprintf(stderr, "Enqueuing %d\n", *((int*) ops));
                    ops = (operators*) malloc(sizeof(operators));
                    operatorCount++;
                }else
                {
                    queueEnqueue(queue, elementNumber, elementType);
                    //fprintf(stderr, "Enqueuing %lf\n", *((double*) elementNumber));
                    elementNumber = (double*) malloc(sizeof(double));
                    numberCount++;
                }
                
                
            }
        }
        
    }
    return 0;
}