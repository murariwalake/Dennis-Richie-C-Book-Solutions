#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

void push(char s[][SIZE], char*, int*);
char *pop(char s[][SIZE], int*);
char *numArray(char*, char*, int*);
void preToPost(char*, char*);
char *strrev(char*);

int main(){
  char pre[SIZE], post[SIZE], c;
  int i = 0;
  printf("Enter the Prefix expression\n");
  while(( c = getchar()) != '\n')
    pre[i++] = c;
  pre[i] = '\0';

  preToPost(post,pre);
  printf("postfix expression is %s\n", post);
  return 0;
}

void preToPost(char *post, char* pre){
  char s[SIZE][SIZE], symbol; //s[SIZE][SIZE]is to hold intermideate prefix expressions
  int top = -1;
  char temp[2]; //to convert charrector into array
  char *op1, *op2;

  for(int i = strlen(pre) - 1; i >= 0 ; i--){
    symbol = pre[i];
    temp[0] = symbol; //convert charrector into array
    temp[1] = '\0';
    if(isalpha(symbol))
        push(s, temp, &top);  //if its an alpabet single charrector then push it into s[][]

    else if(isdigit(symbol)){
      char num[SIZE];
      push(s, numArray(num, pre, &i), &top); //if digit occors then collect digit part;
      i++;/*because i was pointing to the previous non digit charrector if we leave it without decrementing
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
        op1 = pop(s, &top);
        op2 = pop(s, &top);
        strcpy(post, op1);
        strcat(post, op2);
        strcat(post, temp);
        push(s, post, &top); break;

        case ' ':break;

        default:printf("ERROR: Unkown charrector %c\n", symbol);
                  exit(0);
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

char *numArray(char* num, char* pre, int* i ){
  char *n = num;
  *num++ = ' ';//afte strev() this space gose to the end of the number
  do{
    *num++ =  pre[(*i)--];
  }while (isdigit(pre[*i]));

  *num = '\0';//terminate string
  //reverce the strig to get correct number
  return strrev(n);
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
  printf("%s",num );
  return num;

}
