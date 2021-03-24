/*Program to convert the given decimal number into specified base */

#include<stdio.h>
#include<string.h>
#define MAX 15
void reverse(char s[]);
void itob(int n, char s[], int b);

int main(){
  int n,b;
  char s[MAX];

  printf("Enter the decimal number\n");
  scanf("%d", &n);
  printf("Base?\n");
  scanf("%d", &b);

  itob(n,s,b);//converts to base b

  printf("Number after convertion to base %d is %s\n",b, s);
}

void itob(int n, char s[], int b){
  int i = 0, sign, digit;

  if((sign = n) < 0)
    n = -n;

  do{
    digit = n % b;
    if(digit <= 9)
      s[i++] = digit + '0';// adding right most digit to array if base is 2,8,10

    else if(digit >= 10 && digit <= 15)
      s[i++] = digit-10 + 'A';//adds A-F for hexadecimal convertion
    }while(n /= b);

  s[i++] = sign < 0 ? (b == 2 ? '1': '-'):(b == 2? '0':'\0');
  /*if its binary sign bits are 0(+) and 1(-). '\0' is because for positive numbers other than
  binary numbers its needed */

  s[i] = '\0';
  reverse(s);//reverses the string
}

void reverse(char s[]){
    int c;
    for(int i = 0, j = strlen(s) - 1; i<j; i++,j--){
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}
