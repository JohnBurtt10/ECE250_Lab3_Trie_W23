#include <iostream>
#include <cstdlib>
#include "Node.hpp"
using namespace std;
class Tree {
private:
public:
    // Constructor 
    Node *root; 
    unsigned int size = 0; 
    Tree(); 
    ~Tree();
    // Command handlers 
    void Insert(string word);
    void Erase(string word); 
    void Print(Node *Node); 
    void spellCheck(string word);
    void empty(); 
    void clear();
    void size(); 

    // Helper functions
    void Delete(Node *Node);
    bool Exists(string word);


    
};