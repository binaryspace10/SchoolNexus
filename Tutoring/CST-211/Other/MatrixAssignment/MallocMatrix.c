#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void main() {
        
    int rows, columns; 

    printf("Input rows and columns of floatMatrix.\n");
    printf("Rows: ");
    scanf("%i", &rows);
    printf("Columns: ");
    scanf("%i", &columns);

    printf("\n\nCreating a %i x %i matrix.\n", rows, columns);

    int *floatMatrix = malloc(((rows * columns) + 1) * sizeof(int));

    int n = 1;
    for(int i = 0; i < (rows * columns); i++) {
        printf("Input float at position (%i, %i).\n", n, (i % columns) + 1);
        char in[30];
        scanf("%s", in);

        printf("Input is: %s\n", in);

        bool valid = true;
        for(int j = 0; j < sizeof(in); j++) {
            if(in[j] == 0) {
                break;
            }
            if(in[j] > 45 && in[j] < 58 && in[j] != 47) {
                //we are good
            } else {
                //printf("Input is: %d\n\n", in[j]);
                valid = false; 
                break;
            }
        }

        if(valid) {
            floatMatrix[i] = strtof(in, NULL);
            if((i+1) % columns == 0)
                n++;
        } else {
            printf("Invalid input. Reinput value at %d.\n", i);
            i--;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%i ", floatMatrix[(columns * i) + j]);
        }
        printf("\n\n");
    } 

    /*
    c = 3
    r = 2

    1,2,3
    4,5,6

    1,2,3,4,5,6
    */
}
