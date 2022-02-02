/** queueAsLinkedList.c
 * ===========================================================
 * Name: Student
 * Section:
 * Project: PEX 3 - RPN Calculator
 * Purpose: Queue ADT library - FIFO
 * ===========================================================
 */
#include "queueAsLinkedList.h"

void queueEnqueue(QueueAsLinkedList* queue, void* element, ElementType type){
    appendElementLinkedList((LinkedList*)queue, element, type);
    return;
}

//redo this one

void* queueDequeue(QueueAsLinkedList* queue, ElementType* type){
    void* node = getElementLinkedList((LinkedList*)queue, 0, type);
    deleteElementLinkedList((LinkedList*)queue, 0);
    return node;
}

bool queueIsEmpty(QueueAsLinkedList* queue){
    if(queue->numberOfElements == 0){
        return true;
    }else{
        return false;
    }
}

bool queueIsFull(QueueAsLinkedList* queue){
    return false;
}

QueueAsLinkedList* queueInit(){
    QueueAsLinkedList* queue = (QueueAsLinkedList*) createLinkedList();
    return queue;
}

void deleteQueue(QueueAsLinkedList* queue){
    deleteLinkedList((LinkedList*)queue);
    return;
}

void* queuePeek(QueueAsLinkedList* queue, ElementType* type){
    return getElementLinkedList((LinkedList*)queue, 0, type);
}

int queueSize(QueueAsLinkedList* queue){
    return lengthOfLinkedList((LinkedList*)queue);
}

void queuePrint(QueueAsLinkedList* queue){
    printLinkedList((LinkedList*)queue);
    return;
}