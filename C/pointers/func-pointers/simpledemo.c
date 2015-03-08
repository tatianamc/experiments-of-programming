#include <stdio.h>
#include <math.h>

double valueOfFunctionInSqrt( double (* func)(double) ) {
    return (* func)(3.1) * (*func)(3.1);
}

int main() {

    printf("%f\n", valueOfFunctionInSqrt(sin));
    printf("%f\n", valueOfFunctionInSqrt(cos));
    printf("%f\n", valueOfFunctionInSqrt(exp));

    return 0;
}
