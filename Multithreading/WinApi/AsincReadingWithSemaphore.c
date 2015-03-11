#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

HANDLE A, B, sema, semb;
int a=-1,b=-1,c=-1;
int AN = 0;
WINAPI DWORD one(lpvoid)
{
	FILE *f;
	f=fopen("data.txt","rb");
	char s[7];
	while(!feof(f))
	{
		WaitForSingleObject(sema,INFINITE);
		fgets(s,7,f);
		a=atoi(s);
		fgets(s,7,f);
		b=atoi(s);
		fgets(s,7,f);
		c=atoi(s);
		ReleaseSemaphore(semb,1,NULL);
	}
	fclose(f);
	AN=1;
	return 0;
}

WINAPI DWORD two(lpvoid)
{
	while(AN==0)
	{
		WaitForSingleObject(semb,INFINITE);
		printf("a=%d b=%d c=%d \n",a,b,c);
		Sleep(1000);
		ReleaseSemaphore(sema,1,NULL);
	}
	return 0;
}

int main()
{
	sema = CreateSemaphore(NULL,1,1,NULL);
	semb = CreateSemaphore(NULL,0,1,NULL);
	
	A = CreateThread(NULL,0,one,0,0,NULL);
	B = CreateThread(NULL,0,two,0,0,NULL);
	
	WaitForSingleObject(A,INFINITE);
	WaitForSingleObject(B,INFINITE);
	printf("End work !!\n");
	return 0;
}
