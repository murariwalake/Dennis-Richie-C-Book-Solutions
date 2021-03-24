#define MAXLEN 1000
#include<stdio.h>
void reverse1(char s[] , int n);

int main()
{
	int c,i=0;
	char string[MAXLEN];

	while( (c=getchar() ) != EOF)
		string[i++]=c;

	string[i] = '\0';

	reverse1(string,  i-1);
	printf("\n%s\n",string);

}

void reverse1
( char s[], int n)
{
	int i=0,temp , j=n;

	/*while( (rs[i] = s[n-i-1]) && i < n)
		++i;

	rs[n] ='\0';
 	*/

	while(i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}


	return;
}


