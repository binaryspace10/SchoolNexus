#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void convertToCaesar(char *arrayIn, char *arrayOut, int size, int startingShiftNumber);

int main()
{
    char operation[257];
    fgets(operation, 257, stdin);
    
    int pseudo_random_number;
    scanf("%d", &pseudo_random_number); fgetc(stdin);
    
    char rotor1[27];
    char rotor2[27];
    char rotor3[27];

    for (int i = 0; i < 3; i++) {
        if(i == 0) {
            fgets(rotor1, 27, stdin); fgetc(stdin);
        } else if (i == 1) {
            fgets(rotor2, 27, stdin); fgetc(stdin);
        } else if (i == 2) {
            fgets(rotor3, 27, stdin); fgetc(stdin);
        }
    }
    char message[1025];
    fgets(message, 1025, stdin);
    
    int size = 0;
    for(int i = 0; i < sizeof(message); i++) {
        if(message[i] > 64 && message) {
            size++;
        } else {
            break;
        }
    }
    
    char cmessage[1025];
    if(operation[0] == 'E' && operation[1] == 'N') {
        fprintf(stderr, "encoding\n"); 
        
        fprintf(stderr, "message = \"%s\"\n", message);
        fprintf(stderr, "int offset = %d\n", pseudo_random_number);
        
        
        convertToCaesar(message, cmessage, size, pseudo_random_number);
        
        fprintf(stderr, "cmessage = \"%s\"\n", cmessage);
        
        
        // ROTOR 1 TRANSFORMATION
        for (int i = 0; i < size; i++) {
            int val = cmessage[i] - 65;
            cmessage[i] = rotor1[val];
        }
        fprintf(stderr, "cmessage = \"%s\"\n", cmessage);

        // ROTOR 2 TRANSFORMATION
        for (int i = 0; i < size; i++) {
            int val = cmessage[i] - 65;
            cmessage[i] = rotor2[val];
        }
        fprintf(stderr, "cmessage = \"%s\"\n", cmessage);

        // ROTOR 3 TRANSFORMATION
        for (int i = 0; i < size; i++) {
            int val = cmessage[i] - 65;
            cmessage[i] = rotor3[val];
        }
        fprintf(stderr, "cmessage = \"%s\"\n", cmessage);
        
        

    } else if (operation[0] == 'D' && operation[1] == 'E') {
        fprintf(stderr, "decoding\n");
        
        // ROTOR 3 TRANSFORMATION
        for (int i = 0; i < size; i++) {
            int pos = -1;
            for (int j = 0; j < 26; j++) {
                if(rotor3[j] == message[i])
                pos = j;
            }
            message[i] = 65 + pos;
        }
        fprintf(stderr, "message = \"%s\"\n", message);

        // ROTOR 2 TRANSFORMATION
        for (int i = 0; i < size; i++) {
            int pos = -1;
            for (int j = 0; j < 26; j++) {
                if(rotor2[j] == message[i])
                pos = j;
            }
            message[i] = 65 + pos;
        }
        fprintf(stderr, "message = \"%s\"\n", message);

        // ROTOR 1 TRANSFORMATION
        for (int i = 0; i < size; i++) {
            int pos = -1;
            for (int j = 0; j < 26; j++) {
                if(rotor1[j] == message[i])
                    pos = j;
            }
            message[i] = 65 + pos;
        }
        fprintf(stderr, "message = \"%s\"\n", message);
        
        convertFromCaesar(message, cmessage, size, pseudo_random_number);
    }
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%s\n", cmessage);

    return 0;
}


/*  ASCII & Assignment Info
 *  
 *  We will never be asked to convert anything other than capital "A" through "Z"
 *  
 *  The ASCII value for "A" is 65
 *  The ASCII value for "Z" is 90
 *  
**/

void convertToCaesar(char arrayIn[], char arrayOut[], int sizeOfArrays, int startingShiftNumber) {
    int n = startingShiftNumber;
    for (int i = 0; i < sizeOfArrays; i++) {
        if(arrayIn[i] == 0) { // Prevent Over reading the array
            break;
        }
        
        if(n > 26)
            n = 1;

        char newVal = arrayIn[i] + n; // if n = 24 & arrayOut[i] = I, then it would equal 73. these added would equal 97. Making the new letter (97-90) + 64 = 71, or G.
        if (newVal > 90) {
            int j = newVal - 90; // possibilities are 91 through 116
            newVal = 64 + j;
        } 

        arrayOut[i] = newVal;
        n++;
    }
}

void convertFromCaesar(char arrayIn[], char arrayOut[], int sizeOfArrays, int startingShiftNumber) {
    int pos = 0;
    int n = startingShiftNumber;
    for (int i = 0; i < sizeOfArrays; i++) {
        if(arrayIn[i] == 0) { // Prevent Over reading the array
            break;
        }
        
        if(n > 26)
            n = 1;

        char newVal = arrayIn[i] - n; // if n = 24 & arrayOut[i] = I, then it would equal 73. these added would equal 97. Making the new letter (97-90) + 64 = 71, or G.
        if (newVal < 65) {
            newVal += 26;
        } 

        arrayOut[i] = newVal;
        n++;
        pos++;
    }
    arrayOut[pos] = 0;
}







