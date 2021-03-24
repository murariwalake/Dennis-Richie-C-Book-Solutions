/*program to check largest line line among entered lines*/

#include<stdio.h>
#define MAXLENGTH 1000
/*
int getline(char[]);
void copy(char[] , char[]);
*/
int getLine(char lin[])
{
        int c, i = 0;
        for(i = 0; i < MAXLENGTH-1  &&  ( c = getchar()) != EOF  &&  c != '\n'; i++)//get line
        lin[i] = c;

        if(c == '\n')
        lin[i] = c; //if there is new line add it to string

        lin[++i] = '\0'; //add null charecter at the end of string

        return i; // return number of charecters in the line or strin
}

void copy( char to[], char from[])
{
        int i = 0;

        while((to[i] = from[i]) != '\0') // copy the string from "from" to "to"
                ++i;

}


int main(void)
{
	int len;
	int max = 0;
	char line[MAXLENGTH]="";
	char largest[MAXLENGTH]="";

	while( (len = getLine(line) ) > 0)// storing length in to "len" and checking whether string conaitns charecters or not
	if(len > max)                    //if entered string is larger then previouse larger string
	{                                //then recently entered one will become larger string
		max = len;
		copy(largest, line);
	}

	printf("Largest line is \n %s\n", largest);
	return 0;
}
