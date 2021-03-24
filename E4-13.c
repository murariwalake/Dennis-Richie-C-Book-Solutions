#include<stdio.h>
#include<string.h>

void reverse(char[], int);

int main(){
  char s[100];
  printf("Enter the string to reverse\n");
  scanf("%s",s);
  reverse(s, strlen(s)-1);
  printf("Reversed string is %s\n", s);
  return 0;
}

void reverse(char s[], int high){
  static int low = 0;

  if(low < high){// swap the mirror charrecters
    char temp = s[low];
    s[low] = s[high];
    s[high] = temp;

    low++;  //stepup to next carrecter

    reverse(s,high-1); //hihg-1 indicates stepdown to its previos charrecter
  }
}
