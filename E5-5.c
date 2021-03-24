/*Write versions of library fuctions strncat strncmp and strncpy which operates at most n charecters of strings. for esample
strncpy(s,t,n) copies n carrectars of t to s. Full discription is in appendix B   */

#include<stdio.h>

int mystrncmp(char *, char *, int );
char *mystrncpy(char *, char *, int);
char *mystrncat(char *, char *, int);

int main(){
  char s1[100], s2[100];
  int n;

  printf("Enter two strings\n");
  scanf("%s %s", s1, s2);
  printf("Enter value of n\n");
  scanf("%d", &n);

  printf("strncmp: of s1 and s2  %d\n",mystrncmp(s1,s2,n));//first at most n charrecters of s2 are compaired with s1
  printf("strncat: first %d charrecters of s2 are concatenated with  s1 result is: %s\n", n, mystrncat(s1,s2,n));
  printf("strncpy: first %d charrecters of s2 are copied to string s1 result is: %s\n",n, mystrncpy(s1,s2,n));
  return 0;
}
/*first at most n charrecters of t will compare with s */
int mystrncmp(char *s, char *t, int n){
  for(; n && *s == *t; s++, t++, n--)
    if(*s == '\0' || n == 1)
    /*if s has lesser than n elements(*s == '\0') or all n elements(n == 1) are compared then it indicates
    firts at most n charrecters of t and s are same */
    return 0;
  return *s - *t;//else finally return charrecter diference
}

char *mystrncat(char *s, char *t, int n){
  char *p = s;
  /*move at the end of string  */
  while(*s++)
    ;
  s--;
  /*if all n charrs of t are copied or t has less elements than n then loop terminates */
  while(n-- && (*s++ = *t++))
    ;
  *s = '\0';//pad NULL at the end
  return p;
}

char *mystrncpy(char *s, char *t, int n){
  char *p = s;
  /*if all n(n--) charrs of t are copied or t has less elements(*s++ = *t++) than n then loop terminates
  if t has lesser elements than n value thattime (*s++ = *t++) results null, so loop terminates  */
  while(n-- && (*s++ = *t++))
    ;
  *s = '\0';//pad NULL at the end
  return p;
}
