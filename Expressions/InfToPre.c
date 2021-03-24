#include<stdio.h>
#include<string.h>
#define SIZE 50

void infToPre(char*, char*);
int F(char);
int G(char);
char *strrev(char*);

int main(){
  char inf[SIZE], pre[SIZE], c;
  int i = 0;
  printf("Enter the Infix expression\n");
  while(( c = getchar()) != '\n')
    inf[i++] = c;
  inf[i] = '\0';

  infToPre(pre, inf);
  printf("prefix expression is %s\n", pre);
  return 0;
}

void infToPre(char *pre, char *inf){
  char s[SIZE], symbol;
  int top = -1;
  int i, j = 0;
  s[++top] = '#';

  strrev(inf);

  for(i = 0; i < strlen(inf); i++){
    symbol = inf[i];
    while( F(s[top]) > G(symbol))
      pre[j++] = s[top--];

    if(F(s[top]) != G(symbol))
      s[++top] = symbol;
    else
      top--;
    }

    while(s[top] != '#')
      pre[j++] = s[top--];
    strrev(inf);
    pre[j] = '\0';
}
int F(char c){
  switch (c) {
    case '+':
    case '-': return 1; break;
    case '*':
    case '/': return 3; break;
    case '$': return 6; break;
    case ')': return 0; break;
    case '#': return -1; break;
    default: return 8; break;
  }
}

int G(char c){
  switch (c) {
    case '+':
    case '-': return 2; break;
    case '*':
    case '/': return 4; break;
    case '$': return 5; break;
    case '(': return 0; break;
    case ')': return 9; break;
    default: return 7; break;
  }
}

char *strrev(char *num){
  char *end, *start, temp;
  start = num;
  end = num + strlen(num) -1 ;
  while(start < end){
    temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
  return num;
}
