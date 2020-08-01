/*
   Title       : A program to demote the given float value to integer using bitwise operators / bitfields
   Author      : Gagan A
   Date        : 01/08/2020
   Description : Input : Read a float number from the user
                 Output: To print the given float number to its demoted int value
*/

#include <stdio.h>

/* Union definition */
union
{
    float num_f;

    struct
    {
	unsigned int MANTESSA :23;
	unsigned int EXPONENT :8;
	unsigned char SIGN :1;
    } floatRange;

} floatNum;

int main()
{
    /* Declare local variables */
    char option;  
    int exp;

    do
    {
	/* Read a float value from the user */
	printf("Enter a float value: ");
	scanf("%f", &floatNum.num_f ); 

	/* check if exponent part of num_f >= 127 */
	if (floatNum.floatRange.EXPONENT >= 127)
	{
	    /* Print demoted float value */
	    exp = floatNum.floatRange.EXPONENT - 127;  
	    floatNum.floatRange.MANTESSA &= (~((1 << (23 - exp)) - 1));
	    printf("demoted int value: %f \n",  floatNum.num_f);

	}
	else
	{
	    /* print demoted float value */
	    exp = 127 - floatNum.floatRange.EXPONENT;
	    floatNum.floatRange.SIGN &= 0;
	    floatNum.floatRange.EXPONENT &= 0;
	    floatNum.floatRange.MANTESSA &= 0;
	    printf("demoted int value: %f \n",  floatNum.num_f);
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}
