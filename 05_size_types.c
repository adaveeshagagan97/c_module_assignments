/*
   Title       : A program to print sizes of all basic data types of C
   Author      : Gagan A
   Date        : 31/05/2020
   Description : Input : None
                 Output: To print the size of different data types of C
*/	   

#include <stdio.h>

int main()
{
    //to print the size of basic data types

    printf("Size of int \t\t\t: %2zu bytes\n", sizeof(int));
    printf("Size of char \t\t\t: %2zu byte\n", sizeof(char));
    printf("Size of float \t\t\t: %2zu bytes\n", sizeof(float));
    printf("Size of double \t\t\t: %2zu bytes\n", sizeof(double));
    printf("Size of long long \t\t: %2zu bytes\n", sizeof(long long));
    printf("Size of void \t\t\t: %2zu byte\n", sizeof(void));

    //Print the size of data types using qualifiers

    //int
    printf("Size of signed short int \t: %2zu bytes\n", sizeof(signed short int));
    printf("Size of unsigned short int \t: %2zu bytes\n", sizeof(unsigned short int));
    printf("Size of signed int \t\t: %2zu bytes\n", sizeof(signed int));
    printf("Size of unsigned int \t\t: %2zu bytes\n", sizeof(unsigned int));
    printf("Size of signed long int \t: %2zu bytes\n", sizeof(signed long int));
    printf("Size of unsigned long int \t: %2zu bytes\n", sizeof(unsigned long int));
    printf("Size of signed long long int\t: %2zu bytes\n", sizeof(signed long long int));
    printf("Size of unsigned long long int\t: %2zu bytes\n", sizeof(unsigned long long int));
    
    //char
    printf("Size of signed char \t\t: %2zu byte\n", sizeof(signed char));
    printf("Size of unsigned char \t\t: %2zu byte\n", sizeof( unsigned char));
    
    //double
    printf("Size of long double \t\t: %2zu bytes\n", sizeof( long double));

    //short
    printf("Size of signed short \t\t: %2zu bytes\n", sizeof(signed short));
    printf("Size of unsigned short \t\t: %2zu bytes\n", sizeof(unsigned short));

    //long
    printf("Size of signed long \t\t: %2zu bytes\n", sizeof(signed long));
    printf("Size of unsigned long \t\t: %2zu bytes\n", sizeof(unsigned long));

    //long long
    printf("Size of signed long long \t: %2zu bytes\n", sizeof(signed long long));
    printf("Size of unsigned long long \t: %2zu bytes\n", sizeof(unsigned long long));

    return 0;
}

    
