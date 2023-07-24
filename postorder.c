#include <stdio.h>
#include <stdlib.h>
// Structure for a binary tree node
struct Node {
int data;
struct Node* left;
struct Node* right;
};
// Function to create a new binary tree node
struct Node* createNode(int data) {
// Allocate memory for a new node
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to build a binary tree from user input
struct Node* buildBinaryTree(int numNodes) {
if (numNodes <= 0) {
return NULL;
}
struct Node* root = NULL;
printf("Enter the data for the root node: ");
int data;
scanf("%d", &data);
root = createNode(data);
for (int i = 1; i < numNodes; i++) {
printf("Enter the data for node %d: ", i + 1);
scanf("%d", &data);
struct Node* currentNode = root;
while (1) {
printf("Insert node %d to the left or right of %d? (L/R): ", data, currentNode->data);
char choice;
scanf(" %c", &choice);
if (choice == 'L' || choice == 'l') {
if (currentNode->left == NULL) {
currentNode->left = createNode(data);
break;
} else {
currentNode = currentNode->left;
}
} else if (choice == 'R' || choice == 'r') {
if (currentNode->right == NULL) {
currentNode->right = createNode(data);
break;
} else {
currentNode = currentNode->right;
}
} else {
printf("Invalid choice. Please enter 'L' or 'R'.\n");
}
}
}
return root;
}
// Postorder traversal function for memory deallocation
void deallocateMemory(struct Node* root) {
if (root == NULL)
return;
// Deallocate memory of the left and right subtrees
deallocateMemory(root->left);
deallocateMemory(root->right);
// Print acknowledgment for deallocating the memory of the current node
printf("Deallocating memory for node with data: %d\n", root->data);
// Deallocate memory of the current node
free(root);
}
// Main function
int main() {
int numNodes;
printf("Enter the number of nodes in the binary tree: ");
scanf("%d", &numNodes);
// Build the binary tree based on user input
struct Node* root = buildBinaryTree(numNodes);
// Perform postorder traversal for memory deallocation
deallocateMemory(root);
return 0;
}
