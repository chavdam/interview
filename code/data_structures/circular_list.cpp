#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

Node* insert(Node* head, int insertVal) {
        if(head == NULL){
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        }
        Node* newNode = new Node(insertVal, NULL);
        if(head == head->next){
            head->next = newNode;
            newNode->next = head;
            return head;
        }
        Node* temp = head;
        
        while(temp->val <= temp->next->val && insertVal <= temp->val){
            temp = temp->next;
        }
        
        Node* tempNext = temp->next;
        temp->next = newNode;
        newNode->next = tempNext;
        return head;
    }

int main()
{
 Node* head = NULL;
 head = insert(head, 1);
 head = insert(head, 4);
 head = insert(head, 3);
 head = insert(head->next, 2);
 cout << head->val << ", " << head->next->val << ", "  << head->next->next->val << endl;

}