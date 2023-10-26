#include <stdio.h> //header file
# include <stdlib.h> //Defines exit() //header file  

FILE *open_file(char filename[], char mode[]) { //special type of function that allows us to open a file
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file; //needs access to pointers to tell us where the file is going to live
}

int main() {
    char filename [] = "data.txt";
    FILE *file = open_file(filename, "r"); //open file for reading //calls function to open file 

    int buffer_size = 100; //size of buffer determines how many characters are read from file
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) { //iterate through file one line at a time
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}