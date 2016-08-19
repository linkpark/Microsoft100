#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Node_ {
  int val;
  struct Node_* left;
  struct Node_* right;

  Node_():val(0), left(NULL), right(NULL) { }
} TreeNode;

void AddTreeNode( TreeNode* root, int val ) {
  if( root == NULL ) return;

  if( root->val < val ) {
    if( root->right == NULL ) {
      TreeNode *node = new TreeNode();
      node->val = val;
      root->right = node;
    } else {
      AddTreeNode( root->right, val ); 
    }
  } else {
    if( root->left == NULL ) {
      TreeNode *node = new TreeNode();
      node->val = val;
      root->left = node;
    } else {
      AddTreeNode( root->left, val );
    } 
  }
}

TreeNode* BuildTree( vector<int> &array ) {
  TreeNode *root = new TreeNode();
  root->val = array.front();

  for( size_t i = 1 ; i < array.size(); ++i ) {
    AddTreeNode( root, array[i] );
  }

  return root;
} 

int main() {
  
}


