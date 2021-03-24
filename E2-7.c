/* Write a function invert(x,p,n) that returns x with n bits that begins at position p
inverted(e.i 1 changed to 0 and vice versa ), leaving the other bits unchanged*/

#include<stdio.h>
unsigned invert(unsigned x, int p, int n);

int main(){
  unsigned x;
  int p,n;

  printf("Enter the values of x,p,n\n");
  scanf("%u %d %d", &x, &p, &n);

  printf("result after inverting %u\n", invert(x,p,n));
 return 0;
}

unsigned invert(unsigned x, int p, int n){
  return x ^ ( ~(~0<<n)<<p-n+1 );
}
