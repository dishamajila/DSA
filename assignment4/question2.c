// Single Screen Cinema hall has one ticket counter.
// One customer arrives at a time. Simulate the ticket counter using queue.
// The requirments are: Add Customer
//                      Serve Customer
//                      Show "HOUSE FULL" if the seates are full
//                      Display alll customer

#include <stdio.h>

int arr[10];
int front = -1;
int rear = -1;

void enqueue(int val){
    if(rear == 9){
        printf("HOUSEFULL");
        return;
    }
    
    rear++;
    arr[rear] = val;
    return;
}

int dequeue(){
    if(front == rear){
        front = -1;
        rear = -1;
        printf("No Customer To Serve");
        return -1;
    }

    int temp = arr[front];
    front++;

    return temp;
}

void display(){
    while(front < rear){
        printf("%d ", arr[front]);
        front++;
    }
    printf("\n");

    front = -1;
    rear = -1;
}

int main(){
    int ch;

    while(1){
        printf("Enter 1 to Add Customer\n");
        printf("Enter 2 to Serve Customer\n");
        printf("Enter 3 to Display Customer\n");
        printf("Enter 4 to Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: {
            int n;
            printf("Enter Customer ID: ");
            scanf("%d",&n);
            enqueue(n);
            break;
        }
        case 2: {
            int n = dequeue();
            printf("Serveed Customer with ID : %d\n", n);
            break;
        }
        case 3: {
            display();
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