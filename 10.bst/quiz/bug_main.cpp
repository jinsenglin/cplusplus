//https://acm.cs.nthu.edu.tw/problem/11684/
#include<iostream>
#include<cstring>

using namespace std;


class TreeNode {
friend class Tree;
friend class BST;

public:
    TreeNode(int value) {
        data = value;
        this->leftChild = NULL;
        this->rightChild = NULL;
        //this->leftSize = 0;
    }

    TreeNode(int value, const TreeNode & left, const TreeNode & right) {
        data = value;
        this->leftChild = new TreeNode(left);
        this->rightChild = new TreeNode(right);
    }

    ~TreeNode() {}


private:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode* parent;
    //string element;
    
};

class BST {
public:
    BST() {
        root = NULL;
    }

    ~BST() {}


    // Recursive Search Codes
    int Get(int k) {
        // Search the BST for a pair with key k
        // If the this pair is found, return a pointer to this pair, otherwise return 0
        return Get(root, k);
    }
    int Get(TreeNode* p, int k) {
        if (!p) return 0;
        if (k < p->data) return Get(p->leftChild, k);
        if (k > p->data) return Get(p->rightChild, k);
        return p->data;
    }


    void Insert(int value) {
            // Search for key “thePair.first”, pp is the parent of p
            //If the search is unsuccessful, then the element is inserted at the point the search terminates
            TreeNode* p = root, *pp = 0;
            while (p) {
                pp = p;
                if (value < p->data) p = p->leftChild;
                else if (value > p->data) p = p->rightChild;
                else {
                    // Duplicate, update the value of element
                    p->data = value;
                return;
                }
            }

            // Perform the insertion
            p = new TreeNode(value);
            if (root) {
                // tree is not empty
                if (value < pp->data) pp->leftChild = p;
                else pp->rightChild = p;
            }
            else root = p;
        }

    void Delete(int k) {
        // TODO
        // Delete x if x is in the binary search tree.
        // Please use the smallest element in right subtree to replace x.
        // If x is not in the binary search tree, you don’t need to do anything.
    }

    void Clear(){
      root = NULL;
    }

    int GetHight() {
      return Height(root);
    }
    /*
        15
    10     20
         16

    n = 15


    */
    int Height(TreeNode* n){
      if (n) {
        int heightLeft = Height(n->leftChild);
        int heightRight = Height(n->rightChild);

        if (heightLeft > heightRight) return heightLeft+1;
        else return heightRight+1;
      }
      else {
        return 0;
      }
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
        cout << to_string(currentNode->data) << " ";
        Inorder(currentNode->rightChild);
    }
}
};

class Implement : public BST {};

void tryTestCase(Implement &inst)
{
    // parse each case
    std::string input;
    char op[20];
    int value;
  while(std::cin >> op)
  {
    if(strcmp("Insert", op) == 0){
        std::cin >> value;
        inst.Insert(value);
    }
    else if(strcmp("Find", op) == 0){
        std::cin >> value;
        int result = inst.Get(value);
        if(result == 0){
          cout<<op<<" "<<value<<": No"<<endl;
        }
        else{
          cout<<op<<" "<<value<<": Yes"<<endl;
        }
    }
    else if(strcmp("Clear", op) == 0) {
        inst.Clear();
    }

    else if(strcmp("Height", op) == 0) {
        int h = inst.GetHight();
        cout<<h<<endl;
        }

    else if(strcmp("End", op) == 0) {
      // string urResultStr = inst.toString();
      //       std::cout << urResultStr << endl;
            break;
        }

  }
  //break;
}

int main() 
{
  Implement inst = *(new Implement());
  tryTestCase(inst);
  //inst.InorderVisit();

  return 0;
}