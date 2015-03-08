#include <stdio.h>
#include <string.h>

// Максимальное количество строк
#define MAX_LINES 5000
// Указатели на строки
char *lineptr[MAX_LINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

// Сортировка строк из входного потока
int main(int argc, char *argv[]) {
	// Количество считанных строк
	int nlines;
	// 1, если числовая сортировка
	int numeric = 0;

	if(argc>1&& strcmp(argv[1], "-n") == 0)
		numeric = 1;


	if((nlines = readlines(lineptr, MAX_LINES)) >= 0) {
		qsort((void **) lineptr, 0, nlines-1,
			(int (*)(void*, void*))(numeric?numcmp:strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("Input too big to sort\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
	int i, last;

	void swap(void *v[], int i, int j);

	if(left >=right) return;

	swap(v,left, (left + right)/2);
	last = left;

	for(i = left +1; i<= right; i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if(v1<v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j )  {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Loop for demo
int readlines(char *lineptr[], int nlines) {
    char* lines[] = {
        "asdfsf",
        "fhcgfh",
        "bdsff",
        "dsf",
        "aaa",
        "fddf",
        "zzz",
        "dsf"
    };

    int cnt = 8;

    int i;
    for(i = 0; i < cnt; i++) {
        lineptr[i] = lines[i];
    }

    return cnt;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for(i = 0; i<nlines;i++) {
        printf("%s\n", lineptr[i]);
    }
}
