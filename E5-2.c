/*Write getfloat, the floating point of getint. What type does getfloat return as its function value?
  Ans:it can return integer as in getint.*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAXSIZE 5
#define BUFSIZE 100

int getfloat(float *);
char getch(void);
void ungetch(char);
char buffer[MAXSIZE];
int buf = 0;

int main(){
  int n, c;
  float  array[MAXSIZE];
  for(n = 0; n < MAXSIZE && (c = getfloat(&array[n])) != EOF; n++){
    printf("%f",array[n]);
    if(c > 0)
      printf("Its float\n");
    else if(c == 0)
      printf("Its not float\n");

  }
  if(c == EOF)
    printf("Its EOF \n");

  return 0;
}

int getfloat(float *ip){
  int c, sign, powr = 1, expsign, expo;
  while(isspace(c = getch()))
    ;//reject starting white spaces

  if(!isdigit(c) && c != EOF && c != '-' && c != '+'){
    ungetch(c);
    return 0;//not integer
  }

  sign = (c == '-')? -1: 1;//collect sign

  if(c == '-' || c == '+')
    c = getch();//if starting charrecter is + or - then collect next charrecter
  /*if sign followed by charracter is not integer then push it to buffer and report its not number */
  if(!isdigit(c)){
    ungetch(c);
    return 0;
  }
  for(*ip = 0; isdigit(c); c = getch())
    *ip = (*ip * 10) + c - '0';//convert entered charrecters into number in to number

/* collect fractional part*/
  if(c == '.'){
    c = getch();
    if(!isdigit(c)){
      ungetch(c);
      return 0;
    }
    for(powr = 1; isdigit(c); c = getch())
      *ip = (*ip * 10) + c - '0';
      powr *= 10;
  }

  /*collect exponential part */
  if(c == 'e' || c == 'E'){
    c =getch();
    expsign = (c == '-')? -1: 1;

    if(c == '-' || c == '+')
       c = getch();

    if(!isdigit(c)){
      ungetch(c);
      return 0;
    }
    for(expo = 0; isdigit(c); c = getch())
      expo = (expo * 10) + c - '0';
    expo *= expsign;
  }

  *ip = sign * (*ip / powr) * pow(10, expo); //complete number

  if(c != EOF)
    ungetch(c);// if c not endof file the push it to buffer

  return c;
}

char getch(void){
  return (buf > 0)? buffer[--buf]:getchar();
}

void ungetch(char c){
  if(buf >= BUFSIZE)
    printf("ERROR: Too many arguments\n");
  else
    buffer[buf++] = c;
}
