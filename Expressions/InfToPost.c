#include<stdio.h>
#include<string.h>
#define SIZE 50

void infToPost(char*, char*);
int F(char);
int G(char);

int main(){
  char inf[SIZE], post[SIZE], c;
  int i = 0;
  printf("Enter the Infix expression\n");
  while(( c = getchar()) != '\n')
    inf[i++] = c;
  inf[i] = '\0';

  infToPost(post, inf);
  printf("Postfix expression is %s\n", post);
  return 0;
}

void infToPost(char *post, char *inf){
  char s[SIZE], symbol;
  int top = -1;
  int i, j = 0;
  s[++top] = '#';

  for(i = 0; i < strlen(inf); i++){
    symbol = inf[i];
    while( F(s[top]) > G(symbol))
      post[j++] = s[top--];

    if(F(s[top]) != G(symbol))
      s[++top] = symbol;
    else
      top--;
    }

    while(s[top] != '#')
      post[j++] = s[top--];
    post[j] = '\0';
}
int F(char c){
  switch (c) {
    case '+':
    case '-': return 2; break;
    case '*':
    case '/': return 4; break;
    case '$': return 5; break;
    case '(': return 0; break;
    case '#': return -1; break;
    default: return 8; break;
  }
}

int G(char c){
  switch (c) {
    case '+':
    case '-': return 1; break;
    case '*':
    case '/': return 3; break;
    case '$': return 6; break;
    case '(': return 9; break;
    case ')': return 0; break;
    default: return 7; break;
  }
}
