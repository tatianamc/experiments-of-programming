#include <stdio.h>

char *month_name(int num) {
	// память static выделяется в сегменте данных
	// а не в стеке, поэтому не очищается при выходе из блока
	// но остается видимой внутри блока
	static char *name[] = {
		"Illegal month",
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	
	return (num<1||num>12)?name[0]:name[num];
}

int main() {
	
	int i = 0;
	for(i = 0; i<15; i++) {
		printf("n=%d : %s\n", i, month_name(i));
	}
	return 0;
}
