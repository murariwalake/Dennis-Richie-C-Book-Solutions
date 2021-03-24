//Program to print a histogram of frequencieas of different charecters in the imput

#include<stdio.h>

int main()
{
	int  c,i,j,k, chars[96];

	for(i=0; i<96; i++)
		chars[i] = 0;

	while( ( c = getchar()) != EOF)
		++chars[c - ' '];

	for(i=0, j = ' '; i < 96;  i++)
	{
		printf("%c: ",j++);

		for(k = 0; k < chars[i]; k++)
		putchar('=');
		putchar('\n');
	}
}
