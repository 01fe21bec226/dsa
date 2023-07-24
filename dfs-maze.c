#include <stdio.h>
#include <stdbool.h>
// Function to initialize the visited array
void initializeVisited(int size, int visited[size][size]) {
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
visited[i][j] = 0;
}
}
}
// Function to check if a cell is valid and unvisited
bool isCellValid(int size, int row, int col, int maze[size][size], int visited[size][size]) {
return (row >= 0 && row < size && col >= 0 && col < size && maze[row][col] == 0 &&
visited[row][col] == 0);
}
// DFS algorithm to solve the maze
bool solveMazeDFS(int size, int row, int col, int maze[size][size], int visited[size][size]) {
// Check if the current cell is the goal
if (row == size - 1 && col == size - 1) {
visited[row][col] = 1;
return true; // Maze is solved
}
// Mark the current cell as visited
visited[row][col] = 1;
// Check all possible directions
if (isCellValid(size, row - 1, col, maze, visited) && solveMazeDFS(size, row - 1, col, maze, visited)) {
return true;
}
if (isCellValid(size, row, col + 1, maze, visited) && solveMazeDFS(size, row, col + 1, maze, visited))
{
return true;
}
if (isCellValid(size, row + 1, col, maze, visited) && solveMazeDFS(size, row + 1, col, maze, visited))
{
return true;
}
if (isCellValid(size, row, col - 1, maze, visited) && solveMazeDFS(size, row, col - 1, maze, visited)) {
return true;
}
// No valid paths, backtrack
visited[row][col] = 0;
return false;
}
// Function to print the solved maze
void printMaze(int size, int visited[size][size]) {
printf("Solved Maze:\n");
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
printf("%d ", visited[i][j]);
}
printf("\n");
}
}
int main() {
int size;
printf("Enter the size of the maze: ");
scanf("%d", &size);
int maze[size][size];
int visited[size][size];
printf("Enter the maze structure (0s and 1s) row by row:\n");
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
scanf("%d", &maze[i][j]);
}
}
initializeVisited(size, visited);
int startRow = 0;
int startCol = 0;
if (solveMazeDFS(size, startRow, startCol, maze, visited)) {
printf("Maze is solvable!\n");
printMaze(size, visited);
} else {
printf("Maze is not solvable.\n");
}
return 0;
}
