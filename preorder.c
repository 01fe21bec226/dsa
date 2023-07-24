#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node {
char data;
struct Node* left;
struct Node* right;
};
// Function to create a new node for the expression tree
struct Node* createNode(char data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = newNode->right = NULL;
return newNode;
}
// Function to build the expression tree from prefix notation
struct Node* buildExpressionTree(char prefix[]) {
struct Node* stack[100];
int top = -1;
// Traverse the prefix expression from right to left
for (int i = strlen(prefix) - 1; i >= 0; i--) {
char symbol = prefix[i];
if (isdigit(symbol)) {
// If the symbol is a digit, create a new node and push it to the stack
struct Node* operand = createNode(symbol);
stack[++top] = operand;
} else {
// If the symbol is an operator, create a new node and set its left and right child
struct Node* operator = createNode(symbol);
operator->left = stack[top];
operator->right = stack[top - 1];
top -= 2;
stack[++top] = operator;
}
}
return stack[top];
}
// Function to evaluate the expression tree
int evaluateExpressionTree(struct Node* root) {
if (root->left == NULL && root->right == NULL) {
// If the root is a leaf node (operand), return its value
return root->data - '0';
} else {
// If the root is an operator, recursively evaluate its left and right subtrees
int leftOperand = evaluateExpressionTree(root->left);
int rightOperand = evaluateExpressionTree(root->right);
switch (root->data) {
case '+':
return leftOperand + rightOperand;
case '-':
return leftOperand - rightOperand;
case '*':
return leftOperand * rightOperand;
case '/':
return leftOperand / rightOperand;
}
}
return 0;
}
int main() {
char prefix[50] ;
// Build the expression tree from the given prefix notation
struct Node* expressionTree = buildExpressionTree(prefix);
printf("Enter Expression\n");
scanf(“%s”,prefix);
printf("Result: %d\n", evaluateExpressionTree(expressionTree));
return 0;
}
