#include<stdio.h>

int main(){
	int i, j, n;
	printf("Enter number of rows\n");
	scanf("%d", &n);

	for(i = 0; i<n; i++)
		for(j=0; j <= n+i; j++)
			printf("%c", i+j < n-1?' ':j < n+i?'*':'\n');
	return 0;
}
