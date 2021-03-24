#include<stdio.h>

int main()
{
	float fahr;
	printf("Enterthe fahrenheit value\n");
	scanf("%f",&fahr);
	printf("%d\n",(int)((5.0/9.0)*(fahr-32.0)));
	printf("%6d\n",(int)((5.0/9.0)*(fahr-32.0)));
	printf("%f\n",(5.0/9.0)*(fahr-32.0));
	printf("%8.3f\n",(5.0/9.0)*(fahr-32.0));
	printf("%.2f\n",(5.0/9.0)*(fahr-32.0));
	printf("%10.2f\n",(5.0/9.0)*(fahr-32.0));
}
