#include <stdio.h>
int queue[10];
int front = -1;
int rear = -1;
void enqueue(int customer) {
    if (rear >= 9) {
        printf("Housefull! \n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = customer;
    printf("Customer %d added to the queue.\n", customer);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("No customers to serve.\n");
        return;
    }
    int customer = queue[front++];
    printf("Customer %d served and removed from the queue.\n", customer);
}
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("No customers in the queue.\n");
        return;
    }
    printf("Current customers in the queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int choice, customer;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add customer (enqueue)\n");
        printf("2. Serve customer (dequeue)\n");
        printf("3. Display all customers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter customer ID to add: ");
                scanf("%d", &customer);
                enqueue(customer);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}