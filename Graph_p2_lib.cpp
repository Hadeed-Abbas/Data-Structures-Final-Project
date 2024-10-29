#include "Graph_p2_lib.h"
#include <cstring>

using namespace std;

Node* adjList[MAX_CITIES];
Distance distanceList[MAX_CITIES];

void insert_edge(Node* adjList[], int src, int dest) {
    Node* new_node = new Node;
    new_node->city = dest;
    new_node->next = adjList[src];
    adjList[src] = new_node;
}

void print_path(int parent[], int src, int dest, City cities[]) {
    if (parent[dest] == -1) {
        cout << "Path does not exist between " << cities[src].name;
        cout << " and " << cities[dest].name << "." << endl;
        return;
    }

    int path[MAX_CITIES];
    int pathIndex = 0;
    int current = dest;
    path[pathIndex] = dest;
    pathIndex++;
    while (parent[current] != -1) {
        path[pathIndex] = parent[current]; pathIndex++;
        current = parent[current];
    }

    double totalDistance = 0;
    string completePath = "";

    for (int i = pathIndex - 1; i >= 0; i--) {
        if (i == pathIndex - 1) {
            completePath += cities[path[i]].name;
        }
        else {
            int distance_index = find_distance(distanceList, cities[path[i + 1]].name, cities[path[i]].name);
            if (distance_index != -1) {
                totalDistance += distanceList[distance_index].distance;
                completePath += " -> " + string(cities[path[i]].name);
            }
        }
    }

    cout << "Path between " << cities[src].name << " and " << cities[dest].name;
    cout << " (" << totalDistance << " miles): " << completePath << endl;
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

int add_distance(Distance distanceList[], char* city1, char* city2, double distance) {
    int key = hashFunction(city1, city2);
    int originalKey = key;

    while (distanceList[key].distance != 0) {
        if (strcmp(city1, distanceList[key].city1) == 0 && strcmp(city2, distanceList[key].city2) == 0) {
            return -1;
        }
        key = (key + 1) % MAX_CITIES;
        if (key == originalKey) {
            return -1;
        }
    }
    if (distanceList[key].city1 != nullptr) {
        while (distanceList[key].city1 != nullptr) {
            key = (key + 1) % MAX_CITIES;
        }
    }

    distanceList[key].city1 = city1;
    distanceList[key].city2 = city2;
    distanceList[key].distance = distance;

    return 0;
}

int find_distance(Distance distanceList[], char* city1, char* city2) {
    int key = hashFunction(city1, city2);
    int originalKey = key;

    while (distanceList[key].distance != 0) {
        if (strcmp(city1, distanceList[key].city1) == 0 && strcmp(city2, distanceList[key].city2) == 0) {
            return key;
        }
        key = (key + 1) % MAX_CITIES; 
        if (key == originalKey) {
            break;
        }
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

void display_edges_and_cities(Node* adjList[], City cities[], int num_cities) {
    cout << endl << "Cities:" << endl;
    for (int i = 0; i < num_cities; i++) {
        cout << cities[i].name << " - " << cities[i].index << endl;
    }

    cout << endl << "Roads: " << endl;

    for (int i = 0; i < num_cities; i++) {
        Node* current = adjList[i];
        while (current != nullptr) {
            cout << cities[i].name << "(Index: " << cities[i].index << ") " << " -> ";
            cout << cities[current->city].name << "(Index: " << cities[current->city].index << ") " << endl;
            current = current->next;
        }
    }
}

int findCityIndex(char* c, City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        if (strcmp(cities[i].name, c) == 0) {
            return cities[i].index;
        }
    }
    return -1;
}

void displayMenu() {
    cout << "--- MENU ---" << endl;
    cout << "1. Find path between two cities" << endl;
    cout << "2. Add distance between two cities" << endl;
    cout << "3. Display cities and Routes" << endl;
    cout << "0. Exit" << endl;
}

void handleMenuChoice(int choice, City cities[], int n) {
    switch (choice) {
    case 1: {
        char s[50], d[50]; 
        cout << "Enter source city name: ";
        cin >> s;
        int src = findCityIndex(s, cities, n);
        cout << "Enter destination city name: ";
        cin >> d;
        int dest = findCityIndex(d, cities, n);
        if (src == -1 || dest == -1) {
            cout << "Invalid city name entered." << endl;
        }
        else {
            bfs(adjList, src, dest, cities, n);
        }
        break;
    }
    case 2: {
        display_edges_and_cities(adjList, cities, n);
        cout << "Enter first city index: ";
        int city1;
        cin >> city1;
        cout << "Enter second city index: ";
        int city2;
        cin >> city2;
        cout << "Enter distance between the cities: ";
        double distance;
        cin >> distance;
        insert_edge(adjList, city1, city2);
        int result = add_distance(distanceList, cities[city1].name, cities[city2].name, distance);
        if (result == -1) {
            cout << "Collision occurred. Distance not added." << endl;
        }
        else {
            cout << "Distance added successfully." << endl;
        }
        break;
    }
    case 3: {
        display_edges_and_cities(adjList, cities, n);
        break;
    }
    case 0: {
        cout << "Exiting program. Goodbye!" << endl;
        break;
    }
    default: {
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
    }
}

void cleanup(Node* adjList[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        Node* current = adjList[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}