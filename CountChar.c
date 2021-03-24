#include<stdio.h>
int main()
{
	int n;
	for(n=0; getchar()!=EOF; ++n)
	 ;					//semi colon can also be placed in the same line of "for"

	printf("\n%d\n",n);
}
	
