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
    // Node *parent;
    vector<Node> children;

    // Constructor 
    Node(char character = 0); 

};
#endif