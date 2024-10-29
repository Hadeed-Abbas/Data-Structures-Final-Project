#include <iostream>
#include <cstring>
#include "Graph_p1_lib.h"
using namespace std;

int main() {
    City cities[] = {
         {"Islamabad", 0},
         {"Chakwal", 1},
         {"Rawalpindi", 2},
         {"Quetta", 3},
         {"Karachi", 4},
         {"Lahore", 5}
    };

    int n = sizeof(cities) / sizeof(cities[0]);

    for (int i = 0; i < MAX_CITIES; i++) {
        adjList[i] = nullptr;
    }

    // Adding edges
    // Islamabad - Quetta
    // Quetta - Karachi
    // Karachi - Lahore
    // Lahore - Islamabad
    // Islamabad - Rawalpindi
    insert_edge(adjList, 0, 3); 
    insert_edge(adjList, 3, 4);
    insert_edge(adjList, 4, 5);
    insert_edge(adjList, 5, 1);
    insert_edge(adjList, 0, 2); 

    // Adding accurate distance from google
    add_distance(distanceList, cities[0].name, cities[3].name, 894.3);
    add_distance(distanceList, cities[3].name, cities[4].name, 685.4);
    add_distance(distanceList, cities[4].name, cities[5].name, 1211.4);
    add_distance(distanceList, cities[5].name, cities[1].name, 376.6);
    add_distance(distanceList, cities[0].name, cities[2].name, 24.1);
    // Running bfs
    bfs(adjList, 0, 1, cities, n); 
    bfs(adjList, 1, 0, cities, n); 
    bfs(adjList, 0, 2, cities, n); 

    return 0;
}