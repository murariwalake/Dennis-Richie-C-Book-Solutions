/*Write pointer vertion of function strcat() that we showed in chapter 2: strcat(s, t) copies the string t to the end of s  */
#include<stdio.h>

char * strcat(char *, char *);

int main(){
  char s1[100], s2[100];
  printf("Enter two strings\n");
  scanf("%s %s",s1, s2);
  printf("String after concatination: %s\n", strcat(s1, s2));
  /*function strcat() returns pointer to charrecter which points to thefirst charrecter of s1; */
  return 0;
}

char * strcat(char *s, char *t){
  char *p = s;
  while(*s++)  //At the end of string *s value becomes NULL loop terminates
    ;
  s--; //s starts to points at the end of charrecter that is '\0'
  while(*s++ = *t++)  //copy char from t to s untill last charrecter including '\0'
    ;
  return p;//p pinting to first charrecter of s
}
