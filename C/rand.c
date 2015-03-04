#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
	int i;
	srand(time(NULL));
	for (i=0; i<20; i++)
		printf("i: %d rand(): %d\n", i, rand());
	return 0;
}
