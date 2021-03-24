/* Add commands to print the top element of the stack without popping to duplicate it, and to swap the top two elements.
add command to clear the styack*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAXOP 100 //size of postfix expression
#define NUMBER '0' //signal for number
#define MAXVAL 100 //size of stack

void calculateExpression(void);
double topElement(void);
void duplicate(void);
void swapTopTwo(void);
void clearStack(void);
void push(double);
double pop(void);
int getop(char []);

double s[MAXOP];
double val[MAXVAL];
int sp = 0;

int main(){
  int ch;
  while(1){
    printf("1.Calculate postfix expression\n2.Print top\n3.Duplicate top\n4.Swap top two\n5.Clear Stack\n6.Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:calculateExpression(); break;
      case 2:printf("%f\n",topElement()); break;
      case 3:duplicate(); break;
      case 4:swapTopTwo(); break;
      case 5:clearStack(); break;
      default :exit(0);break;
    }
  }
  return 0;
}

void calculateExpression(void){
  int type;
  double op2;
  char s[MAXOP];

  printf("Enter postfix expression Note: Enter \"ctr + d\" to end expression\n");
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

      case '\n':   break;
      default : printf("ERROR: unknown comand %s\n",s);break;
    }
  }
  printf("expression is calculated succesfully and answer is pushed in to stack\n");
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
    printf("ERROR: stack is empty, cannot be popped any element\n");
    return 0.0;
}

double topElement(void){
  if(sp > 0){
     return val[sp-1];
  }
  else
  printf("stack is empty\n");return 0.0;
}

void duplicate(void){
  if(sp < MAXVAL && sp > 0){
    double op2 = pop();
    push(op2);
    push(op2);
    printf("the element %f is dupliacted\n", op2);
  }
  else if(sp == 0){
    printf("ERROR: Stack is empty cannot be duplicated\n");
  }
  else if(sp >= MAXVAL){
    printf("ERROR: Stack is full cannot be duplicated\n");
  }
}

void swapTopTwo(void){
  if(sp > 1){
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
    printf("swap success\n");
  }
  else{
    printf("ERROR: cannot be swapped, either stack has single element or it may be empty\n");
  }
}

void clearStack(void){
  sp = 0;
  printf("Stack is cleared\n");
}
