#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void push(char s[][20], char*, int*);
char *pop(char s[][20], int*);
char *numArray(char*, char*, int*);
void postToInf(char*, char*);

int main(){
  char inf[20], post[20], c;
  int i = 0;
  printf("Enter the postfix exinfssion\n");
  while(( c = getchar()) != '\n')
    post[i++] = c;
  post[i] = '\0';

  printf("%s\n",post );
  postToInf(inf, post);
  printf("infix exinfssion is %s\n", inf);
  return 0;
}

void postToInf(char *inf, char* post){
  char s[20][20], symbol, *p[20]; //s[20][20]is to hold intermideate inffix exinfssions
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
      char num[20];
      push(s, numArray(num, post, &i), &top); //if digit occors then collect digit part;
      i--;/*because i was pointing to the next non digit charrector if we leave it without decrementing
          it gose to increment part of for loop and it get increaments so the the charrecter immediate
           after the end of digits will be skipinfd for that i-- is needed*/
    }
    else{
      switch(symbol){
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '$':/* if any above symbol occors then pop two elements from s and perform inffix the push resulting inffix back*/
        op2 = pop(s, &top);
        op1 = pop(s, &top);
        strcpy(inf, "(");
        strcat(inf, op1);
        strcat(inf, temp);
        strcat(inf, op2);
        strcat(inf, ")");
        push(s, inf, &top); break;

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

void push(char s[][20], char *str, int* top){
  if(*top == 19){
    printf("ERROR: Too much large exinfssion, stack overflow\n");
    exit(0);
  }
//  (*top)++;
  strcpy(s[++(*top)], str);
}

char *pop(char s[][20], int *top){
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
