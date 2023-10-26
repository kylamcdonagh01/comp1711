#include <stdio.h>

float sum (float a, float b) //5 is in the float a parameter, y in in float b parameter
{
    float answer;
    answer = a + b;
    return answer;
}

int main () 
{
    float y = 2.0;
    float z = sum(5, y); // calling our new function

    printf ("The sum of 5 and %.2f is %.2f\n", y, z); // %.2f means to 2 decimal places

    return 0;
}