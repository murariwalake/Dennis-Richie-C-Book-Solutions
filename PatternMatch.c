/* program which prints the entered lines which containes pattern t[]*/

#include<stdio.h>
int getLine(char s[]);
int stringIndex(char s[], char t[]);
char t[] = "ould";

int main(void){
  char s[1000];
  printf("The entered string containing \"ould\" will be displayed\n");

  while(getLine(s) > 0){  //if line is not empty
    if(stringIndex(s,t) >= 0)//if pattern found
      printf("%s",s);
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

  for(i = 0; s[i] != '\0'; i++){
    for(j = i, k = 0; t[k] != '\0' && t[k] == s[j]; k++, j++)
      ;

    if(t[k] == '\0' && k > 0)//if full pattern is matched and pattern string t[] should not be empty
    return i; //index of the patttern t[] in string s[]
  }

  return -1;//pattern is not matched
}
