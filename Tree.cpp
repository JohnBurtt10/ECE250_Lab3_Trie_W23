#include "Tree.hpp"
// Constructor 
Tree::Tree()
{
    root = new Node('r');
    size = 0;
}

// Destructor 
Tree::~Tree() {
    clear(root);
}

void Tree::clear(Node* root) {
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
            clear(root->children[i]);
        }
    }
    // Delete the root node
    delete root;
}

bool Tree::exists(string word) { 
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
void Tree::insert(string word) { 
    Node *temp = root;
    unsigned int i = 0;
    while (word[i] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[i] - 'A' + 1;
        // Check if a child for that character already exists
        if (temp->children[idx] == nullptr) {
        // If it doesn't, create it 
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


// TODO: refactor such that the character does not need to be stored
void Tree::print(Node *Node, string s) {
    if (Node ->character == 27) {
        std::cout << s; 
        std::cout << " "; 
        return;
    }
    if ((Node->character - 'A' +1) > 0 && (Node->character - 'A' +1) < 27) { 
        s += Node->character;
    }
    for (int i =0; i < 27; i++) {
        if (Node->children[i] != nullptr) {
            print(Node->children[i], s);
        }
    }
}

bool Tree::empty() { 
    for (int i =0; i < 27; i++) { 
        if (root->children[i] != nullptr) {
            return false;
        }
    }
    return true;
}

void Tree::erase(string word) { 
    // std::cout << "trying to erase: " << word << std::endl;
    if (!exists(word)) { 
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
     std::cout << "success" << std::endl; 
    size--;
}

void Tree::spellCheck(string word) { 
    if (exists(word)) { 
        std::cout << "correct" << std::endl;
        return;
    }
    Node *temp = root; 
    unsigned int i = 0;
    // TODO: replace this code with getNode() once it no longer requires string
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
        print(temp, word.substr(0,i-1));
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

Node* Tree::getNode(string word) { 
    Node *temp = root; 
    unsigned int j = 0;
    bool notFound = false;
    while (word[j] != '\0') {
        // Get the position of in the alphabet of the character 
        int idx = word[j] - 'A' + 1;
        // Check if a child for that character already exists
        if (temp->children[idx] == nullptr) {
            return nullptr;
            break;
        }
        temp = temp->children[idx];
        // Move temp down to the child corresponding to the character word[i]
        j++;
    }
    return temp;
}