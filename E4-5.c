/* Add access to library functions like sin, exp, and pow. See <math.h> in apendix B, section 4. */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAXOP 100 //size of postfix expression
#define NUMBER '0' //signal for number
#define MAXVAL 100 //size of stack

void push(double);
double pop(void);
int getop(char []);
int strProcess(char []);

double val[MAXVAL];
int sp = 0;

int main(){
  int type;
  double op2;
  char s[MAXOP];
  printf("Enter postfix expresiion\n");
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
      case '%': op2 = pop();
                if(op2 != 0)
                push(fmod(pop(), op2));
                else
                printf("ERROR: mod is not possible lfet operand is zero\n");break;
      case 's':push( sin( atof(s) ) );  break;
      case 'c':push( cos( atof(s) ) );  break;
      case 't':push( tan( atof(s) ) );  break;
      case 'e':push( exp( atof(s) ) );  break;
      case 'p':
      case '\n':printf("\t%.8g\n",pop());
                printf("Enter postfix expresiion\n"); break;
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
  if(!isdigit(c) && c != '.' && !isalpha(c) && c !=',') /*in case of strings like sin, exp we need to collect alpabhets */
    return c;        /* not a number */

  i = 0;
  if(isdigit(c) || isalpha(c))
    while (isdigit(s[++i] = c = getchar()) || isalpha(c) || c == '(' || c == ')' ) /* collect numeric part */
      ;
  if(c == '.')
    while (isdigit(s[++i] = c = getchar()) || c == ')') /* collect fractional part */
      ;

  s[i] = '\0';
  return strProcess(s);
}

int strProcess(char s[]){
  char pref[5];
  int j = 0;
  int k = 0;
  for(int i = 0; s[i] != '\0'; i++){
    if(isalpha(s[i]))
      pref[k++] = s[i]; //collect math function
    else if(isdigit(s[i]) || s[i] == '.')
      s[j++] = s[i]; // collect value
  }
  pref[k] = '\0';
  s[j] = '\0';

  if( strcmp(pref,"sin") == 0)
    return 's';

  else if( strcmp(pref, "cos") == 0)
    return 'c';

  else if( strcmp(pref, "tan") == 0)
    return 't';
  else if(strcmp(pref, "exp") == 0)
    return 'e';
  else
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
