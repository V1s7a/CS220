/** stackAsLinkedList.c
 * ===========================================================
 * Name: Student
 * Section:
 * Project: PEX 3 - RPN Calculator
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */
#include "stackAsLinkedList.h"

void stackPush(StackAsLinkedList* stack, void* element, ElementType type){
    insertElementLinkedList((LinkedList*)stack, 0, element, type);
    return;
}

void* stackPop(StackAsLinkedList* stack, ElementType* type){
    void* node = getElementLinkedList((LinkedList*)stack, 0, type);
    deleteElementLinkedList((LinkedList*)stack, 0);
    return node;
}

bool stackIsEmpty(StackAsLinkedList* stack){
    if(stack->numberOfElements == 0){
        return true;
    }else{
        return false;
    }
}

bool stackIsFull(StackAsLinkedList* stack){
    return false;
}

StackAsLinkedList* stackInit(){
    return (StackAsLinkedList*) createLinkedList();
}

void deleteStack(StackAsLinkedList* stack){
    deleteLinkedList((LinkedList*)stack);
}

void* stackPeek(StackAsLinkedList* stack, ElementType* type){
    return getElementLinkedList((LinkedList*)stack, 0 , type);
}

int stackSize(StackAsLinkedList* stack){
    return stack->numberOfElements;

}

void stackPrint(StackAsLinkedList* stack){
    printLinkedList((LinkedList*)stack);
}