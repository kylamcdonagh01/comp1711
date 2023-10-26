#include <stdio.h>

int main() {

    int number;

    printf ("Enter the number: \n");
    scanf ("%d", &number); 
       
    printf ("The number to be checked is: %d \n", number);

        if (number == 0)
        {
            //checks if number is equal to 0
            printf ("The number of %d is zero\n", number);

        }
        else if (number < 0)
        {
            printf ("The number %d is negative\n", number);
        }
        
        else
        {
            printf ("The number %d is positive\n", number);
        }

    return 0;
}