#include <stdio.h>

int main() {

    int mark;

    printf ("Enter the mark: \n");
    scanf ("%d", &mark); //takes a users input
        //& takes the address of mark
    printf ("The mark to be checked is: %d \n", mark);

    if (mark >= 0 && mark <= 100) //AND (&&)
    {
        //nested if statement
        if (mark == 0) //== checks equivalent to
        {
            //checks if mark is equal to 0
            printf ("The mark of %d is zero\n", mark); //the variable mark prints where %d is written in this message

        }
        //checks if mark is smaller than 40 (fail)
        else if (mark < 40)
        {
            printf ("The mark of %d is a fail\n", mark);
        }
        //checks if mark is greater than 40 (pass)
        else
        {
            printf ("The mark of %d is a pass\n", mark);
        }
    }      
    else
    {
        printf ("Marks must be between 0 and 100 \n");
    }

    return 0;
}