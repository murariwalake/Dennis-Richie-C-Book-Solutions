#include<stdio.h>

int main()
{
	int c, digits[10], others = 0;

	for(int i=0; i<10; i++)
	digits[i] = 0;

	printf("enter the charecters\n");

	while((c=getchar()) != EOF)
	{
		if(c >= '0' && c <= '9')
		++digits[c-'0'];
		else
		++others;
	}

	printf("digits  occurence\n");

	for(int i=0; i<10; i++)
	printf("%3d %5d\n", i, digits[i]);

	printf("Other charecters %d\n",others);
}
