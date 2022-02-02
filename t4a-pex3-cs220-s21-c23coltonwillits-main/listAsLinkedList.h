/** listAsLinkedList.h
 * ===========================================================
 * Name: Student
 * Section:
 * Project: PEX 3 - RPN Calculator
 * Purpose: List ADT as linked list
 * ===========================================================
 */

#ifndef LISTASLINKEDLIST_H
#define LISTASLINKEDLIST_H
#include <stdbool.h>

// define node type enum

typedef enum { REAL_NUMBER, MATH_OPERATOR } ElementType;

typedef enum {add, subtract, multiply, divide, power} operators;

// define a node of the linked list
typedef struct Node_struct {
    void* data;        // ptr to data of any type
    ElementType type;  // the element type; number or operator
    struct Node_struct* next;
} Node;

// define the type (meta-data) that manages the linked list of nodes
typedef struct LinkedList_struct {
    Node* head;
    Node* tail;
    int numberOfElements;
} LinkedList;

// Functions that manipulate a linked list

/** createLinkedList()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 * @pre    - nothing
 * @post   - new empty linked list returned
 */
LinkedList* createLinkedList();

/** deleteLinkedList(()
 * @brief  - deletes linked list, freeing all memory used
 * @param list - a ptr to the linked list structure
 * @pre    - unmodified linked list
 * @post   - the linked list is erased, all elements freed
 */
void deleteLinkedList(LinkedList* list);

/** appendElementLinkedList()
 * @brief - addes a new element to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param element - ptr to the value to append to the list
 * @param type - enum ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. linked list before element added
 * @post  - modified linked list; node with pointer to element added
 */
void appendElementLinkedList(LinkedList* list, void* element, ElementType type);

/** lengthOfLinkedList()
 * @brief  - returns the size of the linked list
 * @param list - a ptr to the linked structure
 * @return - number of items in the linked list
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; size of linked list returned
 */
int lengthOfLinkedList(LinkedList* list);

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; linked list elements printed
 */
void printLinkedList(LinkedList* list);

/** getElementLinkedList()
 * @brief  - retrieves element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - value at 'position', NULL on failure
 * @pre    - unmodified linked list; unmodified element type to be updated
 * @post   - unmodified linked list; pointer to element at 'position' returned;
 *           type updated
 */
void* getElementLinkedList(LinkedList* list, int position, ElementType* type);

/** deleteElementLinkedList()
 * @brief  - deletes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete
 * @pre    - unmodified linked list
 * @post   - modified linked list; node at 'position' removed;
 *           element of node being removed is freed;
 *           node removed is freed
 */
void deleteElementLinkedList(LinkedList* list, int position);

/** insertElementLinkedList()
 * @brief  - adds element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - ptr to value to be added
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre    - 1. void* pointing to dynamically allocated element
 *           2. linked list before element added
 * @post   - modified linked list; node with pointer to element added at 'position'
 */
void insertElementLinkedList(LinkedList* list, int position, void* element, ElementType type);

/** changeElementLinkedList()
 * @brief  - changes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - ptr to new value
 * @param  type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre    - 1. void* pointing to dynamically allocated element
 *           2. linked list before element added
 * @post   - 1. modified linked list; node changed at 'position' with new pointer to a new element
 *           2. memory allocated to previous element freed
 */
void changeElementLinkedList(LinkedList* list, int position, void* newElement, ElementType type);

bool isEmpty(LinkedList* list);
#endif  // LISTASLINKEDLIST_H
