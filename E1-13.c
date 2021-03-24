//programs to print the histogram of length of the words in its imput

#include<stdio.h>

int main()
{
	int c;
	while( (c = getchar()) != EOF)
	{
		if(c == '\n' || c == ' ' || c == '\t')
			putchar('\n');
		else
			putchar('-');
	}
}

