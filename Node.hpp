#ifndef Node_h
#define Node_h
#include <vector> 
#include <iostream>
#include <cstdlib>
using namespace std;
class Node {
private:
public:
    char character;
    Node *parent = nullptr;
    Node *children[26] = {nullptr};

    // Constructor 
    Node(char character, Node *parent = nullptr); 

};
#endif