/* 
   Title       : Circular right shift and left shift of a number by n-bits entered by the user
   Author      : Gagan A
   Date        : 17/06/2020
   Description : Input : Read num, n, choice from the user
                 Output: To print either right shifted or left shifted num wrt to user's choice
*/

#include<stdio.h>

//function prototype
unsigned int right_shift(unsigned int num, unsigned  int n);
unsigned int left_shift(unsigned int num, unsigned int n);
void print_bits(int value);

int main()
{
    /* Declare variable option */
    char option;

    do
    {
	/* Declaring local variables */
	unsigned int value, num, n, choice;

	//prompt the user for the num
	printf("Enter num: ");
	scanf("%d", &num);

	//prompt for the n-bit to be shifted
	printf("Enter n: ");
	scanf("%d", &n);

	//prompt the user for the choice
	printf("Possible operations\n1.Circular Right shift\n2.Circular Left shift\nEnter Your Choice: ");
	scanf("%d", &choice);

	//validate the user_option
	switch ( choice )
	{
	    case 1:
		printf("The binary form of number : ");
		print_bits(num);

		//calls the function to perform right shift
		value = right_shift(num, n);

		printf("\nAfter Circular Right Shifting by %d", n);
		print_bits(value);
		break;

	    case 2:
		printf("The binary form of number : ");
		print_bits(num);

		//calls the function to perform left shift
		value = left_shift(num, n);

		printf("\nAfter Circular Left Shifting by %d", n);
		print_bits(value);
		break;

	    default:
		printf("Invalid Entry");
	}

	/* Check for continue */
	printf("\nDo you want to continue (y/n): ");
	scanf(" %c", &option);

    } while ( option == 'y' );

    return 0;
}

//function returns the circular_right shifted value
unsigned int right_shift(unsigned int num, unsigned int n)
{
    return ((num & ((1 << n) - 1)) << (sizeof(int) * 8 - n)) | (num >> n);

}

//function returns the circular_left shifted value
unsigned int left_shift(unsigned int num, unsigned int n)
{
    return ((num & (~0 << (sizeof(int) * 8 - n))) >> (sizeof(int) * 8 - n))  | (num << n); 
}

//function prints the value in binary form
void print_bits(int value)
{
    unsigned mask;

    printf("\nThe binary form of number: ");
    for( mask = (1 << (sizeof(int) * 8 - 1)); mask; mask >>= 1 )
    {
	(value & mask) ? printf("1") : printf("0");
    }

}
