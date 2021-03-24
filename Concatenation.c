#include<stdio.h>
void concat(char str1[], char str2[]);

int main(){
  char str1[100];
  char str2[100];

  printf("Enter string 1\n");
  scanf("%s",str1);
  printf("Enter the strin 2\n");
  scanf("%s",str2);
  concat(str1,str2);
  printf("String after concatenation of string1 and string2 %s\n",str1);
  return 0;
}

void concat(char str1[], char str2[]){
  int i,j=0;
  while(str1[i] = '\0')
    i++;

  while((str1[i++] = str2[j++]) != '\0');
}
