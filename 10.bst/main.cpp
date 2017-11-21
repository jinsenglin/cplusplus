#include<iostream>
#include<cstring>

using namespace std;

class Pair {
    public:
        Pair(int key, int element) {
            first = key;
            second = element;            
        }
        ~Pair() {}

        string ToString() {
            return to_string(this->first) + " : " + to_string(this->second);
        }
    private:
        int first;
        int second;
};

class TreeNode {
    friend class Tree;
    friend class BST;

    public:
        TreeNode(Pair pair) {
            this->data = &pair;
            this->leftChild = NULL;
            this->rightChild = NULL;
        }
        ~TreeNode() {}
    private:
        Pair* data;
        TreeNode* leftChild;
        TreeNode* rightChild;
};

class Tree {
    public:
        Tree() {
            root = NULL;
        }

        ~Tree() {}

        void Visit(TreeNode* currentNode) {
            cout << currentNode->data->ToString() << endl;
        }

        void Inorder(TreeNode* currentNode) {
            if (currentNode) {
                Inorder(currentNode->leftChild);
                Visit(currentNode); // e.g., printout information
                Inorder(currentNode->rightChild);
            }
        }

        void Preorder(TreeNode* currentNode) {
            if (currentNode) {
                Visit(currentNode); // e.g., printout information
                Preorder(currentNode->leftChild);
                Preorder(currentNode->rightChild);
            }
        }

        void Postorder(TreeNode* currentNode) {
            if (currentNode) {
                Postorder(currentNode->leftChild);
                Postorder(currentNode->rightChild);
                Visit(currentNode); // e.g., printout information
            }
        }

        void InorderVisit() {
            this->Inorder(root);
        }

        void PreorderVisit() {
            //this->Preorder(root);
        }

        void PostorderVisit() {
            //this->Postorder(root);
        }

        void Levelorder() {
            // TODO
        }

        void Insert(Pair pair) {
            TreeNode n (pair);

            if (this->root) {
                // TODO
            }
            else {
                this->root = &n;
                this->InorderVisit();   //TODO DEBUG
            }
        }

    private:
        TreeNode* root;
};

class BST {
    public:
        BST() {
            root = NULL;
        }
        ~BST() {}

        // Recursive Search Codes
        Pair* Get(int k) {
            // TODO
            return 0;
        }
        Pair* Get(TreeNode* p, int k) {
            // TODO
            return 0;
        }

        /* Iterative Search Codes
        Pair* Get(int k) {
            // TODO
            return 0;
        }*/

        Pair* RankGet(int r) {
            // TODO
            return 0;
        }

        void Insert(const Pair& thePair) {
            // TODO
        }

        void Delete(int k) {
            // TODO
        }
    private:
        TreeNode* root;       
};

int main() {
    Pair p (1, 1);
    TreeNode n (p);
    Tree t;
    t.Insert(p);
    //t.InorderVisit();     // TODO DEBUG
    //t.PreorderVisit();
    //t.PostorderVisit();
    
    return 0;
}
