#include<iostream>
#include<array>

using namespace std;

class MyCircularQueue {
private:
    int* q;
    int front;
    int rear;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(isEmpty()){
            front = ++front % size;
        }
        rear = ++rear % size;
        q[rear] = value;
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = ++front % size;
        }
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(!isEmpty())
            return q[front];
        else
            return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(!isEmpty())
            return q[rear];
        else
            return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear + 1) % size == front;    
    }
};

int main()
{
  MyCircularQueue q(3);
  q.enQueue(1);
  //q.enQueue(2);
  //q.enQueue(3);
  cout << q.Rear() << endl;

}