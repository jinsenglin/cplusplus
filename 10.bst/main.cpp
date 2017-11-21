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
            data = &pair;
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
    cout << "DEBUG: " << p.ToString() << endl;
    TreeNode n (p);
    cout << "DEBUG: " << p.ToString() << endl;
    Tree t;
    
    return 0;
}
