/*Program to check given year is leap year not*/

#include<stdio.h>

int main(){
  int year;
  printf("Enter the year to check leap year\n");
  scanf("%d",&year);

  if((year%4 == 0 && year%100 != 0) || year%400 == 0){
    printf("Entered year is leap year\n");
  }else{
    printf("Entered year is not leap year\n");
  }

  return 0;

}
