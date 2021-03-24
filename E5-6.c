#include<stdio.h>
#include<string.h>
#include<ctype.h>//isspace() and isdigit() are used
#define MAXVAL 100
#define NUMBER 0

int mygetline(char *, int);
int atoi(char *);
char *itoa(int n, char *);
char *reverse(char *s);
int strindex(char *, char *);//to find the index of right most pattern of t from s
int getop(char *);

int main(){
  char s[MAXVAL], t[MAXVAL], n, c ;
  int num;

  printf("Enther any charrecter or  unsigned number or operator\n");
  c = getop(s);
  if(c == NUMBER)
    printf("its numer\n");
  else
    printf("its charecter\n");

  printf("Enter a line\n");
  printf("Entered line has %d carrecters \n", mygetline(s, MAXVAL));

  printf("enter a string from above line to get its right most index\n");
  scanf("%s", t);
  if((n = strindex(s,t)) >= 0)
    printf("string fount at %d\n", n );
  else
    printf("string not fount\n");

  printf("Enter an iteger\n");
  scanf("%d", &num);
  printf("The integer converted charrecter array is \"%s\" \n", itoa(num, s) );
  printf("The charrecter array converted integer is %d \n", atoi(s) );

  return 0;
}

//to find the index of right most pattern of t from s
int strindex(char *s, char *t){
  int i,j,k;

  for(i = strlen(s) - strlen(t) - 1; i>=0; i--){
    for(j = i, k = 0; *(t+k) != '\0' && *(t+k) == *(s+j); k++, j++)
      ;

    if(*(t+k) == '\0' && k > 0)//if full pattern is matched and pattern string t[] should not be empty
    return i; //index of the patttern t[] in string s[]
  }

  return -1;//pattern is not matched
}

int mygetline(char *s, int lim){
  char *start = s;
  while(lim-- && ( (*s++ = getchar()) != EOF && *(s-1) != '\n' ))
    ;
  if(*(s-1) == EOF)
    *(s-1) = '\0';//dont include EOF in the sting
  else
    *s == '\0';// include '\n' in the sttring
  return s - start;
}

int atoi(char *s){
  int num, sign;
  while(isspace(*s++))//neglect all white spaces
    ;
  s--;//actual first charrecter
  sign = (*s == '-')? -1:1;

  if(*s == '-' || *s == '+')
    s++;//if first charrecter is sign the neglect it

  for(num = 0; isdigit(*s); s++){
    num = num * 10 + (*s - '0');
  }
  return num * sign;
}

char *itoa(int n, char *s){
  char *start = s;
  int i = 0, sign;

  if((sign = n) < 0)
    n = -n;         //if number is negative make it positive

  do{
    *s++ = n % 10 + '0';  //converts right most digit in to charecter
  }while(n /= 10);

  if(sign < 0)
    *s++ = '-'; //for negative number '-' sign will be added

  *s = '\0';
  return reverse(start);
}
/* revrsre the ctring s*/
char *reverse(char *s){
  char *p = s + strlen(s) - 1;
  char *start = s;
  for(; s < p; s++, p--){
    char temp = *s;
    *s = *p;
    *p = temp;
  }
  return start;
}

int getop(char *s){
  int i,c;
  while(( *s = c = getchar() ) == ' ' || c == '\t')
    ;//skip spaces and tabs
  *(s + 1) ='\0';
  if(!isdigit(c) && c != '.'){
  printf("%s\n",s);
    return c;        /* not a number */
}
  i = 0;
  if(isdigit(c))
    while (isdigit(*++s = c = getchar())) /* collect numeric part */
      ;
  if(c == '.')
    while (isdigit(*++s = c = getchar())) /* collect fractional part */
      ;

  *s = '\0';

  //if(c != EOF)
   //ungetch(c);

  return NUMBER;
}
