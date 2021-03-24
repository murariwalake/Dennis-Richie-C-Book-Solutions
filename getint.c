#include<stdio.h>
#include<ctype.h>
#define MAXSIZE 5
#define BUFSIZE 100

int getint(int *);
char getch(void);
void ungetch(char);
char buffer[MAXSIZE];
int buf = 0;

int main(){
  int n, array[MAXSIZE], c;
  for(n = 0; n < MAXSIZE && (c = getint(&array[n])) != EOF; n++){
    printf("%d",array[n]);
    if(c > 0)
      printf("Its integer\n");
    else if(c == 0)
      printf("Its not an integer\n");

  }
  if(c == EOF)
    printf("Its EOF \n");

  return 0;
}

int getint(int *ip){
  int c, sign;
  while(isspace(c = getch()))
    ;//reject starting white spaces

  if(!isdigit(c) && c != EOF && c != '-' && c != '+'){
    ungetch(c);
    return 0;//not integer
  }

  sign = (c == '-')? -1: 1;//collect sign

  if(c == '-' || c == '+')
    c = getch();//if starting charrecter is + or - then collect next charrecter

  for(*ip = 0; isdigit(c); c = getch())
    *ip = (*ip * 10) + c - '0';//convert entered charrecters into number in to number
  *ip *= sign;// assign sign

  if(c != EOF)
    ungetch(c);// if c not endof file the push it to buffer

  return c;
}

char getch(void){
  return (buf > 0)? buffer[--buf]:getchar();
}

void ungetch(char c){
  if(buf >= BUFSIZE)
    printf("ERROR: Too many arguments\n");
  else
    buffer[buf++] = c;
}
