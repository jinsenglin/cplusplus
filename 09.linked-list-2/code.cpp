
#include <iostream>
#include "function.h"
#include <cstring>
using namespace std;


void Implement::InsertBack(int data)
{
    // if duplicate, do nothing
    Node *n = head;
    while (n !=0) {
        if (n->data == data) return;
        n = n->next;
    }

    // 配置新的記憶體
    Node *newNode = new Node(data);
    // 若list沒有node, 令newNode為head
    if (head == 0) {
        head = newNode;
        return;
    }

    Node *current = head;
    // Traversal
    while (current->next != 0) {
        current = current->next;
    }
    // 將newNode接在list的尾巴
    current->next = newNode;
    newNode->next = NULL;
}

void Implement::InsertFront(int data)
{
    // if duplicate, do nothing
    Node *n = head;
    while (n !=0) {
        if (n->data == data) return;
        n = n->next;
    }

    // 配置新的記憶體
    Node *newNode = new Node(data);
    // 先把head 的node接在newNode後面
    newNode->next = head;
    // 再把head指向newNode所指向的記憶體位置
    head = newNode;
}

void Implement::InsertAfter(int data1, int data2)
{
    // Approach 1
    // delete duplicated item
    //Delete(data2);

    // Approach 2
    // if duplicate, do nothing
    Node *n = head;
    while (n !=0) {
        if (n->data == data2) return;
        n = n->next;
    }

    Node *current = head;
    Node *newNode = new Node(data2);
    // Traversal
    while ((current != NULL) && (data1 != current->data))
    {
        current = current->next;
    }
    //find data1
    if(current != NULL) {
        //insert data2
        newNode->next = current->next;
        current->next = newNode;
    }
    //if not found, do nothing
}

void Implement::Delete(int data)
{
    Node *current = head;
    Node *prev = head;
    Node *newNode = new Node(data);
    // Traversal
    while ((current != NULL) && (data != current->data))
    {
        prev = current;
        current = current->next;
    }
    //find data
    if(current != NULL) {
        prev->next = current->next;
        delete current;
        current = NULL;
    }
}

void Implement::DeleteFront()
{
    Node *current = head;
    //new head
    if(current != NULL)
    {
        head = head->next;
        delete current;
        current = NULL;
    }
}

void Implement::DeleteBack()
{
    Node *current = head;
    Node *prev = head;
    if(current != NULL)
    {
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        //current->next == NULL
        prev->next = NULL;
        delete current;
        current = NULL;
    }
}

void Implement::Reverse()
{
    Node *prev = 0;
    Node *current = head; //prev trails current
    
    while (current) {
        Node *r = prev;
        //把三個指標「按照順序」往前移動，然後進行下一個node之pointer調整
        prev = current;       // r trails prev
        current = current->next;  // current往後挪
        prev->next = r; // link prev to preceding node
    }

    head = prev;
}
