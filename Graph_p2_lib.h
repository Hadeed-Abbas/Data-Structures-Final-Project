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

// Define the Distance struct
typedef struct {
    char* city1;
    char* city2;
    int cities_key;
    int distance;
} Distance;

extern Node* adjList[MAX_CITIES];
extern Distance distanceList[MAX_CITIES]; 

/*
Function: insert_edge
Process: This function inserts an edge (road) between two cities in the adjacency list
Input data (parameter): Node* adjList[] (adjacency list), int src (source city index), int dest (destination city index)
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(1)
*/
void insert_edge(Node* adjList[], int src, int dest);

/*
Function: print_path
Process: This function prints the path between two cities and the total distance
Input data (parameter): int parent[] (parent array from BFS), int src (source city index), int dest (destination city index), City cities[] (array of cities)
Output data(parameter): None
Output data (return): None
Dependencies: find_distance
Complexity: O(n), where n is the length of the path
*/
void print_path(int parent[], int src, int dest, City cities[]);

/*
Function: bfs
Process: This function performs Breadth-First Search (BFS) to find the shortest path between two cities
Input data (parameter): Node* adjList[] (adjacency list), int src (source city index), int dest (destination city index), City cities[] (array of cities), int n (number of cities)
Output data(parameter): None
Output data (return): None
Dependencies: enqueue, dequeue, isEmpty, print_path
Complexity: O(V + E), where V is the number of cities and E is the number of roads
*/
void bfs(Node* adjList[], int src, int dest, City cities[], int n);

/*
Function: hashFunction
Process: This function calculates the hash key for a pair of city names
Input data (parameter): char* city1 (name of first city), char* city2 (name of second city)
Output data(parameter): None
Output data (return): int (hash key)
Dependencies: None
Complexity: O(m + n), where m and n are the lengths of the city names
*/
int hashFunction(char* city1, char* city2);

/*
Function: add_distance
Process: This function adds the distance between two cities in the distance list (hash table)
Input data (parameter): Distance distanceList[] (distance list), char* city1 (name of first city), char* city2 (name of second city), double distance (distance between cities)
Output data(parameter): None
Output data (return): int (0 if distance added successfully, -1 if collision occurred or hash table is full)
Dependencies: hashFunction
Complexity: O(1) on average, O(n) in the worst case (when all slots are occupied and linear probing is used)
*/
int add_distance(Distance distanceList[], char* city1, char* city2, double distance);

/*
Function: find_distance
Process: This function finds the distance between two cities in the distance list (hash table)
Input data (parameter): Distance distanceList[] (distance list), char* city1 (name of first city), char* city2 (name of second city)
Output data(parameter): None
Output data (return): int (index of the distance in the distance list, -1 if the distance not found)
Dependencies: hashFunction
Complexity: O(1) on average, O(n) in the worst case (when all slots are occupied and linear probing is used)
*/
int find_distance(Distance distanceList[], char* city1, char* city2);

/*
Function: newNode
Process: This function creates a new node for the queue
Input data (parameter): int data (data to be stored in the node)
Output data(parameter): None
Output data (return): Node* (pointer to the new node)
Dependencies: None
Complexity: O(1)
*/
Node* newNode(int data);

/*
Function: enqueue
Process: This function enqueues an element into the queue
Input data (parameter): Queue* q (pointer to the queue), int data (data to be enqueued)
Output data(parameter): None
Output data (return): None
Dependencies: newNode
Complexity: O(1)
*/
void enqueue(Queue* q, int data);

/*
Function: dequeue
Process: This function dequeues an element from the queue
Input data (parameter): Queue* q (pointer to the queue)
Output data(parameter): None
Output data (return): int (data of the dequeued element, -1 if queue is empty)
Dependencies: None
Complexity: O(1)
*/
int dequeue(Queue* q);

/*
Function: isEmpty
Process: This function checks if the queue is empty
Input data (parameter): Queue* q (pointer to the queue)
Output data(parameter): None
Output data (return): bool (true if queue is empty, false otherwise)
Dependencies: None
Complexity: O(1)
*/
bool isEmpty(Queue* q);

/*
Function: display_edges_and_cities
Process: This function displays the list of cities and roads (edges) in the graph
Input data (parameter): Node* adjList[] (adjacency list), City cities[] (array of cities), int num_cities (number of cities)
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(V + E), where V is the number of cities and E is the number of roads
*/
void display_edges_and_cities(Node* adjList[], City cities[], int num_cities);

/*
Function: findCityIndex
Process: This function converts a city name to its corresponding index
Input data (parameter): char* c (city name), City cities[] (array of cities), int num_cities (number of cities)
Output data(parameter): None
Output data (return): int (index of the city, -1 if city not found)
Dependencies: None
Complexity: O(n), where n is the number of cities
*/
int findCityIndex(char* c, City cities[], int num_cities);

/*
Function: displayMenu
Process: This function displays the menu options
Input data (parameter): None
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(1)
*/
void displayMenu();

/*
Function: handleMenuChoice
Process: This function handles the user's menu choice and performs the corresponding operation
Input data (parameter): int choice (user's menu choice), City cities[] (array of cities), int n (number of cities)
Output data(parameter): None
Output data (return): None
Dependencies: findCityIndex, bfs, display_edges_and_cities, insert_edge, add_distance
Complexity: Depends on the chosen option:
            Case 1: O(V + E + n), where V is the number of cities, E is the number of roads, and n is the length of the path
            Case 2: O(V + E)
            Case 3: O(V + E)
            Case 0 and default: O(1)
*/
void handleMenuChoice(int choice, City cities[], int n);

/*
Function: cleanup
Process: This function deallocates the memory used by the adjacency list
Input data (parameter): Node* adjList[] (adjacency list), int num_cities (number of cities)
Output data(parameter): None
Output data (return): None
Dependencies: None
Complexity: O(V + E), where V is the number of cities and E is the number of roads
*/
void cleanup(Node* adjList[], int num_cities);