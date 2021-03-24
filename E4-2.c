/*Modifide program to convert string to double value which hndeles Examples like 1235.765e-4, 2653536.E+3, 773663.87e9*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>
//int powe(int x, int expo);
double atof(char s[]);

int main(){
  char s[30];
  printf("Enter double value\n");
  scanf("%s",s);

  printf("double value is %f\n",atof(s));
  return 0;
}

double atof(char s[]){
  int i,sign,sign1;
  double value,power, expo = 0.0;
  for(i=0; isspace(s[i]); i++)//skip white spaces
    ;
  sign = s[i] == '-'?-1:1;//sign check
  if(s[i] == '-' || s[i] == '+')
    i++;  //skip sign if is there

  for(value = 0.0; isdigit(s[i]); i++)
    value = value * 10.0 + (s[i]-'0');//calcute double value before decimal point
  if(s[i] == '.')
    i++;  //skip decimal point

  for(power = 1; isdigit(s[i]); i++){
    value = value * 10.0 + (s[i] - '0');//countinue with the calculation of double value
    power *= 10.0;  //pow(10, number of digits after decimal value)
  }

  if(s[i] == 'e' || s[i] == 'E'){
    i++;
    sign1 = s[i] == '-'?-1:1;//exponent sign.

    if(s[i] == '-' || s[i] == '+')
      i++;  //skip sign if is there
    }

    while(isdigit(s[i])){
      expo = expo * 10 + (s[i++] - '0');//convert exponent value to integer.
    }

    if(sign1 == -1)
      power = power * pow(10, expo);
    else
      power = power / pow(10, expo);

 return  sign * value / power;//shift the decimal point at it's correct position
}
/*
int powe(int x, int expo){
  int value = 1;

  for(int i = 1; i <= expo; i++)
    value *= x;

  return value;
}
*/
