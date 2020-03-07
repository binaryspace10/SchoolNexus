#include <stdio.h>
#include <stdlib.h>

void main() {
	printf("Hello World!\n");

	char a[] = "This is the first string!!";

	// Go through a string and return all of the matches of a character inside of it. 

	int count;
	char l = '!'; // This is the character we will search for
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] == l)
			count++;
	}

	printf("The character '%c' is used %i times in the string \"%s\".\n\n", l, count, a);

	// Go through a string and create an inverse of it.

	int n = 0;
	int nullAdd = 0;
	char b[sizeof(a)];
	for (int j = sizeof(a) - 1; j >= 0; j--) {
		if(a[j] != 0) {
			b[n] = a[j]; 
		} else {
			nullAdd++;
			continue;
		}

		n++;
		//printf("a[j] = %i, or %c\n", a[j], a[j]);
	}
	for (int i = 0; i < nullAdd; i++) {
		b[n] = 0;
		n++;
	}

	printf("The original string is \"%s\", and the inverted string is \"%s\".\n\n", a, b);

	// go through a string and convert the string to a float.

	char numStr[] = "147.59";

	float number = strtof(numStr, NULL); 
	printf("Number is %f\n\n", number);

	// go through a string and recursively delete the string

	char thanosSnap[] = "This will be removed.";

	for (int i = sizeof(thanosSnap) - 1; i >= 0; i--) {
		thanosSnap[i] = 0;
		printf("%s\n", thanosSnap);
	}
	printf("\nThe string is no more. It was set to NULL values (zeros) character by character.\n");
}
