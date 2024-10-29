#include "search_lib_BST.h"
#include <iostream>
using namespace std;

const string inputFilename = "myData_CS2001.csv";
const string outputFilename = "../output.csv";

int main() {
    // Creating Tree
    TreeNode* root = createTree();
    // Saving data from file to tree
    root = getData(inputFilename);
    //  printTree(root);
    // Validating whether the data was created as a BST or not.
    // Removed the condition of equality
    bool isBST = validateTree(root);
    if (isBST) {
        cout << "The data was created as a binary search tree." << endl;
    }
    else {
        cout << "The data was not created as a binary search tree." << endl;
    }

    // Examples check
    int firstOccurrence232 = getFirstOccurrence(232, root);
    cout << "First occurrence of 232: " << firstOccurrence232 << endl;

    int lastOccurrence232 = getLastOccurrence(232, root);
    cout << "Last occurrence of 232: " << lastOccurrence232 << endl;

    // Took max_size 3000
    const int MAX_SIZE = 3000;
    int occurrences[MAX_SIZE];
    int numOccurrences = 0;

    dtype elementToFind = 232;

    getAllOccurrences(elementToFind, root, occurrences, &numOccurrences);

    cout << "Number of occurrences of " << elementToFind << ": " << numOccurrences << endl;
    cout << "Indices of occurrences: ";
    for (int i = 0; i < numOccurrences; i++) {
        cout << occurrences[i] + 1 << " ";
    }
    cout << endl;

    // The following is to save data again in a csv 
    //  cout << endl << "Saving data: " << endl;

     //  saveData(outputFilename, root);

    return 0;
}