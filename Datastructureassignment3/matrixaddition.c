//write a c program using function to take input number in A 2*2 and B 2*2 matrix. Find the sum of A and B and store it in C 2*2
//matrix and print the A,B and C matrix.
#include <stdio.h>

void inputMatrix(int a[2][2], int b[2][2],int c[2][2]) {
    int i, j;
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < 2; i++) {   
        for (j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
}
int main() {
    int A[2][2], B[2][2], C[2][2];
    inputMatrix(A, B, C);
    
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Matrix A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("Sum of Matrix A and B (Matrix C):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
