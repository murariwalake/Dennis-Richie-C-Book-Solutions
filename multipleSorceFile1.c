//use cc multipleSorceFile1.c multipleSorseFile2.c
#include<stdio.h>
extern int add(int, int);
int main(){
	printf("the source code is splited into two files namely multipleSorceFile1.c and multipleSorceFile2.c\n");
	printf("a+b=%d\n",add(10,20));
	return 0;
}
