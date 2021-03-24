/*  Program to calculate the postfix expressions  */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 100 //size of postfix expression
#define NUMBER '0' //signal for number
#define MAXVAL 100 //size of stack
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

void push(double);
double pop(void);
int getop(char []);
void ungetch(int);
int getch(void);

double val[MAXVAL];
int sp = 0;

int main(){
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF){
    switch(type){
      case NUMBER: push( atof(s) );  break;
      case '+': push(pop() + pop()); break;
      case '*': push(pop() * pop());break;
      case '-': op2 = pop();
                push(pop() - op2); break;
      case '/': op2 = pop();
                if(op2 != 0)
                  push(pop() / op2);
                else
                  printf("ERROR: division by 0 is not possible\n");  break;

      case '\n':printf("\t%.8g\n",pop()); break;
      default : printf("ERROR: unknown comand %s\n",s);break;
    }
  }
  return 0;
}

int getop(char s[]){
  int i,c;
  while(( s[0] = c = getchar() ) == ' ' || c == '\t')
    ;

  s[1] ='\0';
  if(!isdigit(c) && c != '.')
    return c;        /* not a number */

  i = 0;
  if(isdigit(c))
    while (isdigit(s[++i] = c = getchar())) /* collect numeric part */
      ;
  if(c == '.')
    while (isdigit(s[++i] = c = getchar())) /* collect fractional part */
      ;

  s[i] = '\0';

  if(c != EOF)
   //ungetch(c);

  return NUMBER;
}

void push(double f){
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("ERROR: stack is full, the value %f cannot be pushed\n", f);
}

double pop(void){
  if(sp > 0)
    return val[--sp];

  else
    printf("ERROR: stack is empty, cannot be popped any element");
    return 0.0;
}
/*
int getch(void){
  return (buf > 0)? buf[--bufp] : getchar();
}

void ungetch(int c){
  if(bufp >= BUFSIZE)
    printf("ungetch: too many charracters\n");
  else
    buf[bufp++] = c;
}*/
