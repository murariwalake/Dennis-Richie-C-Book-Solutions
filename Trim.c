
/*program to remove multiple spaces, lines and tabes*/

#include<stdio.h>
int main()
{
	int c,i = 0;
	char s[1000];
	while( ( c= getchar() ) != EOF  && i < 1000)
	{
		 if(   ( (i==0 || s[i-1]=='\n' ) && (c==' ' || c=='\t' || c=='\n') )   ||   (s[i-1]==' ' && (c==' ' || c=='\t') )   )
			continue;
		else if(c == '\t')
		s[i++] == 32;
		else
		s[i++] = c;
	}

//	s[i] = '\0';

	printf("\n%s\n",s);

}


/* if its firts line then in starting  there should not be space, tab or new line*/
/*if entering charecter is tab then insert space for it*/
/*if previous line is new line then there should not continous new line*/
