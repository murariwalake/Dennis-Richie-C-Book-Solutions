/* getBits() return the value of n bits right from the position p in the number x */

#include<stdio.h>
unsigned getBits(unsigned x, int p, int n);

int main(){
  unsigned x;
  int p, n;

  printf("Enter the values of x,p,n\n");
  scanf("%u%d%d",&x, &p, &n);

  printf("Result after Get Bits %u\n", getBits(x,p,n));
}

unsigned getBits(unsigned x, int p, int n){
  return x >> p-n+1 & ~(~0 << n); value from position p to position n where p >=n
}
