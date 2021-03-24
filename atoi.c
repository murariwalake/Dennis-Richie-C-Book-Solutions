/* Program to convert string intger. The same atoi function prototype is available in
 ctype.h header file.
*/

#include<stdio.h>
int atoi(char s[]);

int main(){
  char str[15];
  printf("enter the value to convert in to string\n");
  scanf("%s",str);
  printf("Integer value is %d\n", atoi(str));
}

int atoi(char s[]){
  int num, sign, i = 0 ;

    sign = (s[0] == '-')? -1:1;

  if(s[0] == '-' || s[0] == '+')
    i++;

  for(num = 0; s[i] >= '0' && s[i] <= '9' ; i++){
    num = num * 10 + (s[i] - '0');
  }

  return num * sign;
}
