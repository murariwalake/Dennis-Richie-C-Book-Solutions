#include<stdio.h>

int main()
{
	int c, blanks = 0, tabs = 0, newlines = 0;
	while((c = getchar()) != EOF){
	if(c == 32)
	++blanks;

	if(c == '\t')
        ++tabs;

	if(c == '\n')
        ++newlines;
	}

	printf("Blanks %d\n Tabs %d\n New lines %d\n", blanks, tabs, newlines);

}
