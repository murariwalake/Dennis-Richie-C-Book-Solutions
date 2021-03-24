/*program which returns first location in str1 where any character from str2 occurs*/

#include<stdio.h>
#include<string.h>
#define LIMIT 100

int charLocation(char str1[], char str2[]);

int main(){
	char str1[LIMIT];
	char str2[LIMIT];
	int c;

	printf("enter strin1\n");
	scanf("%s",str1);

	printf("enter strin2\n");
        scanf("%s",str2);

	int pos = charLocation(str1, str2);

	if(pos >=0 )
	printf("first location of charrecter from str2 in str1 is %d\n", pos);

	else
	printf("none of the charecters from str2 is mtching with str1\n");

return 0;
}

int charLocation(char str1[], char str2[]){
	int chars[94], i;
	for(i = 0; i < 94; i++)
		chars[i] = 0;

	for(i = 0; i < strlen(str2); i++)
		++chars[str2[i] - ' '];

	for(i = 0; i < strlen(str1); i++)
		if(chars[str1[i] - ' '] > 0)	//is ith character from str1 present in str2 ?
			return i;

	return -1;
}
