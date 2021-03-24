#include<stdio.h>
#define MAX 100

void escape(char s[], char t[]);
void realChars(char s[], char t[]);

int main(){
	int c, i=0;
	char s[MAX],t[MAX],r[MAX];
	printf("enter the first string\n");

	while( (c=getchar()) !=EOF )
		t[i++] = c;
	t[i]='\0';
 
	escape(s,t);
	printf("the entered string with escape charecters is\n %s",s);

	realChars(s,r);
	printf("\nOriginal string is\n %s",r);
	return 0;
}

void escape(char s[], char t[]){
	int i,j = 0;
	for(i = 0; t[i] != '\0'; i++){
		switch(t[i]){
			case '\n': s[j++] = '\\'; s[j++] = 'n'; break;

			case '\t':s[j++] = '\\'; s[j++] = 't'; break;

			default: s[j++] = t[i]; break;
		}

	}
}

void realChars(char s[], char t[]){
	int i,j = 0;

	for(i = 0; s[i] != '\0'; i++ ){
		switch(s[i]){
			case '\\':if(s[i+1] == 'n')
						t[j++] = '\n';

					  else if(s[i+1] == 't')
					  	t[j++] = '\t';

					  i++; break;

			default:t[j++] = s[i];
		}
	}
}











