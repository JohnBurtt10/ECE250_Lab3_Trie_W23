#include "Node.hpp"
#include "Tree.hpp"
#include <iostream> 
#include <fstream> 
using namespace std; 

int main() {
    string cmd; 
    Tree *tree;
    string word; 
    string prefix;
    ifstream fin("corpus.txt"); 
    tree = new Tree();
    while (cin >> cmd) {
        if (cmd == "load") {
            // 
            while (fin>>word) { 
                tree->Insert(word);
            }
        std::cout << "success" << std::endl;
        } else if (cmd == "i") { 
            cin >> word; 
            if (tree->Exists(word)) {
                std::cout << "failure" << std::endl;
                break;
            }
            tree->Insert(word);
            std::cout << "success" << std::endl;
        } else if (cmd == "c") {
            cin >> prefix; 
        } else if (cmd == "e") {
            cin >> word; 
        } else if (cmd == "p") { 
            tree->Print(tree->root);
        } else if (cmd == "spellcheck") {
            cin >> word;
        } 
        else if (cmd == "empty") { 
        } else if (cmd == "clear") { 
        } else if (cmd == "size") { 
        }
        else if (cmd == "exit") { 
            break;
        }
    }
    delete tree;
    return 0;

}