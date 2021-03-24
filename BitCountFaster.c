#include<stdio.h>
int bitCountFaster(unsigned x);
int main(){
  unsigned x;
  printf("Enter the a number\n");
  scanf("%d",&x);

  printf("Number of set bits in %u are %d\n", x, bitCountFaster(x));

  return 0;
}

int bitCountFaster(unsigned x){
  int b;
  for(b = 0; x != 0; x &= (x-1), ++b);
  return b;
}
