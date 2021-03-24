/*Program to convert hexadecimal to decimal value 
Note: to compile this use command gcc E2-3.c -lm */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int hexaToDecimal(char hexa[]);

int main(){
	char hexa[10];

	printf("enter the hexadecimal value\n");
	scanf("%s", hexa);		//tekes string as imput.

	printf("decimal equivalent is %d\n", hexaToDecimal(hexa));
}

int hexaToDecimal(char hexa[]){

	int num = 0;

	for(int i=0, j= strlen(hexa)-1; j>=0; i++,j--){
		if(hexa[j] >= '0' && hexa[j] <= '9'){
			num += (hexa[j] - '0') * pow(16,i);  //ex;123(hexa) = 1*16^2 + 2*16^1 + 3*16^0 = 291(decimal) 
		}

		else if(hexa[j] >= 'A' && hexa[j] <= 'F'){
			num +=  (hexa[j] - 'A' + 10) * pow(16,i);  //converts A-F letters into equevalent decimal value
		}

		else if(hexa[j] >= 'a' && hexa[j] <= 'f'){
                	num +=  (hexa[j] - 'a' + 10) * pow(16,i); //converts a-f letters into equevalent decimal value

        	}

		else{
			printf("invalid hexadecimal value\n");
			exit(0);
		}
	}
return num;
}


