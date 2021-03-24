/*Write function expand(s1,s2) that expnds shathand notations like a-z in string s1 in to the equivalent
complete string abcd....xyz in s2. Allow for letters of either case and digits, and be prepared to
handel cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally */

#include<stdio.h>
void expand(char s1[], char s2[]);

int main(){
  char s1[100], s2[1000];
  printf("Enter the range\n");
  scanf("%s",s1);

  expand(s1,s2);

  printf("%s\n",s2);
  return 0;
}

void expand(char s1[], char s2[]){
  int i=0, j=0, c;

  while( (c=s1[i++]) != '\0' ){

    if(s1[i] == '-' && c <= s1[i+1]){//checks order and format. it do not allow examples like z-a
        i++;
      while(c < s1[i])//All the elements which comes after c and  before s1[i] will store in s2[]
        s2[j++] = c++;
    }

    else
     s2[j++] = c;//End charracter will be added. ex: in a-z, z will be added in this statement
  }
}
