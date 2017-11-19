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
        TreeNode() {}
        ~TreeNode() {}
    private:
        Pair* data;
};

class BST {
    public:
        BST() {}
        ~BST() {}

        // Recursive Search Codes
        Pair* Get(int k) {
            return 0;
        }
        Pair* Get(TreeNode* p, int k) {
            return 0;
        }

        /* Iterative Search Codes
        Pair* Get(int k) {
            return 0;
        }*/

        Pair* RankGet(int r) {
            return 0;
        }

        void Insert(const Pair& thePair) {
        }

        void Delete(int k) {
        }
    private:
        TreeNode* root;       
};

int main() {
    return 0;
}
