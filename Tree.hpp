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
    void Insert(string word);
    void Erase(string word); 
    void Print(Node *Node, string s); 
    void spellCheck(string word);
    void empty(); 
    void clear();
    void Empty();
    unsigned int count(Node *Node, string word);

    // Helper functions
    void Delete(Node *Node);
    bool Exists(string word);


    
};