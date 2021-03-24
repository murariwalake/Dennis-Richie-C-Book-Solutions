/* Program to convert integer in to array, previous itoa() function do not handel largest -ve number
 that is -2147483648. but this program handels that number.
 becouase in previous program we were converting negative number in to positive but for largest negative
 number we cannot convert it in to positive.
 */

#include<stdio.h>
#include<string.h>
#define  MAX 12
#define  abs(x) x > 0?x :-x
void itoa(int n, char s[]);//converts integer in to string
void reverse(char s[]);//function to reverse string

int main(){
  int n;
  char s[MAX];
  //printf("%d\n", (~(unsigned)0>>1)+1);
  printf("Enter the number\n");
  scanf("%d", &n);
  itoa(n,s);

  printf("The converted string is %s \n",s);
  return 0;
}

void itoa(int n, char s[]){
  int i = 0, sign = 1;

  if(n < 0)
    sign = -1;         //if number is negative make it positive

  do{
    s[i++] = abs(n % 10) + '0';  //converts right most digit in to charecter
  }while(n /= 10);

  if(sign == -1)
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
