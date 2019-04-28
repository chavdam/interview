#include<iostream>
using namespace std;

typedef struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int d):data(d),left(NULL),right(NULL){
  }
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

void inorder_traversal(TreeNode* h){
  if(h == NULL)
    return;

  inorder_traversal(h->left);
  cout << h->data << "   ";
  inorder_traversal(h->right);

}

void preorder_traversal(TreeNode* h){
  if(h == NULL)
    return;

  cout << h->data << "   ";
  inorder_traversal(h->left);
  inorder_traversal(h->right);

}

void postorder_traversal(TreeNode* h){
  if(h == NULL)
    return;

  inorder_traversal(h->left);
  inorder_traversal(h->right);
  cout << h->data << "   ";
}

void LCA(int v1, int v2, TreeNode* h){
  if(h == NULL)
    return;
  if(v1 <= h->data && v2 <= h->data)
    LCA(v1, v2, h->left);
  else if(v1 > h->data && v2 > h->data)
    LCA(v1, v2, h->right);
  else
    cout << "LCA => " << h->data;
}

int main(){

  insert(8);
  insert(5);
  insert(12);
  insert(3);
  insert(9);
  insert(4);
  insert(13);
  insert(2);

  cout << endl << "In-Order traversal ... "<< endl;
  inorder_traversal(head);
  cout << endl << "Pre-Order traversal ... "<< endl;
  preorder_traversal(head);
  cout << endl << "Post-Order traversal ... "<< endl;
  postorder_traversal(head);
  cout <<endl;

  LCA(2,3,head);


  return 0;
}

//      8
//    5    12
//  3     9