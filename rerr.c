#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef M_LN2
#define M_LN2  0.693147180559945309417232121458176568
#endif

int fact(int n) {
    if (n <= 1) return 1;
    return n*fact(n-1);
}

int main() {
    double err;
    for(int i = 1; i < 16; i++){
        err = (2.0/(fact(i+1)))*(pow(M_LN2/2.0,i+1));
        printf(" rel. error(%i) = %.7e \n",i,err);
    }
    
    return 0;
}
