#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }
int menu() {
    char filename [] = "FitnessData_2023.csv"; //open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 100; //size of buffer determines how many characters are read from file
    char line_buffer[buffer_size];
    int count = 0;
    FITNESS_DATA fdata; //creating array of FITNESS_DATA

    FITNESS_DATA records[100];

    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice: \n")

    // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n'); 


        // switch statement to control the menu.
        switch (choice)
        {
        count = 0
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            printf("Filename to be imported: %s", filename);
            break;

        case 'B':
        case 'b':
            while (fgets(line_buffer, buffer_size, file) != NULL) { //iterate through file one line at a time
                if (count < 100) {
                    count = count + 1;
                }
                printf("Number of records in file: %d\n", count);
            break

}
// Complete the main function
int main() {
    menu();
    

//    while (fgets(line_buffer, buffer_size, file) != NULL) { //iterate through file one line at a time
  //      if (count < 100) {
    //        char date[11], time[6], steps[20]; //temporary variables
      //      tokeniseRecord(line_buffer, ",", date, time, steps);
        //    fdata.steps = atoi(steps);
          //  strcpy(fdata.date, date);
            //strcpy(fdata.time,time);
            //records[count] = fdata;
            //count = count + 1;
     //   }
        
  //  }

    fclose(file); //always remember to close the file again!

  //  printf("Number of records in file: %d\n", count);


    return 0;
}

