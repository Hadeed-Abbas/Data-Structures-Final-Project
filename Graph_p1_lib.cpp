#include<iostream>
#include "Graph_p1_lib.h"
using namespace std;

Node* adjList[MAX_CITIES];
double distanceList[MAX_CITIES];

void insert_edge(Node* adjList[], int src, int dest) {
    Node* new_node = new Node;
    new_node->city = dest;
    new_node->next = adjList[src];
    adjList[src] = new_node;
}

void print_path(int parent[], int src, int dest, City cities[]) {
    if (parent[dest] == -1) {
        cout << "Path does not exist between " << cities[src].name << " and " << cities[dest].name << "." << endl;
        return;
    }

    int path[MAX_CITIES];
    int path_index = 0;
    int current = dest;
    path[path_index] = dest;
    path_index++;

    while (parent[current] != -1) {
        path[path_index] = parent[current]; 
        path_index++;
        current = parent[current];
    }

    double totalDistance = 0;
    string completePath = "";

    for (int i = path_index - 1; i >= 0; i--) {
        if (i == path_index - 1) {
            completePath += cities[path[i]].name;
        }
        else {
            int dist = find_distance(distanceList, cities[path[i + 1]].name, cities[path[i]].name);
            if (dist != -1) {
                totalDistance += distanceList[dist];
                completePath += " -> " + string(cities[path[i]].name);
            }
        }
    }

    cout << "Path between " << cities[src].name << " and " << cities[dest].name << " (" << totalDistance;
    cout << " miles): " << completePath << endl;
}

void bfs(Node* adjList[], int src, int dest, City cities[], int n) {
    bool visited[MAX_CITIES] = { false };
    int parent[MAX_CITIES];
    for (int i = 0; i < MAX_CITIES; i++) {
        parent[i] = -1;
    }

    Queue* q = new Queue();
    q->front = q->rear = nullptr;
    visited[src] = true;
    enqueue(q, src);

    while (!isEmpty(q)) {

        int current = dequeue(q);
        Node* temp = adjList[current];

        while (temp) {
            int next = temp->city;
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = current;
                enqueue(q, next);
            }
            if (next == dest) {
                print_path(parent, src, dest, cities);
                return;
            }
            temp = temp->next;
        }
    }
    print_path(parent, src, dest, cities);

}

int hashFunction(char* city1, char* city2) {
    int sum = 0;
    for (int i = 0; city1[i]; i++) {
        sum += city1[i];
    }
    for (int i = 0; city2[i]; i++) {
        sum += city2[i];
    }
    return sum % MAX_CITIES;
}

int find_distance(double distanceList[], char* city1, char* city2) {
    int key = hashFunction(city1, city2);
    if (distanceList[key] != 0) {
        return key;
    }
    return -1;
}

int add_distance(double distanceList[], char* city1, char* city2, double distance) {
    int key = hashFunction(city1, city2);
    if (distanceList[key] == 0) {
        distanceList[key] = distance;
        return 0;
    }
    return -1;
}

Node* newNode(int data) {
    Node* temp = new Node;
    temp->city = data;
    temp->next = nullptr;
    return temp;
}


void enqueue(Queue* q, int data) {
    Node* temp = newNode(data);
    if (q->rear == nullptr) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == nullptr) {
        return -1; 
    }
    int data = q->front->city;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    delete temp;
    return data;
}

bool isEmpty(Queue* q) {
    return (q->front == nullptr);
}

