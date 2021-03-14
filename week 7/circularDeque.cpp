class MyCircularDeque {
public:
    
    int size = 0;
    int limit = 0;
    
    struct DequeNode {
        int val;
        DequeNode *prev, *next;
    };
    
    DequeNode *front, *last;
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        limit = k;
    }
    
    DequeNode* insertNode(int val){
        DequeNode *newNode = new DequeNode{val};
                
        if(size == 0){
            front = last = newNode;
        }
        
        newNode->prev = last;
        last->next = newNode;
        
        front->prev = newNode;
        newNode->next = front;
        
        size++;
        
        return newNode;
    }    
    
    void deleteNode(DequeNode *nodeToDelete){
        if(size == 1){
            front = last = NULL;
            delete nodeToDelete;
            return;
        }
        
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
        
        delete nodeToDelete;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size == limit) return false;
        
        DequeNode *newNode = insertNode(value);

        front = newNode;
                
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size == limit) return false;
        
        DequeNode *newNode = insertNode(value);
        
        last = newNode;
                
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size == 0) return false;
        
        DequeNode *prevFront = front;
        front = front->next;
        
        deleteNode(prevFront);
        
        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size == 0) return false;
        
        DequeNode *prevLast = last;
        last = last->prev;
        
        deleteNode(prevLast);
        
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(size == 0) return -1;
        
        return front->val;
     }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(size == 0) return -1;
        
        return last->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == limit;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */