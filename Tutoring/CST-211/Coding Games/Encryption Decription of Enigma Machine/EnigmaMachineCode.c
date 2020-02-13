#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    
    char rot1[27];
    char rot2[27];
    char rot3[27];
    
    char operation[257];
    fgets(operation, 257, stdin);
    int pseudo_random_number;
    scanf("%d", &pseudo_random_number); fgetc(stdin);
    for (int i = 0; i < 3; i++) {
        char rotor[27];
        fgets(rotor, 27, stdin); fgetc(stdin);
        
        for (int j = 0; j < sizeof(rotor); j++){
            if(i == 0) {
                rot1[j] = rotor[j];
            } else if(i == 1) {
                rot2[j] = rotor[j];
            } else if(i == 2) {
                rot3[j] = rotor[j];
            } 
        }

    }
    char message[1025];
    fgets(message, 1025, stdin);
    
    if(operation[0] == 'E' && operation[1] == 'N') {
        fprintf(stderr, "encoding\n"); 
      
        if(true) {
            
        }
      
      
      
      
      
      
      
      
      
    } else if (operation[0] == 'D' && operation[1] == 'E') {
        fprintf(stderr, "decoding\n");
      
      
      
      
      
      
      
      
      
      
    }
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("message\n");

    return 0;

}