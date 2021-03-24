#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

void push(char s[][SIZE], char*, int*);
char *pop(char s[][SIZE], int*);
char *numArray(char*, char*, int*);
void postToPre(char*, char*);

int main(){
  char pre[SIZE], post[SIZE], c;
  int i = 0;
  printf("Enter the postfix expression\n");
  while(( c = getchar()) != '\n')
    post[i++] = c;
  post[i] = '\0';

  printf("%s\n",post );
  postToPre(pre, post);
  printf("Prefix expression is %s\n", pre);
  return 0;
}

void postToPre(char *pre, char* post){
  char s[SIZE][SIZE], symbol, *p[SIZE]; //s[SIZE][SIZE]is to hold intermideate prefix expressions
  int top = -1;
  char temp[2]; //to convert charrector into array
  char *op1, *op2;

  for(int i = 0; i < strlen(post); i++){
    symbol = post[i];
    temp[0] = symbol; //convert charrector into array
    temp[1] = '\0';
    if(isalpha(symbol))
        push(s, temp, &top);  //if its an alpabet single charrector then push it into s[][]

    else if(isdigit(symbol)){
      char num[SIZE];
      push(s, numArray(num, post, &i), &top); //if digit occors then collect digit part;
      i--;/*because i was pointing to the next non digit charrector if we leave it without decrementing
          it gose to increment part of for loop and it get increaments so the the charrecter immediate
           after the end of digits will be skippred for that i-- is needed*/
    }
    else{
      switch(symbol){
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '$':/* if any above symbol occors then pop two elements from s and perform prefix the push resulting prefix back*/
        op2 = pop(s, &top);
        op1 = pop(s, &top);
        strcpy(pre, temp);
        strcat(pre, op1);
        strcat(pre, op2);
        push(s, pre, &top); break;

        case ' ':break;

        default:printf("ERROR: Unkown charrector %c\n", symbol);
                  system("exit");
      }
    }
  }
  if(top){
    printf("ERROR: More operands than operators\n");
    exit(0);
  }
}

void push(char s[][SIZE], char *str, int* top){
  if(*top == 19){
    printf("ERROR: Too much large expression, stack overflow\n");
    exit(0);
  }
//  (*top)++;
  strcpy(s[++(*top)], str);
}

char *pop(char s[][SIZE], int *top){
 if(*top == -1){
   printf("ERROR: More operators than oparands\n" );
  exit(0);
 }
  return &s[(*top)--][0];
}

char *numArray(char* num, char* post, int* i ){
  char* n = num;
  do{
    *num++ =  post[(*i)++];
  }while (isdigit(post[*i]));

  *num = ' '; // pad space to last digit of the number to distinguish it with next number
  *(num + 1) = '\0';//terminate string
  return n;
}
