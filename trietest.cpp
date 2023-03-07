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

bool illegalArgument(string word) { 
    unsigned int i = 0;
        bool flag = false;
        while (word[i] != '\0') { 
            if ((word[i] - 'A' + 1) < 1 || (word[i] - 'A' + 1) > 27) {
                try {
                    throw illegal_exception("illegal argument");
                } catch (illegal_exception mce) {
                    std::cout << mce.what() << std::endl;
                    return true;
                    break;
                }

            }
            i++;
    }
    return false;
}

int main() {
    string cmd; 
    Tree *tree;
    string word; 
    string prefix;
    ifstream fin("corpus.txt"); 
    tree = new Tree();
    while (cin >> cmd) {
        if (cmd == "load") {
            while (fin>>word) { 
                if (!tree->exists(word)) { 
                    tree->insert(word);
                }
            }
        std::cout << "success" << std::endl;
        } else if (cmd == "i") { 
            cin >> word; 
            if (illegalArgument(word)) { 
                continue;
            }
            if (tree->exists(word)) { 
                std::cout << "failure" << std::endl;
            } else {
                tree->insert(word);
                std::cout << "success" << std::endl;
            }
        } else if (cmd == "c") {
            cin >> prefix; 
            if (illegalArgument(prefix)) { 
                continue;
            }
            Node *temp = tree->getNode(prefix);
            if (!temp) { 
                std::cout << "not found" << std::endl;
                continue;
            }
            std::cout << "count is " << tree->count(temp) << std::endl;
        } else if (cmd == "e") {
            cin >> word; 
            if (illegalArgument(word)) { 
                continue;
            }   
            tree->erase(word);
        } else if (cmd == "p") { 
            tree->print(tree->root, "");
            if (!tree->empty()) {
                std::cout << std::endl;
            }
        } else if (cmd == "spellcheck") {
            cin >> word;
            tree->spellCheck(word);
        } 
        else if (cmd == "empty") { 
            if (tree->empty()) { 
                std::cout << "empty 1" << std::endl;
            } else { 
                std::cout << "empty 0" << std::endl;
            }
        } else if (cmd == "clear") { 
            tree->clear(tree->root); 
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