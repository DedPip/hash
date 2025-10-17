#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_INFO_SIZE 100
#define MAX_TABLE_SIZE 10
#define DJB2_HASH_NUMBER 5381

typedef struct {
    char name[MAX_NAME_SIZE];
    char info[MAX_INFO_SIZE];
} Person;

Person hashTable[MAX_TABLE_SIZE];

unsigned int hash(const char *str);
void insert_person(const char *name, const char *info);
void search_person(const char *name);

int main(void) {
    
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        memset(hashTable[i].name, 0, MAX_NAME_SIZE);
        memset(hashTable[i].info, 0, MAX_INFO_SIZE);
    }

    insert_person("Ali", "Age 20, City: Langarud");
    insert_person("Reza", "Age: 18 City: Lahijan");
    insert_person("liA", "Age 20, City: Langarud");

    char name[MAX_NAME_SIZE];

    printf("Welcome to hash, type 'end' to stop the program.\n");
    printf("\n");
    while (1) {
        printf("Enter a name to search: ");
        scanf("%s", name);
        if (strcmp(name, "end") == 0) {
            printf("Program stopped\n");
            return 0;
        }
        search_person(name);
        printf("\n");
    }
}

unsigned int hash(const char *str) {
    if (str == NULL) {
        printf("name is NULL\n");
        return 0;
    }
    unsigned long hashNumber = DJB2_HASH_NUMBER;
    unsigned int character = 0; 

    while((character = *str++)) {
        hashNumber = ((hashNumber << 5) + hashNumber) + character;
    }
    return hashNumber % MAX_TABLE_SIZE;
}

void insert_person(const char *name, const char *info) {
    unsigned int hashIndex = hash(name);
    if (hashTable[hashIndex].name[0] != '\0') {
        printf("Insertion failed! Collision detected when inserting '%s' at index %u of %i it's occupied by '%s'\n", name, hashIndex, MAX_TABLE_SIZE, hashTable[hashIndex].name);
        return;
    }
    strcpy(hashTable[hashIndex].name, name);
    strcpy(hashTable[hashIndex].info, info);
}

void search_person(const char *name) {
    unsigned int hashIndex = hash(name);
    if (strcmp(hashTable[hashIndex].name, name) == 0)
    {
        printf("Person found: %s, %s\n", name, hashTable[hashIndex].info);
    }
    else {
        printf("Person not found\n");
    }
}