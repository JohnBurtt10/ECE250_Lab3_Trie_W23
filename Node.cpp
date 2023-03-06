#include "Node.hpp"
// Constructor 
    Node::Node(char character, Node *parent) {
        this->character = character; 
        this->parent = parent;
    }