#include<iostream>
#include<string>

using namespace std;

class Pair {
    public:
        Pair(int key, int element) {
            first = key;
            second = element;            
        }
        ~Pair() {}
    private:
        int first;
        int second;
};

class TreeNode {
    public:
        TreeNode(int key, int element) {
            // TODO
        }
        ~TreeNode() {}
    private:
        Pair* data;
        TreeNode* leftChild;
        TreeNode* rightChild;
};

class BST {
    public:
        BST() {}
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
    return 0;
}
