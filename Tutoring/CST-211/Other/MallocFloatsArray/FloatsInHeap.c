#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main () {

    bool use_user_variables = true;  // Change this to true if you want to have users input

    int n = 0;

    if (use_user_variables) {
        printf("Input number of floats to store.\n");
        scanf("%d", &n);
    } else {
        n = 5;
    }
    
    float *floats = malloc((n + 2) * sizeof(float));
    
    int pos = 0;
    float *p;

    for (p = &floats[0]; p <= &floats[n + 1]; p++) {
        printf("Value of floats at [%d] is: %f\n", pos, *p);
        pos++;
    }

    if (use_user_variables) {
        for(int i = 0; i < n; i++) {
            printf("Input float %d.\n", i);
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
                floats[i] = strtof(in, NULL);
            } else {
                printf("Invalid input. Reinput value at %d.\n", i);
                i--;
            }
            
        }
/*
        int *p = &floats[0];
        *p = 0;

        p ==== &floats[0]

        *p ==== floats[0]

        int n = floats[0]; // n = 0;
*/
        pos = 0;
        for (p = &floats[0]; p <= &floats[n + 1]; p++) {
            printf("Value of floats at [%d] is: %f\n", pos, *p);
            pos++;
        }
    }
    

    printf("\n\nFilling floats array with random values between 1 and 10.\n\n");

    for (p = &floats[0]; p <= &floats[n + 1]; p++) {
        *p = (((float)rand()/(float)(RAND_MAX)) * 9) + 1;
    }

    pos = 0;
    for (p = &floats[0]; p <= &floats[n + 1]; p++) {
        printf("Value of floats at [%d] is: %f\n", pos, *p);
        pos++;
    }

    free(floats);
}