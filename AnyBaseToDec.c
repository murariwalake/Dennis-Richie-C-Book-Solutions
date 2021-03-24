/*program to convert any value with given base to decimal
Note: To compile this code use "gcc HexToDec.c -ml;" otherwise pow() function will not work
then we have to write pow() function our own. */

#include<stdio.h>
#include<string.h>
#include<math.h>
//int power(int m, int n);
int baseToDec(char s[], int base);
int power(int, int);
int main(){
  char s[10];
  int base, dec;
  printf("Enter value and its base Note:for binary number first bit is considered as sign bit\n");
  scanf("%s %d", s, &base);
  dec = baseToDec(s,base);
  printf("decimal value is %d\n", dec);
  return 0;
}

int baseToDec(char s[], int base){
  int num = 0, j=0,  sign = 1, firstCharPos = 0;
 if(s[0] == '-' || (s[0] == '1' && base == 2)){
  sign = -1;// if the given value is negative then assign sign = -1
  firstCharPos = 1;// To skip 0th charrecter from s[]. because it represents sing and it will not be consider in bellow for loop.
 }

  for(int i = strlen(s)-1; i>=firstCharPos; i--,j++){
    if(s[i] >= '0' && s[i] <= '9')
      num = num + (s[i]-'0') * power(base,j);

    else if(s[i] >= 'A' && s[i] <= 'F')
      num = num + (s[i] - 'A' + 10) * power(base,j);

    else if(s[i] >= 'a' && s[i] <= 'f')
      num = num + (s[i] - 'a' + 10) * power(base,j);
  }
  return num*sign;
}

int power(int m, int n){
  int num = 1;
  for(int i = 0; i < n; i++)
    num *= m;
  return num;
}
