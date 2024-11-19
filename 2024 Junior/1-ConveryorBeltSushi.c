#include <stdio.h>

int main() {
    int R = 0; // Number of red plates
    int G = 2; // Number of green plates
    int B = 4; // Number of blue plates
    int C = R*3 + G*4 + B*5; // Total
    printf("The meal costs %d$", C);
    return 0;
}