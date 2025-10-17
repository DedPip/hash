#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_INFO_SIZE 100
#define MAX_TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME_SIZE];
    char info[MAX_INFO_SIZE];
} Person;

Person hashTable[MAX_TABLE_SIZE];

unsigned int hash(const char *str) {
    if (str == NULL) {
        printf("name is NULL\n");
        return 1;
    }
    unsigned int sum = 0;
    while (*str) {
        sum += *str;
        str++;
    }
    return sum % MAX_TABLE_SIZE;
}

void insert_person(const char *name, const char *info) {
    unsigned int hashIndex = hash(name);
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

int main(void) {
    
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        memset(hashTable[i].name, 0, MAX_NAME_SIZE);
        memset(hashTable[i].info, 0, MAX_INFO_SIZE);
    }

    insert_person("Ali", "Age 20, City: Langarud");
    insert_person("Reza", "Age: 18 City: Lahijan");

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