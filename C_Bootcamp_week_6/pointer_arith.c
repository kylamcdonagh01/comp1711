#include <stdio.h>

int main()
{
    int vector[5] = {11,13,17, 23 , 31}; //creating an array

    int* address = vector; //create variable called'address' that points to the memory adress of the next address in vector array

    printf ( "\nAddress[0] = %d\n\n", *address);

    printf ( "\nAddress[1] = %d\n\n", *address++); //this also prints 11 (instead of 13) because the '++' (increment) is after the adress has been printed 

    printf ("\nAddress[2] = %d\n\n", *++address); //the '++' is in the right place here, it is incrementing the address pointed to BEFORE printing the variable

    printf ("\n \nWhat is happening here?\n");

}