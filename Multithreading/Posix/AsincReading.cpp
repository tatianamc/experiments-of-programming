#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <sys/time.h>


FILE *fl;
pthread_t pThread_a,pThread_b;
float a,b,c;
float a1,b1,c1;
char s[6];
int AA;
pthread_mutex_t mutex_a=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_b=PTHREAD_MUTEX_INITIALIZER;
clock_t StartTime,EndTime;

//int idA,idB,idC,idD,idSOF,idVF;

void * Thread_a(void *param)
{
	printf("a");
	fl=fopen("data.txt","rb");
	int i=0;
	
	while(!feof) {
		pthread_mutex_lock(&mutex_a);
		fgets(s,5,fl);
		a=atof(s);
		fgets(s,5,fl);
		b=atof(s);
		fgets(s,5,fl);
		c=atof(s);
		pthread_mutex_unlock(&mutex_b);			
	}
			
	AA=1;
}


void * Thread_b(void *param) {
	printf("b");
    while(AA!=1) {
		pthread_mutex_lock(&mutex_b);
		a1=a;
		b1=b;
		c1=c;
		pthread_mutex_unlock(&mutex_a);
		float D,x1,x2;
		D=b1*b1-4*a1*c1;
		x1=(-b1+sqrt(D))/2*a1;
		x2=(-b1-sqrt(D))/2*a1;
		printf(" x1= %.2f   x2=%.2f\n",x1,x2);
     }
}

int main(int arg, char *argk[])
{	
	StartTime=clock();
	pthread_mutex_init(&mutex_a,NULL);
	
	pthread_mutex_init(&mutex_b,NULL);
	pthread_mutex_unlock(&mutex_b);
	//pthread_mutex_unlock(&mutex_a);
	//printf("bbbb");
	pthread_create(&pThread_a, NULL, Thread_a,NULL);
	pthread_create(&pThread_b, NULL, Thread_b,NULL);
	pthread_join(pThread_a,NULL);
	pthread_join(pThread_b,NULL);
	
	EndTime=clock();
	float xxxxx=(EndTime-StartTime);
	printf("DONE: time %f ",xxxxx);

}
