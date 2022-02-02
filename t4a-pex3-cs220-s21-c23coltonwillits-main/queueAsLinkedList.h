/** queueAsLinkedList.h
 * ===========================================================
 * Name: Student
 * Section:
 * Project: PEX 3 - RPN Calculator
 * Purpose: Queue ADT library - FIFO
 * ===========================================================
 */

#ifndef QUEUEASLIST_H
#define QUEUEASLIST_H
#include <stdbool.h>
#include <stddef.h>

#include "listAsLinkedList.h"

typedef LinkedList QueueAsLinkedList;

/** queueEnqueue()
 * @brief - puts an element onto the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - ptr to the value to add to the back of the queue
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. queue before element added
 * @post  - queue one element longer
 */
void queueEnqueue(QueueAsLinkedList* queue, void* element, ElementType type);

/** queueDequeue()
 * @brief - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the value removed, type void*; NULL on failure
 * @pre   - queue before element removed from the front; type to be updated unmodified
 * @post  - queue one element shorter; node type updated; ptr to element returned
 */
void* queueDequeue(QueueAsLinkedList* queue, ElementType* type);

/** queueIsEmpty()
 * @brief  - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; and empty status returned
 */
bool queueIsEmpty(QueueAsLinkedList* queue);

/** queueIsFull()
 * @brief - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; always returns false
 */
bool queueIsFull(QueueAsLinkedList* queue);

/** queueInit()
 * @brief  - initializes the queue structure
 * @return - pointer to queue
 * @pre    - nothing
 * @post   - ptr to new empty queue returned
 */
QueueAsLinkedList* queueInit();

/** deleteQueue()
 * @brief  - deletes queue, freeing all memory used
 * @param queue - a ptr to the queue structure
 * @pre    - unmodified queue
 * @post   - the queue is erased, all elements freed
 */
void deleteQueue(QueueAsLinkedList* queue);

/** queuePeek()
 * @brief  - returns the item in the front of the
 *           queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the value at the front of the queue, type void*;
 *           NULL if queue is empty
 * @pre    - queue unmodified; type to be updated unmodified
 * @post   - queue unmodified; ptr to front element returned;
 *           type updated with the type of element being returned
 */
void* queuePeek(QueueAsLinkedList* queue, ElementType* type);

/** queueSize()
 * @brief  - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 * @pre    - queue unmodified
 * @post   - queue unmodified; size of queue returned
 */
int queueSize(QueueAsLinkedList* queue);

/** queuePrint()
 * @brief  - outputs the queue to the console
 * @param queue - the queue structure
 * @pre    - queue unmodified
 * @post   - queue unmodified; queue elements printed
 */
void queuePrint(QueueAsLinkedList* queue);

#endif  // QUEUEASLIST_H
