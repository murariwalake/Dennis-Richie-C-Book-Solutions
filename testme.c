int printf(char *str, ...);
int scanf(char *str, ...);

int main(){
	int a,b;
	printf("Enter a,b\n");
	scanf("%d %d", &a, &b);
	printf("a+b = %d\n", a+b);
	return 0;
}
