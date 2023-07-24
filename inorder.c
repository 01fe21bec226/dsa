#include <stdio.h>
#include <stdlib.h>
// Definition of a node in the Binary Search Tree
struct Node {
int value;
struct Node* left;
struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
// Allocate memory for the new node
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->value = value;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to insert a node into the Binary Search Tree
struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->value) {
root->left = insert(root->left, value);
} else if (value > root->value) {
root->right = insert(root->right, value);
}
return root;
}
// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
if (root == NULL)
return;
// Traverse the left subtree
inorderTraversal(root->left);
// Visit the current node
printf("%d ", root->value);
// Traverse the right subtree
inorderTraversal(root->right);
}
int main() {
int numNodes, data;
struct Node* root = NULL;
printf("Enter the number of nodes in the Binary Search Tree: ");
scanf("%d", &numNodes);
printf("Enter the data for each node:\n");
for (int i = 0; i < numNodes; i++) {
scanf("%d", &data);
root = insert(root, data);
}
// Perform inorder traversal to sort the BST
printf("Sorted elements: ");
inorderTraversal(root);
printf("\n");
return 0;
}
