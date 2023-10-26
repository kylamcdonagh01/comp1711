#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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

// Complete the main function
int main() {
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

    while (fgets(line_buffer, buffer_size, file) != NULL) { //iterate through file one line at a time
        if (count < 100) {
            char date[11], time[6], steps[20]; //temporary variables
            tokeniseRecord(line_buffer, ",", date, time, steps);
            fdata.steps = atoi(steps);
            strcpy(fdata.date, date);
            strcpy(fdata.time,time);
            records[count] = fdata;
            count = count + 1;
        }
        
    }

    fclose(file); //always remember to close the file again!

    printf("Number of records in file: %d\n", count);

    for (int i = 0; i < count && i < 3; i++) {
        if (i == 0) {
            printf("%s/%s/%d\n", records[i].date, records[i].time, records[i].steps);
        }
        if (i == 1) {
            printf("%s/%s/%d\n", records[i].date, records[i].time, records[i].steps);
        }
        if (i == 2) {
            printf("%s/%s/%d\n", records[i].date, records[i].time, records[i].steps);
        }
    }

    return 0;
}

