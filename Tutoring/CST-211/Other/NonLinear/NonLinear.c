#include <stdio.h>
#include <stdlib.h>

void halfArray(int numberOfElements, int* array);

void main() {

    int a, b, c, j;
    int data[100];
    
    // reset Data
    //for(int i = 0; i < sizeof(data); i++) {
    //    data[i] = 0;
    //}

    printf("Input first term: ");
    scanf("%d", &a);
    printf("\nInput second term: ");
    scanf("%d", &b);

    printf("\nRunning Algorithm.\n");
    printf("%i\n%i\n", a, b);

    while (b < 1000000000) {
        c = a + b;
        a = b;
        b = c;
        data[j] = c;
        printf("%i\n", c);
        j++;
    }

    printf("Print Data Array Contents: \n"); 
    for(int i = 0; i < j; i++) {
        if(i == 0) {
            printf("%i", data[i]);
        } else {
            printf(", %i", data[i]);
        }
    }

    // Remove the odd elements of the Array, and reformat.
    halfArray(j, data);

    // Display final array
    printf("\n\nPrint Data Array Contents (Halfed): \n"); 
    for(int i = 0; i < j; i++) {
        if(i == 0) {
            printf("%i", data[i]);
        } else {
            printf(", %i", data[i]);
        }
    }

}

void halfArray(int numberOfElements, int array[]) {
    int n = 0;
    for (int i = 0; i < numberOfElements; i+=2) {
        array[n] = array[i];
        array[i] = 0;
        n++;
    }

    // Clean Array
    for (int i = n; i < numberOfElements; i++) {
        array[i] = 0;
    }
}