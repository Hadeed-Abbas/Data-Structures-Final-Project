#include <iostream>
#include <cstring>
#include "Graph_p2_lib.h"
using namespace std;




int main() {
    for (int i = 0; i < MAX_CITIES; i++) {
        distanceList[i].city1 = nullptr;
        distanceList[i].city2 = nullptr;
        distanceList[i].distance = 0;
    }

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

    insert_edge(adjList, 0, 3);
    insert_edge(adjList, 3, 4);
    insert_edge(adjList, 4, 5);
    insert_edge(adjList, 5, 1);
    insert_edge(adjList, 0, 2);
    insert_edge(adjList, 1, 0);
    insert_edge(adjList, 0, 1);




    add_distance(distanceList, cities[0].name, cities[3].name, 894.3);
    add_distance(distanceList, cities[3].name, cities[4].name, 685.4);
    add_distance(distanceList, cities[4].name, cities[5].name, 1211.4);
    add_distance(distanceList, cities[5].name, cities[1].name, 376.6);
    add_distance(distanceList, cities[0].name, cities[2].name, 24.1);
    add_distance(distanceList, cities[1].name, cities[0].name, 24.1);
    add_distance(distanceList, cities[0].name, cities[1].name, 24.1);

    // display_edges_and_cities(adjList, cities, n);
    // cout<<hashFunction(cities[0].name, cities[1].name)<<endl;
    // cout<<hashFunction(cities[1].name, cities[0].name);


    int choice;
    do {
        int n = sizeof(cities) / sizeof(cities[0]);
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice < 0 || choice > 3) {
            cout << "Invalid choice. Please enter a number between 0 and 3." << endl;
            continue; 
        }

        handleMenuChoice(choice, cities, n);

    } while (choice != 0);

    cleanup(adjList, n);

    return 0;
}

