/* Program to remove trailing tabs, blanks and new lines*/

#include<stdio.h>
#include<string.h>
#define MAX 100
int trim(char s[]);

int main(){
  int i = 0, c;
  char s[MAX];

  printf("Enter string\n");
  while( (c=getchar()) != -1) // EOF = -1    EOF value is -1
    s[i++] = c;

  s[i] = '\0';

  int n = trim(s);

  printf("String after trimming \"%s\" it contains %d chars\n",s,n);

  return 0;
}

int trim(char s[]){
  int i;
  for(i = strlen(s)-1; i >= 0; i-- )
    if(s[i] != ' ' && s[i] != '\t' && s[i] !='\n')
      break;//if charracter occurs other than blank, tab or newlines at the end, for loop will break
    s[i+1] = '\0';
    return i+1;//number of chars

}
