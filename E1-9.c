#include<stdio.h>

int main()
{
	int c, prev = 32;
	while((c = getchar())!=EOF){
		if(c == 32 && prev == 32)
		    continue;
		putchar(c);
		prev = c;
		 

	}
	
}
