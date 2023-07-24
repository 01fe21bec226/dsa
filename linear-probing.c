#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
struct Entry {
char* key;
int value;
};
struct SymbolTable {
struct Entry* table;
};
// Hash function to convert a key into an index
int hash(char* key) {
int sum = 0;
for (int i = 0; key[i] != '\0'; i++) {
sum += key[i];
}
return sum % TABLE_SIZE;
}
// Initialize the symbol table
void initSymbolTable(struct SymbolTable* st) {
st->table = (struct Entry*)malloc(TABLE_SIZE * sizeof(struct Entry));
for (int i = 0; i < TABLE_SIZE; i++) {
st->table[i].key = NULL;
st->table[i].value = -1;
}
}
// Insert a key-value pair into the symbol table
void insert(struct SymbolTable* st, char* key, int value) {
int index = hash(key);
// Linear probing to find the next available slot
while (st->table[index].key != NULL) {
index = (index + 1) % TABLE_SIZE;
}
// Insert the entry at the index
st->table[index].key = strdup(key);
st->table[index].value = value;
}
// Search for a key in the symbol table
int search(struct SymbolTable* st, char* key) {
int index = hash(key);
// Linear probing to search for the key
while (st->table[index].key != NULL) {
if (strcmp(st->table[index].key, key) == 0) {
return st->table[index].value;
}
index = (index + 1) % TABLE_SIZE;
}
// Key not found
return -1;
}
int main() {
int numEntries;
char key[50];
int value;
struct SymbolTable st;
initSymbolTable(&st);
printf("Enter the number of key-value pairs: ");
scanf("%d", &numEntries);
for (int i = 0; i < numEntries; i++) {
printf("Enter key %d: ", i + 1);
scanf("%s", key);
printf("Enter value for key %s: ", key);
scanf("%d", &value);
insert(&st, key, value);
}
// Search for keys in the symbol table
printf("Value for key 'apple': %d\n", search(&st, "apple"));
printf("Value for key 'cat': %d\n", search(&st, "cat"));
printf("Value for key 'elephant': %d\n", search(&st, "elephant"));
printf("Value for key 'lion': %d\n", search(&st, "lion"));
return 0;
}
