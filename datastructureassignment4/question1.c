//bank account is keeping the transaction amount as it is processed by customer. 
//the transaction amount of last customer is stored at the top position. After completion of all the transaction, the manager pull the 
//amount one by  one and display the amount and find total_transaction_amount to print.
// Define following function
// push(): to insert amount in stack
// pop(): to remove amount from stack
// dosum(): find sum of all transaction amount
// amount inserted in the following order: 1050, 2090,3000,6000,5500,8900
#include <stdio.h>
int stack[100];
int top = -1;
int total_transaction_amount = 0;
void push(int amount) {
    if (top >= 99) {
        printf("Stack overflow! Cannot insert more amounts.\n");
        return;
    }
    stack[++top] = amount;
    printf("Amount %d inserted into stack.\n", amount);
}
void pop() {
    if (top < 0) {
        printf("Stack underflow! No amounts to remove.\n");
        return;
    }
    int amount = stack[top--];
    printf("Amount %d removed from stack.\n", amount);
}
int dosum() {
    int sum = 0;
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }
    return sum;
}
int main() {
    int choice, amount;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert amount (push)\n");
        printf("2. Remove amount (pop)\n");
        printf("3. Display total transaction amount (dosum)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter amount to insert: ");
                scanf("%d", &amount);
                push(amount);
                break;
            case 2:
                pop();
                break;
            case 3:
                total_transaction_amount = dosum();
                printf("Total transaction amount: %d\n", total_transaction_amount);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}