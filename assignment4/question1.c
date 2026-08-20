// Bank account keeping the transaction amount as it is processed by customer 
// The transaction amount of last customer is stored at top position 
// After completion of all transaction, the manager pull the amount one by one and display the amount 
// And find total-transaction-amount to print.
// Define following function: push(): to insert amount in 
//                            pop(): to remove amount
//                            dosum(): find sum of transaction amout

#include <stdio.h>

int top = -1;
int arr[10];

void push(int val){
    if(top == 9){
        printf("Stack Overflow");
        return;
    }

    top++;
    arr[top] = val;
    return;
}

int pop(){
    if(top == -1){
        printf("Stack Overflow");
    }

    int temp = arr[top];
    top--;
    return temp;
}

int dosum(){
    int sum = 0;
    while(top != -1){
        int num = pop();
        sum += num;
    }
    return sum;
}

int main(){
    int ch;

    while(1){
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for dosum\n");
        printf("Enter 4 for break\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: {
            int n;
            printf("Enter the value: ");
            scanf("%d",&n);
            push(n);
            break;
        }
        case 2: {
            int n = pop();
            printf("Poped %d from the stack\n", n);
            break;
        }
        case 3: {
            int sum = dosum();
            printf("Sum : %d\n", sum);
            break;
        }
        case 4:
            return 0;
        default:
            printf("Wrong Choice!\n");
            break;
        }
    }
}