#include<stdio.h>

int main(){
	int a[5];
	int a[10];
	int b[5] = {1,2,3,4,5,7,8};
	for(int i = 0; i<= 10; i++)
		printf("%d\t",a[i]);
	
	for(int i = 0; i < 8; i++)
		printf("%d\t", b[i]);
	return 0;
}
