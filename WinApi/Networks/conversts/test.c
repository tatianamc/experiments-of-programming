
#include <stdio.h>
#include <string.h>

struct Record {
    int a;
    double b;
} df;

int main() {
    
    struct Record r;
    r.a = 23;
    r.b = 123.1234;
    
    printf("%d\n", sizeof(r));
    
    printf("%d %lf \n", r.a, r.b);
    
    
    char buff[32];
    memcpy(buff, &r, sizeof(r));
    
    int i;
    for(i=0;i<sizeof(r); i++) {
        printf("%c ", buff[i]);
    }
    
    puts("converter");
    puts("=======");
    
    struct Record d;
    memcpy(&d, buff, sizeof(buff));
    printf("%d %lf \n", d.a, d.b);
    
    return 0;
}
