#include <stdio.h>

int main() {

    int grade;

    printf ("Enter the grade: \n");
    scanf ("%d", &grade); 
       
    printf ("The grade to be checked is: %d \n", grade);

        if (grade >= 70)
        {
       
            printf ("The grade of %d is a distinction\n", grade);

        }
        else if (grade >= 50)
        {
            printf ("The grade of %d is a pass\n", grade);
        }
        
        else
        {
            printf ("The grade of %d is a fail\n", grade);
        }

    return 0;
}