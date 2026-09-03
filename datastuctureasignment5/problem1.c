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

struct Node
{
    int studentID;
    struct Node *next;
};

int main()
{
    struct Node *HEAD = NULL;
    struct Node *newNode;
    struct Node *temp;
    int n, i;


    printf("Enter number of students: ");
    scanf("%d", &n);

  
    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter Student ID %d: ", i);
        scanf("%d", &newNode->studentID);

        newNode->next = NULL;

        if (HEAD == NULL)
        {
            HEAD = newNode;
        }
        else
        {
    
            temp = HEAD;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

        
            temp->next = newNode;
        }
    }

    printf("\nStudent Records:\n");

    temp = HEAD;

    while (temp != NULL)
    {
        printf("Student ID: %d\n", temp->studentID);
        temp = temp->next;
    }

    return 0;
}