#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root == NULL){
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // Base case - Empty tree
  if(node == NULL){
    node = new struct node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
  }

  // Else recurse down the BST
  if(node->key > key){
    node->left = insertNode(node->left,key);
  }else if(node->key < key){
    node->right = insertNode(node->right,key);
  }

  return node;
}

struct node *findMin(struct node *root){
  struct node *node = root;
  while(node->left != NULL){
    node = node->left;
  }
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Base case - Empty tree
  if(root == NULL){
    return root;
  }

  // Else recurse down the BST
  if(root->key > key){
    // If key is less than key of root
    root->left = deleteNode(root->left,key);
  }else if(root->key < key){
    // If key is greater than key of root
    root->right = deleteNode(root->right,key);
  }else{
    // When the required node is found
    if(root->left == NULL){
      return root->right;
    }else if(root->right == NULL){
      return root->left;
    }else{
      // If bothe children are not null, then replace node with the smallest in the right subtree)
      struct node *minNode = findMin(root->right);
      root->key = minNode->key;
      root->right = deleteNode(root->right,minNode->key);
    }
  }

  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}