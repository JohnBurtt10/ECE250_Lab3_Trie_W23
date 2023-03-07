#include <iostream>
#include <cstdlib>
#include "Node.hpp"
using namespace std;
class Tree {
private:
public:
    // Constructor 
    Node *root; 
    unsigned int size; 
    Tree(); 
    ~Tree();
    // Command handlers 
    // TODO:: figure out capital letters for functions
    void insert(string word);
    void erase(string word); 
    void print(Node *Node, string s); 
    void spellCheck(string word);
    void clear(Node *Node);
    bool empty();
    unsigned int count(Node *Node);

    // Helper functions
    bool exists(string word);
    Node* getNode(string word);


    
};