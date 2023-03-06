#include "Tree.hpp"
// Constructor 
Tree::Tree()
{
    root = new Node(0);
}

// Destructor 
Tree::~Tree() {
    Delete(root);
}

void Tree::Delete(Node *Node) {
    for (int i = 0; i < 26; i++) {
        if (Node->children[i] != nullptr) { 
            Delete(Node->children[i]);
        }
        }
    delete Node;
}

bool Tree::Exists(string word) { 
    Node *temp = root; 
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'a';
        // Check if a child for that character already exists
        if (temp->children[idx] == nullptr) {
            // If it does, return false to indicate that the word does not exist
            return false; 
        }
        // Move temp down to the child corresponding to the character word[i]
        temp = temp->children[idx];
        i++;
    }
    return true;
}
void Tree::Insert(string word) { 
    Node *temp = root;
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'A' + 1;
        // Check if a child for that character already exists
        if (temp->children[idx] == nullptr) {
        //     // If it doesn't, create it 
            temp->children[idx] = new Node(word[i], temp); 

        }
        // Move temp down to the child corresponding to the character word[i]
        temp = temp->children[idx];
        i++;
    }
    size++; 
}

void Tree::Print(Node *Node) { 
    for (int i =0; i < 26; i++) { 
        if (Node->children[i] != nullptr) {
            std::cout << Node->character; 
            Print(Node->children[i]);
        }
    }
}

void Tree::Empty() { 
    for (int i =0; i < 26; i++) { 
        if (Node->children[i] != nullptr) {
            std::cout << "empty 0" << std::endl; 
            return;
        }
    }
    std::cout << "empty 1" << std::endl;
}

void Tree::Erase(string word) { 
    if (!Exists(word)) { 
        std::cout << "failure" << std::endl;
    }
    Node *temp = root; 
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'a';
        // Move temp down to the child corresponding to the character word[i]
        temp = temp->children[idx];
        i++;
    }
    Node *Parent; 
    while (true) {
        Parent = temp->parent; 
        delete temp; 
        // Continue deleting nodes until one of temp's ancestors has siblings
        for (int i =0; i < 26; i++) { 
        if (temp[i] != nullptr) {
            std::cout << "success" << std::endl; 
            return;
        }
    }
    temp = Parent; 
    }

}