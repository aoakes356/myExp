#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_LOG2E
#define M_LOG2E   1.44269504088896340735992468100189214
#endif

#ifndef M_LN2
#define M_LN2  0.693147180559945309417232121458176568
#endif
/* The results from rerror.c show that we must use a taylor series
 * of degree 7 in order to obtain an approximation with an error less than 
 * machine epsilon.
*/
double fracExp(float x){
    float coeffs[7] = {1, 1.0/2.0, 1.0/6.0, 1.0/24.0, 1.0/120.0, 1.0/720.0, 1.0/5040.0};
    // horner's algorithm for the seventh degree taylor series for e^x.
    return fmaf(x,fmaf(x,fmaf(x,fmaf(x,fmaf(x,fmaf(x,fmaf(x,coeffs[6],coeffs[5]),coeffs[4]),coeffs[3]),coeffs[2]),coeffs[1]),coeffs[0]),1);
}
float myexp(float x) {
    float z = x/M_LN2;
    float m = floor(z);
    float w = z-m;
    float u = w*M_LN2;
    float left = ldexpf(1,m);
    float frac = fracExp(u);
    return left*frac;
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <number>\n", argv[0]);
    exit(1);
  }
  const float x = atof(argv[1]);
  const float y = myexp(x);
  printf("%0.9e\n", y);

  return 0;
}
