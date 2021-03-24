/*Write the function strend(s, t) which returns 1 if the string t occurs at the end of string s and zero otherwise   */
#include<stdio.h>

int strend(char *, char *);
int mystrlen(char *);

int main(){
  char s1[100], s2[100];
  printf("Enter two strings\n");
  scanf("%s %s",s1, s2);
  if(strend(s1, s2))
    printf("String \"%s\" contains \"%s\" at the end\n", s1, s2);
  else
    printf("String \"%s\" does not contains \"%s\" at the end\n", s1, s2);
  return 0;
}

int strend(char *s, char *t){
   s = s + mystrlen(s) - mystrlen(t); //
   for(; *s == *t; s++, t++)
    if(*s == '\0') // if all charrecters compared then return 1
      return 1;

   return 0;

}

int mystrlen(char *s){
  char *p = s;
  while(*s++) //at the end of the string value of *s becomes zero
    ;
    s--;//s pointing to end of the string that is '\0'
  return s - p;
}
