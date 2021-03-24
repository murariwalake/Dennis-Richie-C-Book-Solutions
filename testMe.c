#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char s[]){
  char c;
  for(int i = 0, j = strlen(s)-1; i < j; i++, j--){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }

}

void itoa(int n, char s[]){
  int i = 0, sign;

  if((sign = n) < 0)
    n = -n;         //if number is negative make it positive

  do{
    s[i++] = n % 10 + '0';  //converts right most digit in to charecter
  }while(n /= 10);

  if(sign < 0)
    s[i++] = '-'; //for negative number '-' sign will be added

  s[i] = '\0';
  reverse(s);
}




int nextPalindrome(int n){
	char a[15];
	itoa(n, a);
	int len = strlen(a); 
	int i=0, j = len-1;

	while(i<j)
		a[j--] = a[i++];
	 
	while(i>=0 && j<len && atoi(a) <= n){
		a[i] = ( (a[i] - '0' + 1)%10 ) + '0';
		a[j++] = a[i--];
	}

	if(atoi(a) > n)
		return atoi(a);
	else
		printf("have to process %s\n", a);
		return 0;
}

int main(){
	int n;
	printf("Enter a number\n");
	scanf("%d", &n);
	printf("%d", nextPalindrome(n));
	return 0; 
}
