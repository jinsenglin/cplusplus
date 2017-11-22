#include<iostream>
#include<cstring>

using namespace std;


class TreeNode {
friend class Tree;
friend class BST;

public:
    TreeNode(int value) {
        int data = value; // BUG !!!!
        // 1. this->data = value;
        // 2. data = value;
        this->leftChild = NULL;
        this->rightChild = NULL;
        //this->leftSize = 0;
    }

    TreeNode(int value, const TreeNode & left, const TreeNode & right) {
        int data = value;
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
  inst.InorderVisit();

  return 0;
}
