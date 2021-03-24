/*Write a function setbits(x,p,n,y) that returns x with n bits that begin at
 position p set to the right most n bits of y, leaving the other bits unchanged. */

#include<stdio.h>
unsigned setBits(unsigned x, int p, int n, unsigned y);

int main(){
  unsigned x,y;
  int p,n;

  printf("Enter the values of x, p, n, y one by one\n");
  scanf("%u %d %d %u", &x, &p, &n, &y);

  printf("result of setBits is %u \n",setBits(x,p,n,y));
  return 0;
}

unsigned setBits(unsigned x, int p, int n, unsigned y){
 return x & ~(~(~0 << n) << (p+1-n)) | (( y & ~(~0 << n )) << (p-n+1));
}
