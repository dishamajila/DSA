// Consider a book rack, where books are stacked one on top of the other. each book has acc-no (1,2,3...).if you are asked to place the book in
//stack using acc-no and take the book from stack using acc-no,how you perform these two operations on stack of books . the sequence of operation is
// given here: push(1),push(2),push(3),pop(3),push(4),push(5),pop(5) ,display the final position of the stack.
#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Final position of the stack:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, acc_no;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter accession number to be pushed: ");
                scanf("%d", &acc_no);
                push(acc_no);
                break;
            case 2:
                printf("Enter accession number to be popped: ");
                scanf("%d", &acc_no);
                if (top != -1 && stack[top] == acc_no) {
                    pop();
                } else {
                    printf("Accession number %d is not at the top of the stack\n", acc_no);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}