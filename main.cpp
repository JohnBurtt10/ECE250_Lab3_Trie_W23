#include "Node.hpp"
#include "Tree.hpp"
#include <iostream> 
#include <fstream> 
using namespace std; 

class illegal_exception : public std::exception {
public:
    illegal_exception(const std::string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

int main() {
    string cmd; 
    Tree *tree;
    string word; 
    string prefix;
    ifstream fin("corpus.txt"); 
    tree = new Tree();
    while (cin >> cmd) {
        // std::cout << cmd << std::endl;
        if (cmd == "load") {
            while (fin>>word) { 
                if (!tree->Exists(word)) { 
                    tree->Insert(word);
                }
            }
        std::cout << "success" << std::endl;
        } else if (cmd == "i") { 
            cin >> word; 
            unsigned int i = 0;
            bool flag = false;
            while (word[i] != '\0') { 
                if ((word[i] - 'A' + 1) < 1 || (word[i] - 'A' + 1) > 27) {
                    try {
                        throw illegal_exception("illegal argument");
                    } catch (illegal_exception mce) {
                        std::cout << mce.what() << std::endl;
                        flag = true;
                        break;
                    }

                }
                i++;
            }
            if (flag) { 
                continue;
            }
            if (tree->Exists(word)) { 
                std::cout << "failure" << std::endl;
            } else {
                tree->Insert(word);
                std::cout << "success" << std::endl;
            }
        } else if (cmd == "c") {
            cin >> prefix; 
            unsigned int i = 0; 
            unsigned int count = 0;
            bool flag = false; 
            while (prefix[i] != '\0') { 
                if ((prefix[i] - 'A' + 1) < 1 || (prefix[i] - 'A' + 1) > 27) {
                    try {
                        throw illegal_exception("illegal argument");
                    } catch (illegal_exception mce) {
                        std::cout << mce.what() << std::endl;
                        flag = true;
                        break;
                    }

                }
                i++;
            }
            if (flag) { 
                continue;
            }
            Node *temp = tree->root; 
            unsigned int j = 0;
            bool notFound = false;
            while (prefix[j] != '\0') {
                // Get the position of in the alphabet of the character 
                int idx = prefix[j] - 'A' + 1;
                // Check if a child for that character already exists
                if (temp->children[idx] == nullptr) {
                    notFound = true;
                    break;
                }
                temp = temp->children[idx];
                // Move temp down to the child corresponding to the character word[i]
                j++;
            }
            if (notFound) { 
                std::cout << "not found" << std::endl;
                continue;
            }
            // std::cout << "temp->character - 'A' + 1: " << temp->character - 'A' + 1 << std::endl;
            std::cout << "count is " << tree->count(temp) << std::endl;
        } else if (cmd == "e") {
            cin >> word; 
            unsigned int i = 0;
            bool flag = false;
            while (word[i] != '\0') { 
            if ((word[i] - 'A' + 1) < 1 || (word[i] - 'A' + 1) > 27) {
                    try {
                        throw illegal_exception("illegal argument");
                    } catch (illegal_exception mce) {
                        std::cout << mce.what() << std::endl;
                        flag = true;
                        break;
                    }

                }
                i++;
            }
            if (flag) { 
                continue;
            }   
            tree->Erase(word);
        } else if (cmd == "p") { 
            tree->Print(tree->root, "");
            if (!tree->Empty()) {
                std::cout << std::endl;
            }
        } else if (cmd == "spellcheck") {
            cin >> word;
            tree->spellCheck(word);
        } 
        else if (cmd == "empty") { 
            if (tree->Empty()) { 
                std::cout << "empty 1" << std::endl;
            } else { 
                std::cout << "empty 0" << std::endl;
            }
        } else if (cmd == "clear") { 
            tree->Delete(tree->root); 
            tree->root = new Node(0);
            std::cout << "success" << std::endl;
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