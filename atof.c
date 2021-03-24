/*program to convert string to double value*/

#include<stdio.h>
#include<ctype.h>
double atof(char s[]);
int main(){
  char s[30];
  printf("Enter double value\n");
  scanf("%s",s);

  printf("double value is %f\n",atof(s));
  return 0;
}

double atof(char s[]){
  int i,sign;
  double value,power;
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
 return  sign * value / power;//shift the decimal point at it's correct position
}
