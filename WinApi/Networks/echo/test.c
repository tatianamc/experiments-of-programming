
#include <stdio.h>
#include <string.h>

int main() {
    
    /*char buff[1024];
    scanf("%s", buff);
    
    printf("%s -> %d", buff, sizeof(buff));
    
    getchar();*/
    
    double array[] = {1.34,6.45,67.76,12.77};
    //int n = 4;
    
    
    char buff[8*4];
    
    //printf("%d", sizeof(array));
    
    memcpy(buff, array, sizeof(array));
    
    int i =0;
    for(i=0;i<32; i++) {
        printf("%c ", buff[i]);
    }
    
    double a2[4];
    memcpy(a2, buff, sizeof(array));
    puts("------");
    
    for(i=0;i<4; i++) {
       printf("%lf ", a2[i]);
    }
    
    //void *memcpy(void *dst, const void *src, size_t n);
    
    
    return 0;
}
