#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
    char path1[50];
    char path2[50];
    FILE *f1;
    FILE *f2;
    int mRows = 0; 
    int mCols = 0;
    int vRows = 0;

    printf("Enter a Matrix File path (File 1, type .csv): ");
    scanf("%s", path1);

    printf("Enter a Vector File path (File 2, type .csv): ");
    scanf("%s", path2);

    if ((f1 = fopen(path1, "r")) == NULL) { 
        printf("Cannot Open File 1.\n");
        return 1;
    }

    if ((f2 = fopen(path2, "r")) == NULL) {
        printf("Cannot Open File 2.\n");
        return 1;
    }


    float *matrix;
    int mPos;
    float *vector;
    int vPos = 0;

    ///////////////////////////////////////////////////// READ MATRIX FILE

    char line[125];
    int lineNum = 0;
    while(!feof(f1)){
        fgets(line, 125, f1);
        if(lineNum == 0) { // if it's the first line
            int i = 0;
            bool c = false;
            bool valid = true;
            char num[10];
            int numIt = 0;
            while(line[i] != 0) {
                if(line[i] > 46 && line[i] < 58) {
                    num[numIt] = line[i];
                    numIt++;
                } else if (line[i] == 44 || line[i] == 10) { // if it's a comma or endl
                    if(!c) { // it's the first comma
                        mRows = atoi(num);
                        printf("mRows is: %i\n", mRows);
                        for(int j = 0; j < 10; j++) {
                            num[j] = 0;
                        }
                        numIt = 0;
                        c = true;
                    } else if (c && line[i] == 10){ // it's second comma and end of line
                        mCols = atoi(num);
                        printf("mCols is: %i\n", mCols);
                        break;
                    } else {
                        valid = false;
                        printf("Error, matrix given more then 2 dimensions (Looking only a row and a colunm).\n");
                        return 1;
                    }
                } else {
                    valid = false;
                    printf("Error, invalid input on Line %i, char %i\n", lineNum, i);
                    return 1;
                }
                i++;
            }
            if (mRows > 0 && mCols > 0) {          // If valid, create the float matrix
                printf("Matrix is %i by %i\n", mRows, mCols);
                matrix = malloc((mRows * mCols) * sizeof(float)); 
            } else {
                printf("Error, could not create matrix.\n");
                printf("mRows = %i, mCol = %i\n", mRows, mCols);
                return 1;
            }
        } else {
            int i = 0;
            char num[10];
            bool valid = true;
            int numIt = 0;
            while(line[i] != 0) {
                if(line[i] > 45 && line[i] < 58 && line[i] != 47) { // if line is 0-9 or .
                    num[numIt] = line[i];
                    numIt++;
                } else if (line[i] == 44 || line[i] == 10) { // if it's a comma or an end of line
                    matrix[mPos] = strtof(num, NULL);
                    mPos++;
                    printf("num is: \"%s\"\n", num);
                    for(int j = 0; j < 10; j++) {
                        num[j] = 0;
                    }
                    numIt = 0;
                    if(line[i] == 10)
                        break;
                } else {
                    valid = false;
                    printf("Error, invalid input on Line %i, char %i\n", lineNum, i);
                    return 1;
                }
                i++;
            }
        }
        lineNum++;
    }

    ///////////////////////////////////////////////////// READ VECTOR FILE

    lineNum = 0;
    while(!feof(f2)){ // if (i = 0; i < n; i ++)
        fgets(line, 125, f2);
        if(lineNum == 0) { // if it's the first line
            int i = 0;
            bool c = false;
            bool valid = true;
            char num[10];
            int numIt = 0;
            while(line[i] != 0) {
                if(line[i] > 46 && line[i] < 58) { // if it's a 0-9
                    num[numIt] = line[i];
                    numIt++;
                } else if (line[i] == 10) { // if it's an endl
                    vRows = atoi(num);
                    printf("num is: \"%s\"\n", num);
                    break;
                } else {
                    if(line[i] == 44) {
                        printf("Error, invalid input on Line %i, vector has too many dimensions", lineNum, i);
                        return 1;
                    } if(line[i] == '.') {
                        printf("Error, invalid input on Line %i, this is an integer number for column count", lineNum, i);
                        return 1;
                    } else {
                        printf("Error, invalid input on Line %i, char %i\n", lineNum, i);
                        return 1;
                    }
                }
                i++;
            }
            if (vRows > 0) {          // If valid, create the float vector
                printf("Vector is %i by 1\n", vRows);
                vector = malloc(vRows * sizeof(float)); 
            } else {
                printf("Error, could not create vector.\n");
                printf("vRows = %i\n", vRows);
                return 1;
            }
        } else {
            int i = 0;
            int c = 0;
            char num[10];
            bool valid = true;
            int numIt = 0;
            while(line[i] != 0) {
                if(line[i] > 45 && line[i] < 58 && line[i] != 47) { // if line is 0-9 or .
                    num[numIt] = line[i];
                    numIt++;
                } else if (line[i] == 44 || line[i] == 10) { // if it's a comma
                    vector[vPos] = strtof(num, NULL);
                    vPos++;
                    printf("num is: \"%s\"\n", num);
                    for(int j = 0; j < 10; j++) {
                        num[j] = 0;
                    }
                    numIt = 0;
                    if(line[i] == 10)
                        break;
                } else {
                    valid = false;
                    printf("Error, invalid input on Line %i, char %i\n", lineNum, i);
                    return 1;
                }
                i++;
            }
        } 
        lineNum++;
    }

    // Print Matrix
    printf("\n\nPrinting the matrix: \n");
    for(int i = 0; i < mRows; i++) {
        for(int j = 0; j < mCols; j++) {
            printf("%f ", matrix[(mCols * i) + j]);
        }
        printf("\n\n");
    } 

    // Print Vector
    printf("\n\nPrinting the vector: \n", lineNum);
    for(int i = 0; i < vRows; i++) {
        printf("%f\n", vector[i]);
    } 
    printf("\n\n");


    /////////////////////////////////////////////////////// PERFORM MATH ON MATRIX

    int oRows = vRows;
    float *output = malloc(oRows * sizeof(float)); 

    if(mCols != vRows) {
        printf("Error, columns of matrix do not match rows of vector.");
        return 1;
    }
    
    for(int i = 0; i < vRows; i++){
        // perform math: 3.4*4.9 + 4.1*6.8 + 5.9*3.5
        float n = 0;
        for (int j = 0; j < mCols; j++) {
            n += (matrix[(mCols * i) + j] * vector[j]);
        }
        output[i] = n;
    }

    // Print Output
    printf("\n\nPrinting the output: \n", lineNum);
    for(int i = 0; i < oRows; i++) {
        printf("%f\n", output[i]);
    } 
    printf("\n\n");    

    //////////////////////////////////////////////////////////////////// WRITE OUTPUT FILE

    char outputFile[1000]; // '3','\n','6','5','.','2','\n','0','',''
    int outIt;
    sprintf(outputFile, "%i", oRows); // THis is a better version of itoa(); it sets a string to the integer value

    for(int i = 0; i < sizeof(outputFile); i++) {
        if(outputFile[i] == 0) {
           outIt = i; 
           break;
        }
    }
    outputFile[outIt] = '\n';
    outIt++;

    char floatHold[10];
    for(int i = 0; i < vRows; i++){
        int n;
        gcvt(output[i], 3, floatHold);   
        for(int j = 0; j < 10; j++){
            if(floatHold[j] == 0){
                n = j;
                break;
            }
        }
        for(int j = 0; j < 4; j++) {
            outputFile[outIt + j] = floatHold[j];
        }
        
        outputFile[outIt + n] = '\n';
        outIt += (n + 1);
    }
    outputFile[outIt] = 0;

    printf("outputFile: \n%s", outputFile);

    FILE *f3;
    if ((f3 = fopen("output.csv", "w")) == NULL) { 
        printf("Cannot Open File 3.\n");
        return 1;
    }

    fwrite(outputFile, sizeof(char), outIt, f3);

    free(matrix);
    free(vector);
    free(output);

    fclose(f1);
    fclose(f2);

    return 0; 
}

