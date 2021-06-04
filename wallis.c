#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int i,float k){
  float num,den,t;
  num=4*i*i;
  den=num-1;
  t=num/den;
  k=k*t;
  return k;
}

int main(void) {
  float pi,k=1;
  for (int i=0; i<5; i++) {
    k = wallis_pi(i,k);
    pi=2*k;
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    k = wallis_pi(i,k);
    pi=2*k;
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

