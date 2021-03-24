// printing 1-9 & 9-1 without using loops

#include<stdio.h>

int main()
{
	int number = 0;

	back1:

	printf("%d\n",number++);
	if(number < 10)
	goto back1;

	back:
	printf("%d\n",--number);
	if(number > 0)
	goto back;

}
