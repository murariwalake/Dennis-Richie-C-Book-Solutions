/*program to count the number of set bits in the given number */

#include<stdio.h>
int bitCount(unsigned x);

int main(){
  unsigned x;
  printf("Enter the number\n");
  scanf("%u", &x);

  printf("Number of set bits in %u are %d\n",x, bitCount(x));
  return 0;
}

int bitCount(unsigned x){
  int b;
  for(b = 0; x!=0; x>>=1)//each time x is right shifting by once
    if(x & 01)//checking whether rignt most nit is set or not
      ++b;
  return b;
}
