/* program to delete all charrecters from string1 which occures in string2*/

#include<stdio.h>
#include<string.h>
#define LIMIT 100

int main(){
	char str1[LIMIT], result[LIMIT];
	int str2[94];
	int c,i,j;

	for(i = 0; i<94; i++)
		str2[i] = 0;

	printf("enter string 1\n");

	scanf("%s", str1);

	printf("enter string 2\n");

	getchar();

	while( ( c=getchar() ) != '\n')
		++str2[c - ' '];

	for(i = 0, j = 0; i < strlen(str1); i++)
		if(str2[str1[i]-32] == 0) //checking whether string2 have charrecter of string1 or not
			result[j++] = str1[i];
	result[j] = '\0';
	printf("Resulting string is %s\n", result);
}



