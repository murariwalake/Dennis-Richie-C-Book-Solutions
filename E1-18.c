
#include<stdio.h>

int main()
{
	extern int c,i;
	char s[1000];

	while( (c = getchar() ) != EOF  && i < 1000)
	{
		if(i==0  && ( c == ' ' || c == '\t' || c == '\n') )
			continue;

		if(c == '\n')
		while(s[i-1] == ' '  ||  s[i-1] == '\t'  || s[i-1] == '\n')
			--i;

		s[i++] = c;
	}

	s[i] ='\0';
	printf("\n\n%sLAST BLANKS MULTIPLE NEW LINES ARE TRIMMED OUT\n", s);

}
int c, i = 0;
