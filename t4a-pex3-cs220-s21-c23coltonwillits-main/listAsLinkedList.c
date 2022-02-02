/** listAsLinkedList.c
 * ===========================================================
 * Name: Colton Willits
 * Section: T4A
 * Project: PEX 3 - RPN Calculator
 * Purpose: List ADT as linked list
 * ===========================================================
 */

#include "listAsLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->numberOfElements = 0;
    list->tail = NULL;
    return list;
}

void deleteLinkedList(LinkedList* list) {
    Node* x = list->head;
    Node* temp = x->next;
    while (x->next != NULL) {
        temp = x->next;
        free(x);
        x = temp;
    }
    // free list memory block
    free(list);
    return;
}

void appendElementLinkedList(LinkedList* list, void* element, ElementType type) {
    Node* node = NULL;
    node = (Node*)malloc(sizeof(Node));
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* prev_node = list->tail;
        prev_node->next = node;
    }
    list->tail = node;
    node->data = element;
    node->next = NULL;
    node->type = type;
    list->numberOfElements++;
    return;
}

int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}

void printLinkedList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->type == REAL_NUMBER) {
            printf("%.3lf -> ", *((double*) temp->data));
        } else {
            switch (*((operators*)temp->data)) {
                case add:
                    printf("+ -> ");
                    break;
                case subtract:
                    printf("- -> ");
                    break;
                case multiply:
                    printf("* -> ");
                    break;
                case divide:
                    printf("/ -> ");
                    break;
                case power:
                    printf("^ -> ");
                    break;

                default:
                    break;
            }
        }

        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

void* getElementLinkedList(LinkedList* list, int position, ElementType* type1) {
    Node* temp = list->head;
    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            i = position;
        } else {
            temp = temp->next;
        }
    }
    if(temp == NULL){
        *type1 = (ElementType) NULL;
        return NULL;
    }else{
        *type1 = (ElementType) temp->type;
        return temp->data;
    }

}

void deleteElementLinkedList(LinkedList* list, int position) {
    Node* temp = list->head;
    Node* prev_node = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev_node = temp;
        temp = temp->next;
    }
    if (prev_node != NULL)
    {
        prev_node->next = temp->next;
    }
    //free(temp);
    list->numberOfElements--;
    return;
}

void insertElementLinkedList(LinkedList* list, int position, void* element, ElementType type) {
    Node* new_node = NULL;
    new_node = (Node*)malloc(sizeof(Node*));
    new_node->data = element;
    new_node->type = type;
    Node* prev_node = list->head;
    
    for (int i = 0; i < position - 1; i++) {
        prev_node = prev_node->next;
    }
    if(list->head == NULL){
        list->head = new_node;
        list->tail = new_node;
    }else if (position == 0)
    {
        new_node->next = prev_node;
        list->head = new_node;
    }else{
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    list->numberOfElements++;
}

void changeElementLinkedList(LinkedList* list, int position, void* newElement, ElementType type) {
    Node* node = list->head;
    for (int i = 0; i < position; i++) {
        node = node->next;
    }
    node->data = newElement;
    node->type = type;
    return;
}

bool isEmpty(LinkedList* list){
    if(list->numberOfElements == 0){
        return true;
    } else {
        return false;
    }
}