/*Program to convert String in to lower case */

#include<stdio.h>
void toLower(char str[]);
int main(){
  char str[100];

  printf("Enter the string with upper case leters\n");
  scanf("%s", str);
  toLower(str);
  printf("String in lower case is %s\n", str);
  return 0;
}

void toLower(char str[]){
  for(int i = 0; str[i] != '\0'; i++)
    str[i] = (str[i] >= 'A') && (str[i] <='Z') ? str[i]+('a'-'A'): str[i];
    //If any of the leter in the string conains upper case that will be converted into lower case
}
