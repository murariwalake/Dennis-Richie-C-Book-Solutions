/* Program to find the position of right most appearing pattern t[] in s[] */

#include<stdio.h>
#include<string.h>
int getLine(char s[]);
int stringIndex(char s[], char t[]);
char t[] = "ould";

int main(void){
  char s[1000];
  int pos;
  printf("Entered The string\n");

  while(getLine(s) > 0){  //if line is not empty
    if((pos = stringIndex(s,t)) >= 0)//if pattern found
      printf("pattern found at position %d\n",pos);
    else
    printf("pattern not found\n");
  }
}

int getLine(char s[]){
  int c, i = 0;

  while((c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if(c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

int stringIndex(char s[], char t[]){
  int i,j,k;

  for(i = strlen(s) - strlen(t) - 1; i>=0; i--){
    for(j = i, k = 0; t[k] != '\0' && t[k] == s[j]; k++, j++)
      ;

    if(t[k] == '\0' && k > 0)//if full pattern is matched and pattern string t[] should not be empty
    return i; //index of the patttern t[] in string s[]
  }

  return -1;//pattern is not matched
}
