#include <stdio.h>

int main () {
    char filename [] = "data.txt"; //created a file
    FILE *file = fopen (filename, "w"); // or "a", "w+", "a+" //creating a pointer to the file
    if (file == NULL) { //tests for an error when opening the file
        perror(""); 
        return 1;
    }

    fclose(file);
    return 0;
}