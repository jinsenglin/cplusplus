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
            this->leftSize = 0;
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

        void SetLeftSize(int s) {
            this->leftSize = s;
        }

    private:
        Pair* data;
        TreeNode* leftChild;
        TreeNode* rightChild;
        int leftSize;
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

        void SetNodeLeftSize(int k, int s) {
             TreeNode* currentNode = root;

            while (currentNode) {
                if (k < currentNode->data->first) currentNode = currentNode->leftChild;
                else if (k > currentNode->data->first) currentNode = currentNode->rightChild;
                else {
                    currentNode->leftSize = s;
                    return;
                }
            }
        }

        // Recursive Search Codes
        Pair* Get(int k) {
            return this->Get(root, k);
        }
        Pair* Get(TreeNode* p, int k) {
            if (!p) return 0;
            if (k < p->data->first) return this->Get(p->leftChild, k);
            if (k > p->data->first) return this->Get(p->rightChild, k);
            return p->data;
        }

        /*
        // Iterative Search Codes
        Pair* Get(int k) {
            TreeNode* currentNode = root;

            while (currentNode) {
                if (k < currentNode->data->first) currentNode = currentNode->leftChild;
                else if (k > currentNode->data->first) currentNode = currentNode->rightChild;
                else return currentNode->data;
            }

            return NULL;
        }
        */

        Pair* RankGet(int r) {
            TreeNode* currentNode = root;

            while (currentNode) {
                if (r < currentNode->leftSize) currentNode = currentNode->leftChild;
                else if (r > currentNode->leftSize) {
                    r -= currentNode->leftSize;
                    currentNode = currentNode->rightChild;
                }
                else return currentNode->data;
            }

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
//  Demo 1

    Pair p (1, 1);
    TreeNode n (p);
    Tree t;
    t.SetRoot(n);
    t.InorderVisit();
    t.PreorderVisit();
    t.PostorderVisit();
*/



/*
//  Demo 2

    TreeNode n15 (*(new Pair(15, 15)));
    TreeNode n25 (*(new Pair(25, 25)));
    TreeNode root (*(new Pair(20, 20)), n15, n25);
    Tree t;
    t.SetRoot(root);
    t.InorderVisit();
    t.PreorderVisit();
    t.PostorderVisit();
*/



//  Demo 3

    BST t;
    Pair p1 (30, 30);
    Pair p2 (5, 5);
    Pair p3 (40, 40);
    Pair p4 (2, 2);
    Pair p5 (35, 35);
    Pair p6 (80, 80);
    Pair p7 (1, 1);
    Pair p8 (3, 3);
    t.Insert(p1);
    t.Insert(p2);
    t.Insert(p3);
    t.Insert(p4);
    t.Insert(p5);
    t.Insert(p6);
    t.Insert(p7);
    t.Insert(p8);
    t.InorderVisit();

    t.SetNodeLeftSize(30, 5);
    t.SetNodeLeftSize(5, 4);
    t.SetNodeLeftSize(40, 2);
    t.SetNodeLeftSize(2, 2);
    t.SetNodeLeftSize(35, 1);
    t.SetNodeLeftSize(80, 1);
    t.SetNodeLeftSize(1, 1);
    t.SetNodeLeftSize(3, 1);
    Pair* r3 = t.RankGet(3);
    if (r3) cout << "DEBUG: " << r3->ToString() << endl;
    Pair* r7 = t.RankGet(7);
    if (r7) cout << "DEBUG: " << r7->ToString() << endl;
    Pair* r6 = t.RankGet(6);
    if (r6) cout << "DEBUG: " << r6->ToString() << endl;

    Pair* p40 = t.Get(40);
    if (p40) cout << "DEBUG: " << p40->ToString() << endl;



    return 0;
}
