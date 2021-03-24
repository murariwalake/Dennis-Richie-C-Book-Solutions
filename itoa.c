/* Program to convert integer in to array*/

#include<stdio.h>
#include<string.h>
#define  MAX 12
void itoa(int n, char s[]);//converts integer in to string
void reverse(char s[]);//function to reverse string

int main(){
  int n;
  char s[MAX];
  printf("Enter the number\n");
  scanf("%d", &n);
  itoa(n,s);

  printf("The converted string is %s \n",s);
  return 0;
}

void itoa(int n, char s[]){
  int i = 0, sign;

  if((sign = n) < 0)
    n = -n;         //if number is negative make it positive

  do{
    s[i++] = n % 10 + '0';  //converts right most digit in to charecter
  }while(n /= 10);

  if(sign < 0)
    s[i++] = '-'; //for negative number '-' sign will be added

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]){
  char c;
  for(int i = 0, j = strlen(s)-1; i < j; i++, j--){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }

}
