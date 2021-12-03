#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define LENGTH_OF_WINDOW 3


int updateArray(int[], int);
int sumOfArray(int[]);
void printArray();

int main() {
    int input_array[LENGTH_OF_WINDOW];
    int num_increasing = 0;
    int num_inputs = 0;
    int input;
    while (scanf("%d", &input) == 1) {
        if (num_inputs > LENGTH_OF_WINDOW - 1) {
            printArray(input_array);
            if (sumOfArray(input_array) < updateArray(input_array, input)) num_increasing++;
        } else {
            updateArray(input_array, input);
        }
        num_inputs++;
    }

    printf("The input file has %d increasing terms\n", num_increasing);
}


//Shifts array and returns the new sum
int updateArray(int inputs[], int val) {
    for(int i = LENGTH_OF_WINDOW - 1; i > 0; i--) inputs[i] = inputs[i-1];
    inputs[0] = val;
    return sumOfArray(inputs);
}


void printArray(int array[]) {
    printf("Array: { %d, %d, %d }\n", array[0], array[1], array[2]);
}

int sumOfArray(int inputs[]) {
    int sum = 0;
    for (int i = 0; i < LENGTH_OF_WINDOW; i++) {
        sum += inputs[i];
    };
    return sum;
}