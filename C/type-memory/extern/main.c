#include <stdio.h>


/**
 * extern позволяет использовать глобальные переменные которые 
 * объявлены ниже по коду 
 */
int testExtern() {
	extern long var;
	return var;
}

int main() {

	puts("Test extern");
	printf("%d\n", testExtern());
	return 0;
}
#include "file.c"
