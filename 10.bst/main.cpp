#include<iostream>
#include<cstring>

using namespace std;

class Pair {
    friend class Tree;
    friend class BST;
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
        TreeNode(const Pair & pair) {
            this->data = new Pair(pair);
            this->leftChild = NULL;
            this->rightChild = NULL;
        }

        TreeNode(const Pair & pair, const TreeNode & left, const TreeNode & right) {
            this->data = new Pair(pair);
            this->leftChild = new TreeNode(left);
            this->rightChild = new TreeNode(right);
        }

        ~TreeNode() {}

        void SetLeft(const TreeNode & n) {
            this->leftChild = new TreeNode(n);
        }

        void SetRight(const TreeNode & n) {
            this->rightChild = new TreeNode(n);
        }

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

        void InorderVisit() {
            this->Inorder(root);
        }

        void PreorderVisit() {
            this->Preorder(root);
        }

        void PostorderVisit() {
            this->Postorder(root);
        }

        void LevelorderVisit() {
            // TODO
        }

        void SetRoot(const TreeNode & n) {
            this->root = new TreeNode(n);
        }

    private:
        TreeNode* root;

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
};

class BST {
    public:
        BST() {
            root = NULL;
        }
        ~BST() {}

        // Recursive Search Codes
        Pair* Get(int k) {
            if (root) {
                // TODO
                return root->data;
            }
            else {
                return 0;
            }
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

        void Insert(const Pair & thePair) {
            // Search for key “thePair.first”, pp is the parent of p

            TreeNode* p = root, *pp = 0;
            while (p) {
                pp = p;
                if (thePair.first < p->data->first) p = p->leftChild;
                else if (thePair.first > p->data->first) p = p->rightChild;
                else {
                    // Duplicate, update the value of element
                    p->data->second = thePair.second;
                    return;
                }
            }

            // Perform the insertion
            p = new TreeNode(thePair);
            if (root) {
                // tree is not empty
                if (thePair.first < pp->data->first) pp->leftChild = p;
                else pp->rightChild = p;
            }
            else root = p;
        }

        void Delete(int k) {
            // TODO
        }

        void InorderVisit() {
            this->Inorder(this->root);
            cout << endl;
        }

    private:
        TreeNode* root;

        void Inorder(TreeNode* currentNode) {
            if (currentNode) {
                Inorder(currentNode->leftChild);
                cout << to_string(currentNode->data->first) << " ";
                Inorder(currentNode->rightChild);
            }
        }
};

int main() {
/*
    Pair p (1, 1);
    TreeNode n (p);
    Tree t;
    // t.Insert(p);
    t.SetRoot(n);
    t.InorderVisit();
    t.PreorderVisit();
    t.PostorderVisit();
*/

/*
    TreeNode n15 (*(new Pair(15, 15)));
    TreeNode n25 (*(new Pair(25, 25)));
    TreeNode root (*(new Pair(20, 20)), n15, n25);
    Tree t;
    t.SetRoot(root);
    t.InorderVisit();
    t.PreorderVisit();
    t.PostorderVisit();
*/

    BST t;
    Pair p (30, 30);
    Pair p2 (20, 20);
    t.Insert(p);
    t.Insert(p2);
    t.InorderVisit();

    return 0;
}
