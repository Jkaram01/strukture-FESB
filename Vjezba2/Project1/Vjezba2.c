#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Person {
    char name[50];
    char surname[50];
    int birthYear;
    struct Person* next;
} Person;


Person* addToBeginning(Person* head, const char* name, const char* surname, int birthYear) {
    Person* newPerson = (Person*)malloc(sizeof(Person));

    if (newPerson == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    strcpy(newPerson->name, name);
    strcpy(newPerson->surname, surname);
    newPerson->birthYear = birthYear;
    newPerson->next = head;

    return newPerson;
}


Person* addToEnd(Person* head, const char* name, const char* surname, int birthYear) {
    Person* newPerson = (Person*)malloc(sizeof(Person));

    if (newPerson == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    strcpy(newPerson->name, name);
    strcpy(newPerson->surname, surname);
    newPerson->birthYear = birthYear;
    newPerson->next = NULL;

    if (head == NULL) {
        return newPerson;
    }

    Person* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newPerson;

    return head;
}


void printList(Person* head) {
    Person* current = head;

    printf("List of people:\n");
    while (current != NULL) {
        printf("Name: %s, Surname: %s, Birth Year: %d\n", current->name, current->surname, current->birthYear);
        current = current->next;
    }
}


void freeList(Person* head) {
    while (head != NULL) {
        Person* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Person* list = NULL; 

    list = addToBeginning(list, "Josip", "Karaman", 2003);
    list = addToEnd(list, "Ivo", "Javorcic", 1989);

    printList(list);

    freeList(list);

    return 0;
}
