#include <stdio.h>
int main() {
    char name[15]; //define a character string varaible called namethat can contain up to 15 characters

    printf("Hello, please enter your name:");
    scanf("%s", name); //scanf lets us read in data from the keyboard; %s - in string format - and stores in the variable name
    printf("Your name is %s\n", name); //prints the phrase in quotes and substitutes in my name for the %s format specifier

    return 0;
}