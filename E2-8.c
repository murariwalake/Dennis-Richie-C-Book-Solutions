/*
Write a function writRot(x,n) that returns the value of
the intger x rotated to the right by n bits
*/


#include<stdio.h>
unsigned rightRot(unsigned x, int n);
int wordLength();

int main(){
  unsigned x;
  int n;

  printf("Enter the values ofx, n\n");
  scanf("%u %d", &x, &n);

  printf("result after n times right rotating %u\n", rightRot(x,n));
  return 0;
}

unsigned rightRot(unsigned x, int n){
  unsigned y = x;
  x = x << (wordLength() - n);
  y = y >> n;
  return x | y;
}

int wordLength(){
  unsigned v = ~0;
  int i;
  for(i = 1; (v >>= 1)>0; i++);
  return i;
}
