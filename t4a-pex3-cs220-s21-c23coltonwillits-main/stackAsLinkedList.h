/** stackAsLinkedList.h
 * ===========================================================
 * Name: Student
 * Section:
 * Project: PEX 3 - RPN Calculator
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */

#ifndef STACKASLINKEDLIST_H
#define STACKASLINKEDLIST_H

#include <stdbool.h>
#include <stddef.h>

#include "listAsLinkedList.h"

typedef LinkedList StackAsLinkedList;  // define Stack datatype as LinkedList

/** stackPush()
 * @brief - puts an element onto the top of the stack
 * @param element - ptr to thethe value to push onto the stack
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. stack before element added
 * @post  - stack one element taller
 */
void stackPush(StackAsLinkedList* stack, void* element, ElementType type);

/** stackPop()
 * @brief  - pops an element off the stack
 * @param  stack - a ptr to the stack structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the top of the stack on success, NULL on failure
 * @pre    - stack before top element removed; type to be modified unchanged
 * @post   - stack one element element shorter; node type updated; ptr to element returned
 */
void* stackPop(StackAsLinkedList* stack, ElementType* type);

/** stackIsEmpty()
 * @brief  - determines if the stack is empty
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is empty or false
 * @pre    - stack unmodified
 * @post   - stack unmodified; and empty status returned
 */
bool stackIsEmpty(StackAsLinkedList* stack);

/** stackIsFull()
 * @brief - determines if the stack is full
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is full or false
 * @pre    - stack unmodified
 * @post   - stack unmodified; always returns false
 */
bool stackIsFull(StackAsLinkedList* stack);

/** stackInit()
 * @brief  - initializes the stack structure
 * @return - pointer to stack
 * @pre    - nothing
 * @post   - new empty stack returned
 */
StackAsLinkedList* stackInit();

/** deleteLinkedList(()
 * @brief  - deletes stack, freeing all memory used
 * @param stack - a ptr to the stack structure
 * @pre    - unmodified stack
 * @post   - the stack is erased
 */
void deleteStack(StackAsLinkedList* stack);

/** stackPeek()
 * @brief  - returns the item on the top of the
 *           stack but doesn't remove it
 * @param stack - a ptr to the stack structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr the item on the top of the stack; NULL on failure
 * @pre    - stack unmodified; type to be updated unchanged
 * @post   - stack unmodified; ptr to top element returned;
 *           type updated with the type of element being returned
 */
void* stackPeek(StackAsLinkedList* stack, ElementType* type);

/** stackSize()
 * @brief  - determines the size of the stack
 * @param stack - a ptr to the stack structure
 * @return - number of items in the stack
 * @pre    - stack unmodified
 * @post   - stack unmodified; size of stack returned
 */
int stackSize(StackAsLinkedList* stack);

/** stackPrint()
 * @brief  - outputs the stack to the console
 * @param stack - the stack structure
 * @pre    - stack unmodified
 * @post   - stack unmodified; stack elements printed
 */
void stackPrint(StackAsLinkedList* stack);

#endif  // STACKASLINKEDLIST_H
