/* Adapt the ideas of printd to write a recursive version of itoa(), that is, convert an integer into a string by
calling arecursive routin. */

#include<stdio.h>

void itoa(int, char[]);

int main(){
  int n;
  char s[10];
  printf("Enter the number\n");
  scanf("%d", &n);
  itoa(n,s);
  printf("Integer converted array is: %s\n",s);
  return 0;
}

void itoa(int n, char s[]){

  static int i;

  if(n < 0){
    s[i++] = '-';
    n = n * (-1);
  }

  if(n/10){
    itoa(n/10, s);
  }
  s[i++] = (n % 10) + '0';
  s[i] = '\0';
}
