/** ternaryTree.h
 * ===========================================================
 * Name: last first
 * Section: 
 * Project: PEX4
 * Purpose: Use a ternary tree hold a dictionary for a spell checker
 * ===========================================================
 */
#ifndef TERNARYTREE_H
#define TERNARYTREE_H

#include "wordList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//create structure for tree and nodes
typedef struct node_struct {
    char letter;
    struct node_struct* leftChild;
    struct node_struct* middleChild;
    struct node_struct* rightChild;
} node;

typedef  struct ternaryTree_struct {
    node* root;
} ternaryTree;

/** plantTree()
 * @brief  - initializes the tree structure structure
 * @return - pointer to tree structure
 * @pre    - nothing
 * @post   - new empty tree structure returned
 */
ternaryTree* plantTree();;

/** treeRemovalService()
 * @brief  - deletes tree structure, freeeing all memory used
 * @return - Nothing
 * @param tree - tree to be deleted
 * @pre    - nothing
 * @post   - tree structure uprooted and removed.
 */
void treeRemovalService(ternaryTree* tree);

/** branchRemoval()
 * @brief  - deletes nodes from tree recursively, freeing all memory used
 * @return - Nothing
 * @param node - starting node
 * @pre    - nothing
 * @post   - branches removed from tree.
 */
void branchRemoval(node* node);

/** growBranch()
 * @brief  - creates new node
 * @return - Nothing
 * @param letter - the character to be assigned
 * @pre    - nothing
 * @post   - branches removed from tree.
 */
node* growBranch(char letter);

/** growTree()
 * @brief  - inserts new word into tree
 * @return - Nothing
 * @pre    - nothing
 * @post   - tree structure should be larger.
 */
void growTree(ternaryTree* tree, char* word);

/** spellCheck()
 * @brief  - compares spelling of word to dictionary words
 * @param tree - a pointer to the tree structure
 * @param word - word to be spell checked
 * @return - truth value
 * @pre    - nothing
 * @post   - return if the word is spelled correctly via truth value
 */
bool spellCheck(ternaryTree* tree, char* word);

/** sortList()
 * @brief  - compares spelling of word to dictionary words
 * @param list - a word list structure
 * @param sorted - address to the sorted wordlist that is pass by reference
 * @param length - length of the list
 * @return - truth value
 * @pre    - nothing
 * @post   - return if the word is spelled correctly via truth value
 */
void sortList(WordList* list, WordList* sorted, int length, int n);

void growTreeRecurse(node* currentNode, char* letter);

#endif  // TERNARYTREE_H