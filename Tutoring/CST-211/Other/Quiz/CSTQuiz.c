#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int averageCalc(int numberOfElements, int array[]);

int main() {
    int r,c;
    printf("Input Row Size: ");
    scanf("%d", &r);
    printf("\nInput Column Size: ");
    scanf("%d", &c);

    int intArray[r*c];

    for(int i = 0; i < (r * c); i++){
        intArray[i] = (rand() % 100) + 1;
        //printf("%i\n", intArray[i]);
    }

    printf("Average: %i", averageCalc((r*c), intArray));

    return 0;
}

int averageCalc(int numberOfElements, int array[]) {
    int av = 0;
    for(int i = 0; i < numberOfElements; i++){
        av = av + array[i];
    }
    printf("Av: %i\n", av);
    av = ceil((float)av / (numberOfElements));
    return av;
}