/*
   Title       : A program to define a macro SIZEOF(x), without using sizeof operator
   Author      : Gagan A
   Date        : 31/07/2020
   Description : Input : No input is required
                 Output: To print the size of variable x without using sizeof operator
*/

#include <stdio.h>

/* MACRO definition */
#define SIZEOF(x) (char *)(&x + 1) - (char *)(&x)

int main()
{
    /* Declare local variables */
    int i_x; 
    char c_x, option; 
    float f_x; 
    double d_x; 
    long long int lli_x; 
    signed short int ssi_x; 
    unsigned short int usi_x;
    signed int si_x;
    unsigned int ui_x;
    signed long int sli_x;
    unsigned long int uli_x;
    signed long long int slli_x;
    unsigned long long int ulli_x;
    signed char sc_x;
    unsigned char uc_x;
    long double ld_x;
    signed short ss_x;
    unsigned short us_x;
    signed long sl_x;
    unsigned long ul_x;
    signed long long sll_x;
    unsigned long long ull_x;

    do
    {
	/* To print the size of x of basic data types without using sizeof operator */
	printf("Size of int \t\t\t: %2zu bytes\n", SIZEOF(i_x));
	printf("Size of char \t\t\t: %2zu byte\n", SIZEOF(c_x));
	printf("Size of float \t\t\t: %2zu bytes\n", SIZEOF(f_x));
	printf("Size of double \t\t\t: %2zu bytes\n", SIZEOF(d_x));
	printf("Size of long long \t\t: %2zu bytes\n", SIZEOF(lli_x));

	/* Print the size of x of data types using qualifiers and without sizeof operator */

	/* int */
	printf("Size of signed short int \t: %2zu bytes\n", SIZEOF(ssi_x));
	printf("Size of unsigned short int \t: %2zu bytes\n", SIZEOF(usi_x));
	printf("Size of signed int \t\t: %2zu bytes\n", SIZEOF(si_x));
	printf("Size of unsigned int \t\t: %2zu bytes\n", SIZEOF(ui_x));
	printf("Size of signed long int \t: %2zu bytes\n", SIZEOF(sli_x));
	printf("Size of unsigned long int \t: %2zu bytes\n", SIZEOF(uli_x));
	printf("Size of signed long long int\t: %2zu bytes\n", SIZEOF(slli_x));
	printf("Size of unsigned long long int\t: %2zu bytes\n", SIZEOF(ulli_x));

	/* char */
	printf("Size of signed char \t\t: %2zu byte\n", SIZEOF(sc_x));
	printf("Size of unsigned char \t\t: %2zu byte\n", SIZEOF( uc_x));

	/* double */
	printf("Size of long double \t\t: %2zu bytes\n", SIZEOF(ld_x));

	/* short */
	printf("Size of signed short \t\t: %2zu bytes\n", SIZEOF(ss_x));
	printf("Size of unsigned short \t\t: %2zu bytes\n", SIZEOF(us_x));

	/* long */
	printf("Size of signed long \t\t: %2zu bytes\n", SIZEOF(sl_x));
	printf("Size of unsigned long \t\t: %2zu bytes\n", SIZEOF(ul_x));

	/* long long */
	printf("Size of signed long long \t: %2zu bytes\n", SIZEOF(sll_x));
	printf("Size of unsigned long long \t: %2zu bytes\n", SIZEOF(ull_x));

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	scanf("%c", &option);
	getchar();

    } while (option == 'y');

    return 0;
}
