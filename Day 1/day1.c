#include <stdio.h>
#include <limits.h>

//To run program, redirect from text file into program. Ex. ./day1.exe < input1.txt


int main() {
    int input;
    int num_increasing = 0;
    int previous_input = INT_MAX;
    while (scanf("%d ", &input) == 1) {
        if (previous_input < input) num_increasing++;
        previous_input = input;
    }

    printf("The input file has %d increasing terms\n", num_increasing);
}