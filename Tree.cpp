#include "Tree.hpp"
// Constructor 
Tree::Tree()
{
    root = Node();

}

// Destructor 
Tree::~Tree() {
}

bool Tree::Exists(string word) { 
    Node *temp = root; 
    unsigned int i = 0;
    unsigned int k = 0;
    bool childExists = false; 
    while (word[i] != 0) {
        k = 0;
        childExists = false; 
        // Check if word[i] is already a child of temp, and if it is then traverse to that child
         for (auto it = temp.children.begin();
            it != temp->children.end(); it++) {
                if (it->character == word[i]) { 
                    temp = temp.children[k]; 
                    childExists = true; 
                    break;
                }
                k++; 
            }
        if (!childExists) { 
            return false;
        }
    i++;
    }
    return true;
}
void Tree::Insert(string word) { 
    Node temp = root; 
    unsigned int i = 0;
    unsigned int k = 0;
    unsigned int j = 0;
    bool childExists = false; 
    while (word[i] != 0) {
        k = 0;
        childExists = false; 
        // Check if word[i] is already a child of temp, and if it is then traverse to that child
         for (auto it = temp.children.begin();
            it != temp.children.end(); it++) {
                if (it->character == word[i]) { 
                    temp = temp.children[k]; 
                    childExists = true; 
                    return; 
                }
                k++; 
            }
        // 
        if (childExists == false) {
            j = 0;
             for (auto it = temp.children.begin();
            it != temp.children.end(); it++) {
                if (word[i] < temp.children[j].character) {  
                    temp.children.insert(temp.children.begin()+j, Node(word[i]));
                    temp = temp.children[j]; 
                    break;
                }
                j++; 
            }
        }
    i++;
    }
}

void Tree::Print(Node Node) { 
    for (auto it = Node.children.begin();
        it != Node.children.end(); it++) {
            std::cout << it->character;
            Print(*it); 
            std::cout << it->character;
        }
}
