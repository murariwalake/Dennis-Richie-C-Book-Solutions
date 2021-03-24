#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define SIZE 100
float s[SIZE];
int t = 0;

void push(float);
float pop(void);
//int isnum(char *aragv[]);

int main(int argc, char *argv[]){
  float op2;
  int i = 0;
  if(argc == 1){
    printf("Usage: comand line reverse polish expression calculation\n");
    return 0;
  }

  while(--argc){
     i++;
    if(*argv[i] == '+'){
      push(pop() + pop());
    }

    else if(*argv[i] == '-'){
      op2 = pop();
      push(pop() - op2);
    }

    else if(*argv[i] == '*'){
      push(pop() * pop());
    }

    else if(*argv[i] == '/'){
      if((op2 = pop()) != 0)
      push(pop() / op2);
      else{
        printf("ERROR: divide by zero\n");
        return 0;
      }

    }
    else if(*argv[i] == '%'){
      if((op2 = pop()) != 0)
      push(fmod(pop(), op2));
      else{
        printf("ERROR: divide by zero\n");
        return 0;
    }
   }

    /*else if(isnum(argv[i])){
      push(atof(argv[i]));
    }*/

    else if(isalpha(*argv[i])){
      printf("enter the value of %c\n", **argv);
      scanf("%f", &op2 );
      push(op2);
    }

    else{
      push(atof(argv[i]));
    //  printf("invalid expression\n");
    }

  }
  printf("%f\n", pop() );
  return 0;
}

void push(float val){
  if(t < SIZE)
    s[t++] = val;
  else
    printf("ERROR: stack is full, the value %f cannot be pushed\n", val);
}

float pop(void){
  if(t > 0)
    return s[--t];

  else
    printf("ERROR: stack is empty, cannot be popped any element");
    return 0.0;
}

/*int isnum(char *num){
  int i = 0;
  while(isdigit((*num + i)))
    i++;
  if(*(num + i) == '\0')
    return 1;
  return 0;

}*/
