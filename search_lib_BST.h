#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef long int dtype;

// TreeNode structure
typedef struct TreeNode{
    dtype data;
    TreeNode* left;
    TreeNode* right;
    int index;
} TreeNode;

// Node structure
typedef struct Node{
    TreeNode* nodeData;
    Node* next;
} Node;

// Stack structure
typedef struct Stack{
    int top;
    Node* head;
} Stack;

// Function headers

// Function: createTree
// Process: This fucntion creates an empty binary search tree
// Input data (parameter): None
// Output data (parameter): None
// Output data (return): pointer to the root node (NULL when tree is empty)
// Dependencies: None
// Complexity: O(1)

TreeNode* createTree();

/*
Function: printTree
Process: This function prints elements of a binary search tree based on preorder traversal
Input data (parameter): pointer to the root of a BST
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(n)
*/
void printTree(TreeNode* root);

/*
Function: addNode
Process: This function adds a node with specified data and index to a binary search tree
Input data (parameter): pointer to the root of a BST (root), data to be inserted (data), index of the data(index)
Output data(parameter): None
Output data (return): pointer to the inserted node
Dependencies: None
Complexity: O(log n) in average case
*/
TreeNode* addNode(TreeNode* root, dtype data, int index);

/*
Function: getData
Process: This function reads data from a .csv file and populates a binary search tree
Input data (parameter): file name (string constant)
Output data(parameter): file name
Output data (return): pointer to the root of the populated tree
Dependencies: createTree, addNode
Complexity: O(n log n) in average case
*/
TreeNode* getData(const string& fileName);

/*
Function: saveData
Process: This function saves data from a binary search tree to a .csv file in preorder traversal
Input data (parameter): file name, pointer to the BST
Output data(parameter): fileName
Output data (return): None
Dependencies: saveDataHelper
Complexity: O(n)
*/
void saveData(const string& fileName, TreeNode* root);

/*
Function: getFirstOccurrence
Process: This function finds the index of the first occurrence of an element in a BST
Input data (parameter): element, pointer to the root of a BST
Output data(parameter): None
Output data (return): index of the first occurrence
Dependencies: None
Complexity: O(log n) in average case
*/
int getFirstOccurrence(dtype element, TreeNode* root);

/*
Function: getLastOccurrence
Process: This function finds the index of the last occurrence of an element in a BST
Input data (parameter): element, pointer to the root of a BST
Output data(parameter): None
Output data (return): index of the last occurrence
Dependencies: None
Complexity: O(log n) in average case
*/
int getLastOccurrence(dtype element, TreeNode* root);

/*
Function: getAllOccurrences
Process: This function finds all occurrences of an element in a BST and stores them in an array
Input data (parameter): element, pointer to the root of a BST, pointer to array of occurrences, pointer to numOccurrences
Output data(parameter): occurrences, numOccurrences
Output data (return): None
Dependencies: None
Complexity: O(n)
*/
void getAllOccurrences(dtype element, TreeNode* root, int* occurrences, int* numOccurrences);

/*
Function: validateTree
Process: This function validates whether a binary tree is a binary search tree
Input data (parameter): pointer to the root of a tree
Output data(parameter): None
Output data (return): boolean indicating whether the tree is a BST or not
Dependencies: createStack, push, pop, isEmptyStack
Complexity: O(n)
*/
bool validateTree(TreeNode* root);

//Following are the helper functions for the code. It has a stack and savedatahelper
/*
Function: saveDataHelper
Process: Helper function that saves data from a binary search tree to a .csv file in preorder traversal
Input data (parameter): file name, pointer to the BST
Output data(parameter): file (variable name of saved file)
Output data (return): None
Dependencies: None
Complexity: O(n)
*/
void saveDataHelper(fstream& file, TreeNode* root);

/*
Function: createStack
Process: creates an empty stack
Input data (parameter): None
Output data(parameter): None
Output data (return): pointer to the created stack
Dependencies: None
Complexity: O(1)
*/
Stack* createStack();

/*
Function: push
Process: pushes a node onto the stack
Input data (parameter): pointer to the stack, data to be pushed
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(1)
*/
void push(Stack* stack, TreeNode* node);

/*
Function: pop
Process: pops a node from the stack
Input data (parameter): pointer to the stack
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(1)
*/
TreeNode* pop(Stack* stack);

/*
Function: isEmptyStack
Process: checks if the stack is empty
Input data (parameter): pointer to the stack
Output data(parameter): None
Output data (return): boolean indicating whether the stack is empty or not
Dependencies: None
Complexity: O(1)
*/
bool isEmptyStack(Stack* stack);