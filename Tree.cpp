#include "Tree.hpp"
// Constructor 
Tree::Tree()
{
    root = new Node('r');
    size = 0;
}

// Destructor 
Tree::~Tree() {
    Delete(root);
}

void Tree::Delete(Node* root) {
    // Base case: if root is null, return
    if (!root) {
        return;
    }
    if (root->character == 27) { 
        size--;
    }
    // Delete all child nodes using recursion
    for (int i = 0; i < 27; i++) {
        if (root->children[i]) {
            Delete(root->children[i]);
        }
    }
    // Delete the root node
    delete root;
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

    return temp->children[0] != nullptr && temp->children[0]->character == 27; 
}
void Tree::Insert(string word) { 
    Node *temp = root;
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'A' + 1;
        // Check if a child for that character already exists
        if (temp->children[idx] == nullptr) {
        // If it doesn't, create it 
        // std::cout << "creating" << word[i] << std::endl;
            temp->children[idx] = new Node(word[i], temp); 
        }
        // Move temp down to the child corresponding to the character word[i]
        temp = temp->children[idx];
        i++;
    }
    // terminating node
    temp->children[0] = new Node(27, temp);
    size++;
}

void Tree::Print(Node *Node, string s) {
    // if (Node->character - 'r' != 0) { 
    // std::cout << Node->character;  
    // }
    // std::cout << Node->character;  
    // if (Node->character - 'r' != 0 && Node->character != 27) { 
    //     std::cout << Node->character;  
    // }
    if (Node ->character == 27) {
        std::cout << s; 
        std::cout << " "; 
        return;
    }
    if (Node->character - 'r' != 0) { 
        s += Node->character;
    }
    for (int i =0; i < 27; i++) {
        if (Node->children[i] != nullptr) {
            Print(Node->children[i], s);
        }
    }
}

bool Tree::Empty() { 
    for (int i =0; i < 27; i++) { 
        if (root->children[i] != nullptr) {
            return false;
        }
    }
    return true;
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
    delete temp->children[0]; 
    temp->children[0] = nullptr;
    Node *parent = temp->parent; 
    for (int j =0; j < 27; j++) { 
        if (temp->children[j] != nullptr) {
            std::cout << "success" << std::endl; 
            size--;
            return;
        }
    }
    while (i > 0) {
        delete temp; 
        // Update parent's children array to remove the deleted node
        int idx = word[i-1] - 'A' + 1;
        parent->children[idx] = nullptr;
        // Continue deleting nodes until one of temp's ancestors has siblings
        for (int j =0; j < 27; j++) { 
            if (parent->children[j] != nullptr) {
                std::cout << "success" << std::endl; 
                size--;
                return;
            }
        }
        temp = parent; 
        parent = parent->parent;
        i--;
    }
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
    if (i > 0) { 
        Print(temp, word.substr(0,i-1));
    }
    std::cout << std::endl;
}

unsigned int Tree::count(Node *Node) {
    unsigned int count = 0;
    if (Node ->character == 27) {
        return 1;
    }
    for (int i =0; i < 27; i++) {
        if (Node->children[i] != nullptr) {
            count += this->count(Node->children[i]);
        }
    }
    return count;

}