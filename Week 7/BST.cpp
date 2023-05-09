#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//finding node with smallest key in a subtree
struct node* findMin(struct node* root){
  if(root==NULL){ //if tree is empty return null
    return NULL;
  }
  else if(root->left!=NULL){ //otherwise search left subtree for the smallest key
    return findMin(root->left);

  }
  return root;

}
// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root==NULL){
    return;
  }
  //traverse in the order of left->root->right
  traverseInOrder(root->left);
  cout<<root->key<<" ";
  traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node==NULL){ //if the node is a leaf of the tree
    node=new struct node;
    node->key=key;
    node->left=NULL;
    node->right=NULL;
  }

  else if(node->key<key){ //when the node value is lower than the key
    node->right=insertNode(node->right,key); //inserting to the right subtree
  }

  else{ //when the node value is higher than the key
    node->left=insertNode(node->left,key);// inserting to the left subtree
  }
  return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root==NULL){
    return NULL;
  }

  else if(root->key>key){ //when the node value is higher than the key search a node in the left subtree
    root->left=deleteNode(root->left,key);
  }

  else if(root->key<key){//when the node value is lower than the key search a node in the right subtree
    root->right=deleteNode(root->right,key);
  }

  else{//found the node
    if(root->right==NULL && root->left==NULL){//when the node has no child
      delete root;
      root=NULL;
      return root;
    }

    else if(root->right==NULL){//when the node has only one child
      struct node* temp=root->left;
      delete root;
      return temp;
    }

    else if(root->left==NULL){//when the node has only one child
      struct node* temp=root->right;
      delete root;
      return temp;
    }
    //when the node has two children
    //finding the minimum value in the right subtree
    struct node* temp=findMin(root->right);
    root->key=temp->key;
    root->right=deleteNode(root->right,temp->key);
  }
 
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