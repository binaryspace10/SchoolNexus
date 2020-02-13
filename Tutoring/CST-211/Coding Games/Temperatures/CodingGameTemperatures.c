#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int cltmp;
    
    // the number of temperatures to analyse
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // a temperature expressed as an integer ranging from -273 to 5526
        int t;
        scanf("%d", &t);
        
        if(i == 0){
            cltmp = t;
        } else {
            if(abs(t) < abs(cltmp)) {
                cltmp = t;
            } else if(abs(t) == abs(cltmp)) {
                cltmp = abs(t);
            }
        }
        
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%i\n", cltmp);

    return 0;
}