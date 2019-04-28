#include<iostream>
#include<stack>

using namespace std;

typedef struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int d):data(d), left(NULL), right(NULL){}
} TreeNode;

TreeNode* head = NULL;

void insert(int data){
  TreeNode* newNode = new TreeNode(data);

  if(head == NULL){
    head = newNode;
  }
  else{
    TreeNode* tempNode = head;
    TreeNode* tempParentNode = head;

    while(tempNode != NULL){
      tempParentNode = tempNode;
      if(data <= tempNode->data)
        tempNode = tempNode->left;
      else 
        tempNode = tempNode->right;
    }

    if(data <= tempParentNode->data)
      tempParentNode->left = newNode;
    else
      tempParentNode->right = newNode;
  }
}

void inorder_traversal(TreeNode* head){
  TreeNode* curr = head;
  stack<TreeNode*> s;

  while(curr != NULL || !s.empty()){
    while(curr != NULL){
      s.push(curr);
      curr = curr->left;
    }

    curr = s.top();
    s.pop();
    cout << curr->data << " ";

    curr = curr->right;
  }
}

void preorder_traversal2(TreeNode* h){
  TreeNode* curr = h;
  if(curr == NULL)
    return;

  cout << curr->data << " ";
  inorder_traversal(curr->left);
  inorder_traversal(curr->right);

}

void preorder_traversal(TreeNode* head){
  TreeNode* curr = head;
  stack<TreeNode* > s;

  while(curr != NULL || !s.empty()){
    while(curr != NULL){
      cout << curr->data << " ";
      s.push(curr);
      curr = curr->left;
    }

    curr = s.top();
    s.pop();

    curr = curr->right;
  }


}

int main(){

  insert(18);
  insert(10);
  insert(25);
  insert(15);
  insert(35);
  insert(8);
  insert(22);

  inorder_traversal(head);
  cout << endl;
  preorder_traversal2(head);
  cout << endl;
  //preorder_traversal2(head);
  cout << endl;

  return 0;
}

/*
        18
  10              25
8      15     22         35

18  10  8  15  25  22  35 

*/