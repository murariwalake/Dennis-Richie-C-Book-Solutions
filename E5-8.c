#include<stdio.h>

static char daytab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                             {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int dayOfYear(int, int, int);
int monthDay(int, int, int*, int* );

int main(){
  int year, month, day, days;
  printf("Enter the date: <day month year>\n");
  scanf("%d %d %d", &day, &month, &year );
  printf("Number of days : %d\n",dayOfYear(day, month, year));

  printf("enter the year and days to determine the date\n");
  scanf("%d %d",&year, &days);

  if(monthDay(year, days, &month, &day))
    printf("Date is <day month year>: %d/ %d/ %d\n", day,  month, year);
  else
    printf("ERROR: Wrong input\n");

  return 0;
}

int dayOfYear(int day, int month, int year){
  char leaf = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; // this expression gives 1 if year is leaf year otherwise 0
  if(month < 1 || month > 12 || day < 1 || day > daytab[leaf][month] ) // error checkeng
    return -1;
  for(int i = 1; i < month; i++)
    day += daytab[leaf][i];   //calculate number of days

  return day;
}

int monthDay(int year, int days, int* pmonth, int* pday){
  int i;
  char leaf = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; // this expression gives 1 if year is leaf year otherwise 0
  if( days < 1 ||  ( days - leaf > 365) ) //error checking
    return 0;
  for(i = 1; days > daytab[leaf][i]; i++ )
    days -= daytab[leaf][i];//finding the day and the month

    *pmonth = i;
    *pday = days;
    return 1;
}
