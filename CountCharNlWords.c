#include<stdio.h>
#define IN 1
#define OUT 0

int main()
{
	int c,state, nl = 0, ch = 0, words = 0;
	while((c=getchar())!= EOF)
	{
		++ch;
		if(c == '\n')
		++nl;
		if(c == ' ' || c == '\t')
		state = OUT;
		else if(state == OUT)
		{
		state = IN;
		++words;
		}
	}
	printf("chars %8d\n new lines %3d\n words %7d\n", ch,nl,words);
}
