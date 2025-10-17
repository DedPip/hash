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

int main(void) {

}