#include<stdio.h>

int main()
{
	float fahr;
	printf("Enter the fahrenheit value\n");
	scanf("%f",&fahr);
	printf("celsius value is %f",(5.0/9.0)*(fahr-32));
}
