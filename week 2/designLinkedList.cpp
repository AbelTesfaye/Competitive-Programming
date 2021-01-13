#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

class MyLinkedList {
public:
    struct Node{
        int val;
        Node *next = NULL;
    };
    
    Node *head = NULL, *tail = NULL;
    int size = 0;
    
    Node * getNodeAtIndex(int i){
        
        Node *node = head;
        while(i){
            node = node->next;
            i--;
        }
        
        return node;
    }
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        
        return getNodeAtIndex(index)->val; 
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        
        Node *newNode = new Node{val};
        if(index == 0){
            if(head == NULL){
                tail = newNode;
            } else {
                newNode->next = head;
            }

            head = newNode;
        } else if(index == size){
            tail->next = newNode;
            tail = newNode;
        } else {
            Node *prev = getNodeAtIndex(index - 1);

            newNode->next = prev->next;
            prev->next = newNode;
        }
        
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        
        if(index == 0){
            if(head == tail){
                head = tail = NULL;
            } else {
                head = head->next;    
            }   
            size--;
            return;
        }
        
        Node *prev = getNodeAtIndex(index - 1);
        prev->next = prev->next->next;
        
        if(index == size - 1){
            tail = prev;
        }
        
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {


    return 0;
}