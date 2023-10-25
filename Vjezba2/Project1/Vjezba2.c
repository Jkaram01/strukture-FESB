#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct _Person {
    char name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    int birthYear;
    struct _Person* next;
} Person;

typedef Person* Position;

Position createPerson() {
    Position newPerson = NULL;
    char name[MAX_LENGTH] = { 0 };
    char surname[MAX_LENGTH] = { 0 };
    int birthYear = 0;

    newPerson = (Position)malloc(sizeof(Person));
    if (!newPerson) {
        perror("Can't allocate memory!\n");
        return NULL;
    }

    printf("Enter name:\n");
    scanf(" %s", newPerson->name);
    printf("Enter surname:\n");
    scanf(" %s", newPerson->surname);
    printf("Enter birth year:\n");
    scanf(" %d", &newPerson->birthYear);

    newPerson->next = NULL;

    return newPerson;
}

Position addToBeginning(Position head) {
    Position newPerson = createPerson();
    if (newPerson == NULL) {
        return head;
    }

    newPerson->next = head;
    return newPerson;
}

Position addToEnd(Position head) {
    Position newPerson = createPerson();
    if (newPerson == NULL) {
        return head;
    }

    if (head == NULL) {
        return newPerson;
    }

    Position current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newPerson;
    return head;
}

void printList(Position head) {
    Position current = head;
    printf("List of people:\n");

    while (current != NULL) {
        printf("Name: %s, Surname: %s, Birth Year: %d\n", current->name, current->surname, current->birthYear);
        current = current->next;
    }
}

void freeList(Position head) {
    while (head != NULL) {
        Position temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Position head = NULL;

    head = addToBeginning(head);
    head = addToBeginning(head);
    head = addToEnd(head);
    head = addToEnd(head);
    printList(head);
    freeList(head);

    return 0;
}
