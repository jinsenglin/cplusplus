#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <string>

using namespace std;

//It contains the functions that you have to override.
class Heap
{
public:
	int size=0;
	int *heap=new int[100000];
	
	//----------------------------------------------------------------------
    // Insert a data into the heap.
    //----------------------------------------------------------------------
    virtual void Insert(int value)=0;

    //----------------------------------------------------------------------
    // Remove the max value from the heap.
    //----------------------------------------------------------------------
    virtual void DeleteMax()=0;

    //----------------------------------------------------------------------
    // Return the max path weight from root to leaf.
    //----------------------------------------------------------------------
    virtual int MaxPathWeight(int index)=0;
	
	//----------------------------------------------------------------------
    // Return the inorder traversal path of the heap tree.
    //----------------------------------------------------------------------
    virtual string InorderTraversal(int index)=0;
	
	//----------------------------------------------------------------------
    // Return the preorder traversal path of the heap tree.
    //----------------------------------------------------------------------
    virtual string PreorderTraversal(int index)=0;
	
	//----------------------------------------------------------------------
    // Return the postorder traversal path of the heap tree.
    //----------------------------------------------------------------------
    virtual string PostorderTraversal(int index)=0;
	
	string toString(){
		//levelorder traversal
		string result = "";
		for(int i=1;i<=size;i++){
			if(i==1)
				result.append(to_string(heap[i]));
			else
				result.append(" "+to_string(heap[i]));
		}
		return result;
	}
};


class Implement : public Heap
{
public:
    void Insert(int value);
    void DeleteMax();
    int MaxPathWeight(int index);
	string InorderTraversal(int index);
	string PreorderTraversal(int index);
	string PostorderTraversal(int index);
};

#endif
