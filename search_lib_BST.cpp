#include "search_lib_BST.h"
#include <fstream>

TreeNode* createNode(dtype data, int index) {
    TreeNode* newNode = new TreeNode;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->index = index;
    return newNode;
}

TreeNode* addToBST(TreeNode* root, dtype data, int index) {
    if (root == nullptr) {
        return createNode(data, index);
    }
    if (data <= root->data) {
        root->left = addToBST(root->left, data, index);
    }
    else {
        root->right = addToBST(root->right, data, index);
    }
    return root;
}

TreeNode* createTree() {
    return nullptr;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

TreeNode* addNode(TreeNode* root, dtype data, int index) {
    return addToBST(root, data, index);
}

TreeNode* getData(const string& fileName) {
    fstream file(fileName);
    if (!file.is_open()) {
        cerr << "File could not be opened: " << endl;
    }
    TreeNode* root = createTree();
    dtype data;
    int index = 0;
    while (file >> data) {
        root = addNode(root, data, index++);
    }
    file.close();
    return root;
}

void saveData(const string& fileName, TreeNode* root) {
    fstream file(fileName, ios::binary | ios::out);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << endl;
        return;
    }

    saveDataHelper(file, root);

    file.close();
}

void saveDataHelper(fstream& file, TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    file << root->data << endl;
    saveDataHelper(file, root->left);
    saveDataHelper(file, root->right);
}

int getLastOccurrence(dtype element, TreeNode* root) {
    int index = 0;

    while (root != nullptr) {
        if (root->data == element) {
            index = root->index;
            if (root->left != nullptr) root = root->left;
            else root = root->right;
        }
        else if (element < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return index + 1;
}

int getFirstOccurrence(dtype element, TreeNode* root) {
    if (root->data == element) {
        return root->index;
    }
    while (root != nullptr) {
        if (root->data == element) {
            return root->index + 1;
        }
        else if (element < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
}

void getAllOccurrences(dtype element, TreeNode* root, int* occurrences, int* numOccurrences) {
    if (root == nullptr) {
        return;
    }

    if (root->data == element) {
        occurrences[*numOccurrences] = root->index;
        ++(*numOccurrences);
        getAllOccurrences(element, root->left, occurrences, numOccurrences);
    }
    else if (element < root->data) {
        getAllOccurrences(element, root->left, occurrences, numOccurrences);
    }
    else {
        getAllOccurrences(element, root->right, occurrences, numOccurrences);
    }
}

bool validateTree(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    Stack* stackTop = createStack();

    TreeNode* prevTreeNode = nullptr;

    while (root != nullptr || !isEmptyStack(stackTop)) {
        while (root != nullptr) {
            push(stackTop, root);
            root = root->left;
        }

        root = pop(stackTop);

        if (prevTreeNode != nullptr && prevTreeNode->data > root->data) {
            return false;
        }

        prevTreeNode = root;

        root = root->right;
    }

    return true;
}


Stack* createStack() {
    Stack* stack = new Stack;
    stack->top = -1;
    stack->head = nullptr;
    return stack;
}


void push(Stack* stack, TreeNode* node) {
    Node* newNode = new Node;
    newNode->nodeData = node;
    newNode->next = stack->head;
    stack->head = newNode;
    stack->top++;
}


TreeNode* pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        return nullptr;
    }

    Node* temp = stack->head;
    TreeNode* poppedNode = new TreeNode;
    poppedNode = temp->nodeData;
    stack->head = temp->next;
    stack->top--;
    delete temp;
    return poppedNode;
}

bool isEmptyStack(Stack* stack) {
    return stack->top == -1;
}