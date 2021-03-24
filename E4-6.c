#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 100 //size of postfix expression
#define MAXDIGITS 10 //max number of digits per number
#define MAXVAL 100 //size of stack

void push(double);
double pop(void);
double val[MAXVAL];
int sp = 0;

int main(){
  int c,i = 0;
  double op2;
  char expr[MAXOP];
  char s[MAXDIGITS];

  printf("Enter the postfix expression\n");
  while((c = getchar()) != '\n' )
    expr[i++] = c;

  expr[i] = '\0';
  i = -1;

  while(expr[++i] != '\0'){
    switch(expr[i]){
      case '+': push(pop() + pop()); break;
      case '*': push(pop() * pop());break;
      case '-': op2 = pop();
                push(pop() - op2); break;
      case '/': op2 = pop();
                if(op2 != 0)
                  push(pop() / op2);
                else
                  printf("ERROR: division by 0 is not possible\n");  break;
      case ' ':
      case '\t': break;
      default : if( isdigit(expr[i]) ){
        int j = 0;

        while(isdigit(expr[i]) )
          s[j++] = expr[i++];
          s[j] = '\0';
        push( atof(s));
      }
      else if( isalpha(expr[i]) ){
        printf("Enter the value of %c\n",expr[i]);
        float value;
        scanf("%f", &value);
        push(value);
      }
      else
      printf("ERROR: Unknown comand %c\n",expr[i]);break;
    }
  }
  printf("Answer: %f\n", pop());
  return 0;
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
    printf("ERROR: Stack is empty, cannot be popped any element");
    return 0.0;
}
