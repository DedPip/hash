#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 50
#define MAX_INFO_SIZE 100
#define MAX_TABLE_SIZE 100
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

    insert_person("Reza Gholami", "Age: 18 City: Lahijan");
    insert_person("Sara Ahmadi", "Age: 25 City: Tehran");
    insert_person("Sara Ahmadi", "Age: 27 City: Shiraz");
    insert_person("Ali Hosseini", "Age: 30 City: Mashhad");
    insert_person("Mina Rahimi", "Age: 22 City: Shiraz");
    insert_person("Mohammad Karimi", "Age: 27 City: Tabriz");
    insert_person("Fatemeh Rezaei", "Age: 19 City: Isfahan");
    insert_person("Hossein Jafari", "Age: 33 City: Rasht");
    insert_person("Niloofar Tavakoli", "Age: 21 City: Yazd");
    insert_person("Amir Hosseinzadeh", "Age: 29 City: Kerman");
    insert_person("Elham Moradi", "Age: 26 City: Qazvin");
    insert_person("Sina Ebrahimi", "Age: 24 City: Hamedan");
    insert_person("Zahra Khademi", "Age: 28 City: Karaj");
    insert_person("Mehdi Abbasi", "Age: 31 City: Gorgan");
    insert_person("Maryam Bahrami", "Age: 23 City: Sanandaj");
    insert_person("Pouya Azizi", "Age: 34 City: Ardabil");
    insert_person("Shirin Hashemi", "Age: 22 City: Bushehr");
    insert_person("Nima Norouzi", "Age: 20 City: Kashan");
    insert_person("Arezoo Parsa", "Age: 25 City: Khorramabad");
    insert_person("Behnam Sadeghi", "Age: 27 City: Qom");
    insert_person("Hanieh Ranjbar", "Age: 24 City: Birjand");
    insert_person("Ehsan Fattahi", "Age: 29 City: Urmia");
    insert_person("Yasaman Mohammadi", "Age: 21 City: Bandar Abbas");
    insert_person("Kaveh Rostami", "Age: 35 City: Dezful");
    insert_person("Sahar Jalali", "Age: 19 City: Zanjan");
    insert_person("Mostafa Alizadeh", "Age: 28 City: Ilam");
    insert_person("Parisa Dabbagh", "Age: 30 City: Ardakan");
    insert_person("Hamed Yousefi", "Age: 32 City: Tabriz");
    insert_person("Samira Niknejad", "Age: 23 City: Shiraz");
    insert_person("Navid Eskandari", "Age: 26 City: Tehran");
    insert_person("Leila Mousavi", "Age: 22 City: Rasht");
    insert_person("Armin Shafiei", "Age: 25 City: Kermanshah");
    insert_person("Negar Ghasemi", "Age: 19 City: Mashhad");
    insert_person("Morteza Javan", "Age: 34 City: Yazd");
    insert_person("Shahram Kiani", "Age: 27 City: Ahvaz");
    insert_person("Pegah Bakhshi", "Age: 24 City: Karaj");
    insert_person("Reyhaneh Mansouri", "Age: 20 City: Isfahan");
    insert_person("Nader Farhadi", "Age: 33 City: Gilan");
    insert_person("Sara Esmaeili", "Age: 21 City: Tonekabon");
    insert_person("Hamid Kazemi", "Age: 36 City: Tehran");
    insert_person("Amin Safaei", "Age: 28 City: Mashhad");
    insert_person("Elena Firoozi", "Age: 22 City: Yazd");
    insert_person("Masoud Pahlavan", "Age: 31 City: Shiraz");
    insert_person("Zeinab Mohseni", "Age: 23 City: Kashan");
    insert_person("Ramin Nouri", "Age: 29 City: Bushehr");
    insert_person("Nazanin Pourreza", "Age: 20 City: Rasht");
    insert_person("Bahram Esfandiari", "Age: 37 City: Karaj");
    insert_person("Shiva Arjmand", "Age: 26 City: Ardabil");
    insert_person("Milad Hasani", "Age: 24 City: Qom");
    insert_person("Mona Sadri", "Age: 25 City: Hamedan");
    insert_person("Peyman Ghaffari", "Age: 32 City: Isfahan");
    insert_person("Tina Behzadi", "Age: 27 City: Lahijan");
    insert_person("Farzad Khorshidi", "Age: 30 City: Tehran");
    insert_person("Hoda Sabet", "Age: 23 City: Mashhad");
    insert_person("Saeed Zolfaghari", "Age: 28 City: Shiraz");
    insert_person("Roya Akbari", "Age: 19 City: Rasht");
    insert_person("Keyvan Fallah", "Age: 31 City: Karaj");
    insert_person("Elina Ramezani", "Age: 21 City: Yazd");
    insert_person("Yousef Madani", "Age: 35 City: Kerman");
    insert_person("Shima Asgari", "Age: 22 City: Isfahan");
    insert_person("Babak Khalili", "Age: 29 City: Tabriz");
    insert_person("Aida Mahdavi", "Age: 24 City: Tehran");
    insert_person("Farhad Salehi", "Age: 27 City: Shiraz");
    insert_person("Nasrin Khatibi", "Age: 20 City: Gorgan");
    insert_person("Elnaz Tavassoli", "Age: 25 City: Rasht");
    insert_person("Omid Rahbar", "Age: 33 City: Yazd");
    insert_person("Shahab Etemadi", "Age: 26 City: Ahvaz");
    insert_person("Golnaz Nematollahi", "Age: 23 City: Bushehr");
    insert_person("Parsa Dehghan", "Age: 19 City: Mashhad");
    insert_person("Sogand Shokri", "Age: 28 City: Isfahan");
    insert_person("Mahdi Yeganeh", "Age: 31 City: Karaj");
    insert_person("Donya Khorsandi", "Age: 22 City: Tehran");
    insert_person("Arash Ghadiri", "Age: 34 City: Shiraz");


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
    unsigned int hashIndex = hash(name);
    Person *current = hashTable[hashIndex];
    int personCount = 0;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found person: name: %s info: %s\n", current->name, current->info);
            personCount++;
        }
        current = current->next;
    }

    if (personCount == 0) {
        printf("Person not found!\n");
    }
}