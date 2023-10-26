#include <stdio.h>

int main() {

    int temperature;

    printf ("Enter the temperature: \n");
    scanf ("%d", &temperature); 
       
    printf ("The temperature to be checked is: %d \n", temperature);

        if (temperature >= -10 && temperature < 70)
        {
       
            printf ("The temperature of %d is valid\n", temperature);
        }
        else
        {
            printf ("The temperature of %d is invalid\n", temperature);
        }

    return 0;
}