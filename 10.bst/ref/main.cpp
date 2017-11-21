//a binary tree for breadth-first traversal
#include <iostream>
#include <queue>
using namespace std;

class Node
{
friend class Tree;
private:
  int data;
  Node* leftChild;
  Node* rightChild;


public:
  void setKey(int aData) { data = aData; }
  void setLeft(Node* aLeft) { leftChild = aLeft; }
  void setRight(Node* aRight) { rightChild = aRight; }
  int Data() { return data; }
  Node* Left() { return leftChild; }
  Node* Right() { return rightChild; }
};

class Tree
{
private:
  Node* root;  
  void addNode(int data, Node* leaf);
public:
  Tree(){root = NULL;}
  Node* Root() { return root; }
  void addNode(int data);
  void Inorder(Node* currentNode);
  void Postorder(Node* currentNode);
  void Preorder(Node* currentNode);
  void levelOrder(Node* currentNode);
};

// Add a node
void Tree::addNode(int data) {
     // No elements. Add the root
     if ( root == NULL ) {
        cout << "add root node ... " << data << endl;
        Node* n = new Node();
        n->setKey(data);
        root = n;
     }
     else {
      cout << "add other node ... " << data << endl;
      addNode(data, root);
     }
}

// Add a node (private)
void Tree::addNode(int data, Node* leaf) {
  if(leaf->Left() == NULL)
  {
    Node* n = new Node();
    n->setKey(data);
    leaf->setLeft(n);
  }
  else if(leaf->Right() == NULL)
    //if ( data <= leaf->Data() ) {
       // if ( leaf->Left() != NULL )
       //    addNode(data, leaf->Left());
       // else {
       //    Node* n = new Node();
       //    n->setKey(data);
       //    leaf->setLeft(n);
       // }
    //}
    //else {
       // if ( leaf->Right() != NULL )
       //    addNode(data, leaf->Right());
       // else {
       //    Node* n = new Node();
       //    n->setKey(data);
       //    leaf->setRight(n);
       // }
    //}
}


void Tree::Inorder(Node* currentNode)
{
  //Recursive inorder traversal function
  if(currentNode)
    {
        cout << "DEBUG: c.d = " << currentNode->Data() << endl;
        if (currentNode->Left()) {
            cout << "DEBUG: c.l.d = " << currentNode->Left()->Data() << endl;
        }
        if (currentNode->Right()) {
            cout << "DEBUG: c.r.d = " << currentNode->Right()->Data() << endl;
        }

        Inorder(currentNode->Left());
        cout << currentNode->Data() << endl;
        Inorder(currentNode->Right());
    }
}

void Tree::Preorder(Node* currentNode)
{
    if (currentNode != NULL)
    {
        cout << currentNode->Data() << endl;
        Preorder(currentNode->Left());
        Preorder(currentNode->Right());
    }
}

void Tree::Postorder(Node* currentNode)
{
    if(currentNode != NULL)
    {

        Postorder(currentNode->Left());
        Postorder(currentNode->Right());
        cout << currentNode->Data() << endl;

    }
}

// Print the tree level-order assisted by queue
void Tree::levelOrder(Node* currentNode) {
   // Create a queue
   queue<Node*> q;

   while ( currentNode )
   {
       cout << currentNode->Data() << " ";
       // Enqueue the left children
       if ( currentNode->Left() != NULL )
            q.push(currentNode->Left());

       // Enqueue the right children
       if ( currentNode->Right() != NULL )
            q.push(currentNode->Right());
       if(q.empty()) return;
       currentNode = q.front();
       // Pop the visited node
       q.pop();
   }
}



int main()
{
  Tree* tree = new Tree();
  tree->addNode(1);
  tree->addNode(2);
  tree->addNode(3);

  cout << "In order traversal" << endl;
    tree->Inorder(tree->Root());
    cout << endl;

  cout << "Pre order traversal" << endl;
   tree->Preorder(tree->Root());
    cout << endl;

  cout << "Post order traversal" << endl;
    tree->Postorder(tree->Root());
    cout << endl;

  cout << "Level order traversal" << endl;
  tree->levelOrder(tree->Root());
  cout << endl;
}
