#include "Tree.hpp"
// Constructor 
Tree::Tree()
{
    root = new Node();
}

// Destructor 
Tree::~Tree() {
    Delete(root);
}

void Tree::Delete(Node *Node) {
    unsigned int i = 0;
    while (i < 24) { 
        if (Node->children[i] != nullptr) {
            Delete(Node->children[i]);
            delete(Node);
        }
    i++;
    }

}

bool Tree::Exists(string word) { 
    Node *temp = root; 
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'a';
        // Check if a child for that character already exists
        if (temp->children[idx]->character == '\0') {
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
        int idx = word[i] - 'a';
        // Check if a child for that character already exists
        if (temp->children[idx]->character != '\0') {
            // If it doesn't, create it 
            temp->children[idx] = new Node(word[i]); 
        }
        // Move temp down to the child corresponding to the character word[i]
        temp = temp->children[idx];
        i++;
    }
}

void Tree::Print(Node *Node) { 
    unsigned int i = 0;
    while (i < 24) { 
        if (Node->children[i] != nullptr) {
            std::cout << Node->character; 
            Print(Node->children[i]);
        }
    i++;
    }
}

