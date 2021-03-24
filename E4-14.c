/*define a macro swap(t,x,y) the interchanges to arguments of type t. (Block structure will help.)*/
#include<stdio.h>
#define swap(t,a,b) {t temp = a; a = b; b = temp;}

int main(){
  float a = 10, b = 20;
  swap(int,a,b);
  printf("%f %f\n",a,b);
  return 0;
}
