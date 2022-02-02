/** rpnUtils.c
 * ===========================================================
 * Name: Student
 * Section:
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */

#ifndef RPNUTILS_H
#define RPNUTILS_H
#define _CRT_SECURE_NO_WARNINGS  // Hide "unsafe, deprecated" warnings, must be at the top

// What other includes do you need?
#include <string.h>

#include "listAsLinkedList.h"
#include "queueAsLinkedList.h"
#include "stackAsLinkedList.h"
#include <ctype.h>
#include <stdio.h>
// prototypes for utility functions

void testHarness1();

void rpnCalc();

int tokenize(StackAsLinkedList* stack, char array[]);

#endif  // RPNUTILS_H
