#include<stdio.h>
#define LOW 0
#define HIGH 300
#define STEP 20

int min()
{
	for(int fahr = HIGH; fahr>=LOW; fahr -=STEP)
	printf("%6f",(5.0/9.0)*(fahr-32));
}
