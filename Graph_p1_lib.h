#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CITIES 50

// City structure
typedef struct {
    char name[50];
    int index;
} City;

// Node structure
typedef struct node {
    int city;
    struct node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front, * rear;
} Queue;

// Global variables
extern Node* adjList[MAX_CITIES];
extern double distanceList[MAX_CITIES];

/*
Function: insert_edge
Process: This function inserts an edge between two vertices in the adjacency list
Input data (parameter): adjList (adjacency list), src (source vertex), dest (destination vertex)
Output data (parameter): None
Output data (return): None
Dependencies: None
Complexity: O(1)
*/
void insert_edge(Node* adjList[], int src, int dest);

/*
Function: print_path
Process: This function prints the path between two cities and the total distance
Input data (parameter): parent (parent array from BFS), src (source city index), dest (destination city index), cities (array of cities)
Output data (parameter): None
Output data (return): None
Dependencies: find_distance
Complexity: O(n), where n is the number of cities in the path
*/
void print_path(int parent[], int src, int dest, City cities[]);

/*
Function: bfs
Process: This function implements the Breadth-First Search algorithm to find the path between two cities
Input data (parameter): adjList (adjacency list), src (source city index), dest (destination city index), cities (array of cities), n (number of cities)
Output data (parameter): None
Output data (return): None
Dependencies: print_path, createQueue, enqueue, dequeue, isEmpty
Complexity: O(V + E), where V is the number of vertices (cities) and E is the number of edges
*/
void bfs(Node* adjList[], int src, int dest, City cities[], int n);

/*
Function: hashFunction
Process: This function calculates a hash key for a pair of cities. It adds the ascii values of both cities
Input data (parameter): city1 (name of first city), city2 (name of second city)
Output data (parameter): None
Output data (return): hash key (integer)
Dependencies: None
Complexity: O(m + n), where m and n are the lengths of the city names
*/
int hashFunction(char* city1, char* city2);

/*
Function: find_distance
Process: This function finds the distance between two cities in the distanceList array
Input data (parameter): distanceList (array of distanceList), city1 (name of first city), city2 (name of second city)
Output data (parameter): None
Output data (return): Index of the distance in the distanceList array, or -1 if not found
Dependencies: hashFunction
Complexity: O(1)
*/
int find_distance(double distanceList[], char* city1, char* city2);

/*
Function: add_distance
Process: Adds the distance between two cities to the distanceList array
Input data (parameter): distanceList (array of distanceList), city1 (name of first city), city2 (name of second city), distance (distance between the cities)
Output data (parameter): None
Output data (return): 0 if successful, -1 if collision
Dependencies: hashFunction
Complexity: O(1)
*/
int add_distance(double distanceList[], char* city1, char* city2, double distance);

// Following are the helper functions for the queue


/*
Function: newNode
Process: This fucntion will create a  new node for the queue.
Input data (parameter): data: The value that will be stored in the node
Output data (parameter): None
Output data (return): Pointer to the new node
Dependencies: None
Complexity: O(1)
*/
Node* newNode(int data);

/*
Function: enqueue
Process: This function adds an element in the queue
Input data (parameter): _queue (pointer to the queue), data (value to be added)
Output data (parameter): None
Output data (return): None
Dependencies: newNode
Complexity: O(1)
*/
void enqueue(Queue* _queue, int data);

/*
Function: dequeue
Process: This function removes an element from the front of the queue
Input data (parameter): _queue (pointer to the queue)
Output data (parameter): None
Output data (return): Value of the dequeued element, or -1 if the queue is empty
Dependencies: None
Complexity: O(1)
*/
int dequeue(Queue* _queue);

/*
Function: isEmpty
Process: This function checks if the queue is empty
Input data (parameter): _queue (pointer to the queue)
Output data (parameter): None
Output data (return): true if the queue is empty, false otherwise
Dependencies: None
Complexity: O(1)
*/
bool isEmpty(Queue* _queue);

