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
    Node *children[26];

    // Constructor 
    Node(char character = 0); 

};
#endif