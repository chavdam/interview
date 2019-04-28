#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int d):data(d), left(NULL), right(NULL){
  }
}TreeNode;

TreeNode* insert(TreeNode* root, int data){
  TreeNode* temp = root;
  TreeNode* newNode = new TreeNode(data);

  if(temp == NULL){
    root = newNode;
  }
  else{
    TreeNode* parentNode;
    while(temp != NULL){
      parentNode = temp;
      if(data <= temp->data){
        temp = temp->left;
      }
      else{
        temp = temp->right;
      }
    }
    if(data <= parentNode->data){
      parentNode->left = newNode;
    }
    else{
      parentNode->right = newNode;
    }
  }

  return root;
}

int getHeight(TreeNode* root){
  TreeNode* temp = root;
  if(temp == NULL)
    return 0;
  return max(getHeight(temp->left), getHeight(temp->right)) + 1;
}

void printLevelOrderHelper(TreeNode* root, int height, int space){
  TreeNode* temp = root;
  if(temp == NULL)
    return;

  if(height == 1){
    cout << string(space, ' ') << root->data ;
    return;
  }
  else{
    printLevelOrderHelper(temp->left, height-1, space);
    printLevelOrderHelper(temp->right, height-1, space*2);
    //cout << endl;
  }
}

void printLevelOrder(TreeNode* root){
  int height = getHeight(root);
  for(int h=1; h<=height; h++){
    printLevelOrderHelper(root, h, 10 - h);
    cout << endl;
  }
}

int main(){
  TreeNode* head = NULL;
  head = insert(head, 18);
  insert(head, 9);
  insert(head, 36);
  insert(head, 14);
  insert(head, 4);
  insert(head, 1);
  insert(head, 2);
  insert(head, 24);
  insert(head, 30);
  insert(head, 20);
  insert(head, 22);
  //cout << getHeight(head);
  printLevelOrder(head);
  return 0;
}