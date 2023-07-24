#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
// Structure for a routing table entry
struct RoutingEntry {
char ip[20];
char nextHop[20];
};
// Structure for the hash table
struct HashTable {
struct RoutingEntry* table[TABLE_SIZE];
};
// Function to create a new routing table entry
struct RoutingEntry* createEntry(const char* ip, const char* nextHop) {
struct RoutingEntry* newEntry = (struct RoutingEntry*)malloc(sizeof(struct RoutingEntry));
strcpy(newEntry->ip, ip);
strcpy(newEntry->nextHop, nextHop);
return newEntry;
}
// Function to create a new hash table
struct HashTable* createHashTable() {
struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
for (int i = 0; i < TABLE_SIZE; i++) {
hashTable->table[i] = NULL;
}
return hashTable;
}
// Hash function 1
int hash1(const char* ip) {
int sum = 0;
for (int i = 0; ip[i] != '\0'; i++) {
sum += ip[i];
}
return sum % TABLE_SIZE;
}
// Hash function 2
int hash2(const char* ip) {
int sum = 0;
for (int i = 0; ip[i] != '\0'; i++) {
sum += ip[i];
}
return (sum % (TABLE_SIZE - 2)) + 1;
}
// Function to insert a routing entry into the hash table
void insert(struct HashTable* hashTable, const char* ip, const char* nextHop) {
int index = hash1(ip);
int step = hash2(ip);
while (hashTable->table[index] != NULL) {
index = (index + step) % TABLE_SIZE;
}
struct RoutingEntry* newEntry = createEntry(ip, nextHop);
hashTable->table[index] = newEntry;
}
// Function to lookup the next hop associated with an IP address
const char* lookup(struct HashTable* hashTable, const char* ip) {
int index = hash1(ip);
int step = hash2(ip);
while (hashTable->table[index] != NULL) {
if (strcmp(hashTable->table[index]->ip, ip) == 0) {
return hashTable->table[index]->nextHop;
}
index = (index + step) % TABLE_SIZE;
}
return "Not Found";
}
int main() {
int numEntries;
printf("Enter the number of routing table entries: ");
scanf("%d", &numEntries);
struct HashTable* hashTable = createHashTable();
for (int i = 0; i < numEntries; i++) {
char ip[20];
char nextHop[20];
printf("Enter IP address for entry %d: ", i + 1);
scanf("%s", ip);
printf("Enter next hop for entry %d: ", i + 1);
scanf("%s", nextHop);
insert(hashTable, ip, nextHop);
}
char searchIp[20];
printf("Enter the IP address to lookup: ");
scanf("%s", searchIp);
const char* nextHop = lookup(hashTable, searchIp);
if (strcmp(nextHop, "Not Found") == 0) {
printf("IP address not found in the routing table.\n");
} else {
printf("Next hop for %s: %s\n", searchIp, nextHop);
}
return 0;
}
