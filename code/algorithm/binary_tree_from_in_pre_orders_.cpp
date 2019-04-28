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

int findIndex(vector<int>& inorder, int item){
  int index = -1;
  for(int i=0; i<inorder.size(); i++){
    if(inorder[i] == item){
      index = i;
      break;
    }
  }
  return index;
}

TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int start, int end){
  if(start > end)
    return NULL;

  int data = preorder[start];
  TreeNode* newNode = new TreeNode(data);

  if(start == end)
    return newNode;
  
  int mid = findIndex(inorder, data);
  newNode->left = constructTree(preorder, inorder, start, mid-1);
  newNode->right = constructTree(preorder, inorder, mid+1, end);

  return newNode;
} 

int main(){
  int inorder[] = {1, 2, 4, 9, 14, 20, 22, 24, 30, 36};
  vector<int> inorderTraversal(inorder, inorder + (sizeof(inorder)/sizeof(inorder[0])));

  int preorder[] = {9, 4, 1, 2, 36, 14, 24, 20, 30, 22};
  vector<int> preorderTraversal(preorder, preorder + (sizeof(preorder)/sizeof(preorder[0])));

  TreeNode* head = NULL;
  head = constructTree(preorderTraversal, inorderTraversal, 0, preorderTraversal.size() - 1);

  //cout << getHeight(head);
  printLevelOrder(head);
  return 0;
}

/*

          9
                    36
    4          14     
  1               24
    2         20      30 
                   22

1 2  4  9   14   20 22 24 30  36 

*/