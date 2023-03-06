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
                if (!tree->Exists(word)) { 
                    tree->Insert(word);
                }
            }
        std::cout << "success" << std::endl;
        } else if (cmd == "i") { 
            cin >> word; 
            if (tree->Exists(word)) { 
                std::cout << "failure" << std::endl;
            } else {
                tree->Insert(word);
                std::cout << "success" << std::endl;
            }
        } else if (cmd == "c") {
            cin >> prefix; 
            tree->count(tree->root, "");
        } else if (cmd == "e") {
            cin >> word; 
            tree->Erase(word);
        } else if (cmd == "p") { 
            tree->Print(tree->root, "");
            std::cout << std::endl;
        } else if (cmd == "spellcheck") {
            cin >> word;
            tree->spellCheck(word);
        } 
        else if (cmd == "empty") { 
            tree->Empty();
        } else if (cmd == "clear") { 
            tree->Delete(tree->root); 
            tree->root = new Node(0);
        } else if (cmd == "size") { 
            std::cout << "number of words is " << tree->size << std::endl;;
        }
        else if (cmd == "exit") { 
            break;
        }
    }
    delete tree;
    return 0;

}