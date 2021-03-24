#include<stdio.h>
#include<limits.h>

int main(){
       printf("signed char range %d to %d\n", -(char) ((unsigned char)~0 >> 1) - 1 , (char) ((unsigned char) ~0 >> 1)  );
       printf("signed short range %d to %d\n", -(short) ((unsigned short)~0 >> 1) - 1 , (short) ((unsigned short) ~0 >> 1)  );
       printf("signed int range %d to %d\n", -(int) ((unsigned int)~0 >> 1) - 1 , (int) ((unsigned int) ~0 >> 1)  );
       printf("signed long range %ld to %ld\n", -(long) ((unsigned long)~0 >> 1) - 1 , (long) ((unsigned long) ~0 >> 1)  );

       printf("\nusigned char range 0 to %d\n",  (unsigned char) ~0 );
       printf("signed short range 0 to %d\n", (unsigned short)~0 );
       printf("signed int range 0 to %u\n", (unsigned int)~0 );
       printf("signed long range 0 to %lu\n", (unsigned long)~0 );
	printf("signed float range 0 to %f\n", ((float)~0 >> 1));

	return 0;
} 
