#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 50
#define MAX_INFO_SIZE 100
#define MAX_TABLE_SIZE 10
#define DJB2_HASH_NUMBER 5381

typedef struct Person {
    char name[MAX_NAME_SIZE];
    char info[MAX_INFO_SIZE];
    struct Person *next;
} Person;

Person *hashTable[MAX_TABLE_SIZE];

unsigned int hash(const char *str);
void insert_person(const char *name, const char *info);
void search_person(const char *name);

int main(void) {

    insert_person("Ali", "Age 23, City: Rasht");
    insert_person("Ali", "Age 20, City: Langarud");
    insert_person("Reza", "Age: 18 City: Lahijan");

    char name[MAX_NAME_SIZE];

    printf("Welcome to hash, type 'end' to stop the program.\n");
    printf("\n");
    while (1) {
        printf("Enter a name to search: ");
        if (!fgets(name, sizeof(name), stdin)) {
            printf("Input Error\n");
            break;
        }

        int nameStrLen = strlen(name);
        if (nameStrLen > 0 && name[nameStrLen - 1] != '\n') {
            printf("Name cannot be bigger than 49 characters\n");
            int bufferTrashCan = 0;
            while ((bufferTrashCan = getchar()) != '\n' && bufferTrashCan != EOF);
            continue;
        }

        name[strcspn(name, "\n")] = '\0';

        if (name[0] == '\0') {
            printf("Input cannot be empty\n");
            continue;
        }

        if (strcmp(name, "end") == 0) {
            printf("\nProgram ended\n\n");
            break;
        }

        search_person(name);
        printf("\n");
    }
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        Person *current = hashTable[i];
        while(current != NULL) {
            Person *temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
    return 0;
}

unsigned int hash(const char *str) {
    if (str == NULL) {
        printf("name is NULL\n");
        return 0;
    }
    unsigned long hashNumber = DJB2_HASH_NUMBER;
    int character = 0; 

    while((character = *str++)) {
        hashNumber = ((hashNumber << 5) + hashNumber) + character;
    }
    return hashNumber % MAX_TABLE_SIZE;
}

void insert_person(const char *name, const char *info) {
    unsigned int hashIndex = hash(name);
    Person *newPerson = malloc(sizeof(Person));

    if (!newPerson) {
        printf("memory allocation has faild!\n");
        return;
    }

    strcpy(newPerson->name, name);
    strcpy(newPerson->info, info);
    newPerson->next = NULL;

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newPerson;
    }
    else {
        newPerson->next = hashTable[hashIndex];
        hashTable[hashIndex] = newPerson;
    }
}

void search_person(const char *name) {
    unsigned int hashIndext = hash(name);
    Person *current = hashTable[hashIndext];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found person: name: %s info: %s\n", name, current->info);
        } 
        current = current->next;
    }
    return;
    printf("Person not found\n");
}