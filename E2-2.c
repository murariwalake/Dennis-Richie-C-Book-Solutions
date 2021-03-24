#include<stdio.h>
#define LIMIT 1000

int main(){
	char s[LIMIT];
	int c;

	for(int i= 0; i < LIMIT-1; i++){
		if((c = getchar()) != EOF){
			if(c != '\n')
				s[i] = c;
			else
				break;
		}

		else
			break;

	}

	printf("%s\n",s);
return 0;
}

