#include <stdio.h>

int testStat(int initVal) {
	static int sm;
	int tmp = sm;
	sm = initVal;
	return tmp;
}

int testAuto(int initVal) {
	int sm;
	int tmp = sm;
	sm = initVal;
	return tmp;
}

int main() {

	puts("Test static");
	printf("%d\n", testStat(5));
	printf("%d\n", testStat(10));
	printf("%d\n", testStat(15));
	printf("%d\n", testStat(20));
	printf("%d\n", testStat(25));
	puts("");
	puts("Test auto");
	printf("%d\n", testAuto(5));
	printf("%d\n", testAuto(10));
	printf("%d\n", testAuto(15));
	printf("%d\n", testAuto(20));
	printf("%d\n", testAuto(25));
	return 0;
}
