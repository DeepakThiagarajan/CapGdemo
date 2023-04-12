#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    long int phone;
    struct Employee* prev;
    struct Employee* next;
};

void push(struct Employee** top, int id, char name[], float salary, long int phone) {
    struct Employee* newNode = (struct Employee*) malloc(sizeof(struct Employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->salary = salary;
    newNode->phone = phone;
    newNode->prev = NULL;
    newNode->next = *top;
    if (*top != NULL) {
        (*top)->prev = newNode;
    }
    *top = newNode;
    printf("Employee added to stack.\n");
}

void pop(struct Employee** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Employee* temp = *top;
    *top = (*top)->next;
    if (*top != NULL) {
        (*top)->prev = NULL;
    }
    printf("Popped employee details:\n");
    printf("ID: %d\n", temp->id);
    printf("Name: %s\n", temp->name);
    printf("Salary: %.2f\n", temp->salary);
    printf("Phone: %ld\n", temp->phone);
}

void printEmployee(struct Employee emp) {
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    printf("Phone: %ld\n", emp.phone);
}

void printStack(struct Employee* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    struct Employee* curr = top;
    while (curr != NULL) {
        printEmployee(*curr);
        curr = curr->next;
    }
}

int main() {
    int choice, id;
    char name[50];
    float salary;
    long int phone;
    struct Employee* top = NULL;
    do {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &id);
                printf("Enter employee name: ");
                scanf("%s", name);
                printf("Enter employee salary: ");
                scanf("%f", &salary);
                printf("Enter employee phone number: ");
                scanf("%ld", &phone);
                push(&top, id, name, salary, phone);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                printStack(top);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
