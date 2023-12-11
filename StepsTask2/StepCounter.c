#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Function prototypes
void readDataFromFile();
void displayTotalRecords();
void findFewestSteps();
void findLargestSteps();
void findMeanStepCount();
void findLongestPeriodAbove500();
void printMenu();

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char filename[300];
FITNESS_DATA *fitnessDataArray = NULL;
int totalRecords = 0;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Outputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
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

int main() {
    char choice;

    do {
        printMenu();
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a':
                printf("Input filename: ");
                scanf("%s", filename);
                readDataFromFile();
                break;
            case 'B':
            case 'b':
                displayTotalRecords();
                break;
            case 'C':
            case 'c':
                findFewestSteps();
                break;
            case 'D':
            case 'd':
                findLargestSteps();
                break;
            case 'E':
            case 'e':
                findMeanStepCount();
                break;
            case 'F':
            case 'f':
                findLongestPeriodAbove500();
                break;
            case 'Q':
            case 'q':
                free(fitnessDataArray); // Free allocated memory
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 'Q');

    return 0;
}

void readDataFromFile() {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char buffer[300];
    int records = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        records++;
    }

    // Allocate memory for FITNESS_DATA array
    fitnessDataArray = (FITNESS_DATA *)malloc(records * sizeof(FITNESS_DATA));


    // Rewind file and read data into array
    rewind(file);
    for (int i = 0; i < records; i++) {
        fgets(buffer, sizeof(buffer), file);
        tokeniseRecord(buffer, ",", fitnessDataArray[i].date, fitnessDataArray[i].time, buffer);
        fitnessDataArray[i].steps = atoi(buffer);
    }

    fclose(file);
    totalRecords = records;
    printf("File successfully loaded.\n");
}

void displayTotalRecords() {
    printf("Total records: %d\n", totalRecords);
}

void findFewestSteps() {
    int minSteps = fitnessDataArray[0].steps;
    int index = 0;

    for (int i = 1; i < totalRecords; i++) {
        if (fitnessDataArray[i].steps < minSteps) {
            minSteps = fitnessDataArray[i].steps;
            index = i;
        }
    }

    printf("Fewest steps: %s %s\n", fitnessDataArray[index].date, fitnessDataArray[index].time);
}

void findLargestSteps() {
    int maxSteps = fitnessDataArray[0].steps;
    int index = 0;

    for (int i = 1; i < totalRecords; i++) {
        if (fitnessDataArray[i].steps > maxSteps) {
            maxSteps = fitnessDataArray[i].steps;
            index = i;
        }
    }

    printf("Largest steps: %s %s\n", fitnessDataArray[index].date, fitnessDataArray[index].time);
}

void findMeanStepCount() {
    if (totalRecords == 0) {
        printf("Mean step count: 0\n");
        return;
    }

    int sum = 0;

    for (int i = 0; i < totalRecords; i++) {
        sum += fitnessDataArray[i].steps;
    }

    int mean = (int)((float)sum / totalRecords + 0.5); //calculate mean and round to nearest integer
    printf("Mean step count: %d\n", mean);
}

void findLongestPeriodAbove500() {
    int start = -1;
    int end = -1;
    int currentStart = -1;

    for (int i = 0; i < totalRecords; i++) {
        if (fitnessDataArray[i].steps > 500) {
            if (currentStart == -1) {
                currentStart = i;
            }
        } else {
            if (currentStart != -1) {
                if (i - currentStart > end - start) {
                    start = currentStart;
                    end = i;
                }
                currentStart = -1;
            }
        }
    }

    if (currentStart != -1 && totalRecords - currentStart > end - start) {
        start = currentStart;
        end = totalRecords;
    }

    printf("Longest period start: %s %s\n", fitnessDataArray[start].date, fitnessDataArray[start].time);
    printf("Longest period end: %s %s\n", fitnessDataArray[end - 1].date, fitnessDataArray[end - 1].time);
}

void printMenu() {
    printf("\nMenu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
}
