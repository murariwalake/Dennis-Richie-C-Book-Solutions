/* Program to count number of lines entered */

#include<stdio.h>

int main()
{
	int c,n=0;
	while((c=getchar())!=EOF)
		if(c==10)		// or if(c=='\n')  charecter constent(ASCII) value for new line(\n) is 10
		++n;
	printf("Number of lines entered are %d\n",n);
}
