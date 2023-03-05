#include "Tree.hpp"
// Constructor 
Tree::Tree()
{
    root = Node();

}

// Destructor 
Tree::~Tree() {
}
void Tree::Insert(string word) { 
    Node temp = root; 
    unsigned int i = 0;
    unsigned int k = 0;
    unsigned int j = 0;
    bool childExists = false; 
    bool unique = false;
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
            unique = true; 
            j = 0;
            while (temp.children[j].character != 0 && word[i] > temp.children[j].character) {
                j++;
            }
            temp.children[j] = Node(word[i]); 
            temp = temp.children[j];

        }
    i++;
    }
    if (!unique) {
        std::cout << "failure" << std::endl;
        return;
    }
    std::cout << "success" << std::endl; 
}

void Tree::Print(Node Node) { 
    for (auto it = Node.children.begin();
        it != Node.children.end(); it++) {
            Print(*it); 
        }
}
