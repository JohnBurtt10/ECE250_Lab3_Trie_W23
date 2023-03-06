#include "Tree.hpp"
// Constructor 
Tree::Tree()
{
    root = new Node(0);
    size = 0;
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
        int idx = word[i] - 'A' + 1;
        // Check if a child for that character already exists
        if (temp->children[idx] == nullptr) {
            // If it does, return false to indicate that the word does not exist
            return false; 
        }
        // Move temp down to the child corresponding to the character word[i]
        temp = temp->children[idx];
        i++;
    }
    // if (temp->children[0] != nullptr) { 
    //     std::cout << temp->children[0]->character << std::endl;
    // }

    return temp->children[0] != nullptr && temp->children[0]->character == 26; 
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
    // terminating node
    temp->children[0] = new Node(26, temp);
    size++;
}

void Tree::Print(Node *Node, string s, bool firstWord) {
    if (Node ->character == 26) {
        if (!firstWord) { 
            std::cout << " "; 
        }
         std::cout << s;  
        // Prints a space after the last letter in the word
        return;
    }
    s += Node->character;
    for (int i =0; i < 26; i++) {
        if (Node->children[i] != nullptr) {
            Print(Node->children[i], s, firstWord);
        }
    }
}

void Tree::Empty() { 
    for (int i =0; i < 26; i++) { 
        if (root->children[i] != nullptr) {
            std::cout << "empty 0" << std::endl; 
            return;
        }
    }
    std::cout << "empty 1" << std::endl;
}

void Tree::Erase(string word) { 
    if (!Exists(word)) { 
        std::cout << "failure" << std::endl;
        return;
    }
    Node *temp = root; 
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'A' + 1;
        if (temp->children[idx] == nullptr) {
            break;
        }
        // Move temp down to the child corresponding to the character word[i]
        temp = temp->children[idx];
        i++;
    }
    Node *parent = temp->parent; 
    while (true) {
        delete temp; 
        // Update parent's children array to remove the deleted node
        int idx = word[i-1] - 'A' + 1;
        parent->children[idx] = nullptr;
        // Continue deleting nodes until one of temp's ancestors has siblings
        for (int i =0; i < 26; i++) { 
            if (parent->children[i] != nullptr) {
                std::cout << "success" << std::endl; 
                return;
            }
        }
        temp = parent; 
        parent = parent->parent;
        i--;
    }
    size--;
}


void Tree::spellCheck(string word) { 
    if (Exists(word)) { 
        std::cout << "correct" << std::endl;
        return;
    }
    Node *temp = root; 
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'A' + 1;
        // Check if a child for that character already exists
        if (temp->children[idx] == nullptr) {
            break;
        }
        temp = temp->children[idx];
        // Move temp down to the child corresponding to the character word[i]
        i++;
    }
    Print(temp, word.substr(0,i-1), true);
    std::cout << std::endl;
}

unsigned int Tree::count(Node *Node, string s) {
    unsigned int count = 0;
    if (Node ->character == 26) {
        return 1;
    }
    s += Node->character;
    for (int i =0; i < 26; i++) {
        if (Node->children[i] != nullptr) {
            count += this->count(Node->children[i], s);
        }
    }
    return count;

}