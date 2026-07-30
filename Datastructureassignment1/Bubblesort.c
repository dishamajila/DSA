// A class-teacher has a list of marks of 10 students in a random fasion.
// All the marks are whole number.
// before publishing the result the class teacher wants to arrange the marks in an order so that the rank of the student can easily be ditected.
// Use a method to order the marks in accending order
// Which methodology you use here implement the method using C program.
//sample input:[99,85,58,71,46,80,78,65,49,55]
#include <stdio.h>

int main() {
    int marks[10] ={99,85,58,71,46,80,78,65,49,55};
    int i, j, temp;

    // Bubble Sort
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9 - i; j++) {
            if(marks[j] > marks[j + 1]) {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    printf("Marks in Ascending Order:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", marks[i]);
    }

    return 0;
}