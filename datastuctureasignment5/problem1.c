//1. Case Study: Student Registration Management
//A university department wants to develop a simple system to maintain a list of students who have registered for a technical workshop.
//The number of students registering for the workshop is not fixed. Therefore, using a static array may result in either:
//•	Wastage of memory when fewer students register, or
//•	Insufficient space when more students register.
//To solve this problem, the software developer decides to use a Singly Linked List.
//Each student record will be represented using a node containing:
//•	Student ID
//•	Pointer to the next student
//The first node of the linked list is accessed through a pointer called HEAD.
//The department wants the system to perform the following basic operations:
//1.Create a singly linked list.
//2.Add student records dynamically.
//3.Traverse the linked list.
//4.Display all student records in the order in which they were added.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int studentID;
    struct Node *next;
};

struct Node *head = NULL;

void addStudent(int id) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->studentID = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        
        struct Node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Link new node at the end
        temp->next = newNode;
    }

    printf("Student ID %d registered successfully.\n", id);
}

// Function to display all students
void displayStudents() {
    struct Node *temp;
    int count = 1;

    if (head == NULL) {
        printf("No students registered yet.\n");
        return;
    }

    temp = head;

    printf("\n--- List of Registered Students ---\n");

    while (temp != NULL) {
        printf("%d. Student ID: %d\n", count, temp->studentID);
        temp = temp->next;
        count++;
    }

    printf("------------------------------------\n");
}

// Function to free allocated memory
void freeList() {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice, id;

    while (1) {
        printf("\n===== Workshop Student Registration =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                addStudent(id);
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                freeList();
                printf("Exiting program. Memory freed successfully.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}