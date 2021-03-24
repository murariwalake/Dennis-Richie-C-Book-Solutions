#include<stdio.h>

int main()
{
	int c,i=0;
	char string[1000];

	while(( (c = getchar()) != EOF) && (i<999)) // A s[999] we have to put '\0'. 
	{
		string[i++] = c;
		if(c == '\n' && i > 80)
		{
			string[i] = '\0';
		        printf("\n%s\n",string);
			i = 0;
		}
		else if(c =='\n')
			i = 0;
	}
} 
