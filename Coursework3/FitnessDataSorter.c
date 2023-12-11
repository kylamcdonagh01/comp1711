#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
int tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
                return 0;
            }
        }
    }
    return 1; // validating data
}

// Checks if the file is valid
int isFileValid(FILE *file) {
    // checking the file isnt NULL
    if (file == NULL) {
        printf("Error: invalid file\n");
        return 0;
    }

    // check the file isnt empty
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        printf("Error: invalid file\n");
        return 0;
    }

    return 1; // this indicates there are no errors

}

// reading data from file to array
int readDataFromFile(FILE *file, FitnessData *data, int *count) {
    char line[100];
    // reading each file in the file at a time
    while (fgets(line, sizeof(line), file) != NULL) {
        // tokenise and store teh data in the array
        if (tokeniseRecord(line, ',', data[*count].date, data[*count].time, &(data[*count].steps)) == 0) {
            (*count)++;
        } else {
            // dealing with bad data
            return 1;
        }
    }

    return 0; // indicates data has been read successfully 

}
// Bubble sorting algorithm on fitness data
void bubbleSort(FitnessData *data, int count) {
    int swapped; // checks for swappages
    do {
        swapped = 0;
        for (int i = 0; i < count - 1; i++) {
            // compare values and decide if to swap
            if (data[i].steps < data[i + 1].steps) {
                FitnessData temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                swapped = 1; // swap did occur
            }
        }
    } while (swapped);
}

// trying a selection sorting algorithm instead
void selectionSort(FitnessData *data, int count) {
    int i, j, maxIndex;
    for (i = 0; i < count -1; i++) {
        maxIndex = i;

        for (j = i + 1; j < count; j++) {
            if (data[j].steps > data[maxIndex].steps) {
                maxIndex = j;
            }
        }

        // now swapping the maximum steps with the first one
        FitnessData temp = data[maxIndex];
        data[maxIndex] = data[i];
        data[i] = temp;
    }
}
    

// writing sorted data to new file
void writeSortedDataToFile(char *filename, FitnessData *data, int count) {
    // creating a new filename with .tsv
    char outputFilename[100];
    sprintf(outputFilename, "%s.tsv", filename);

    // opening the file in write mode
    FILE *outputFile = fopen(outputFilename, "w");

    // writing the sorted data to the file
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%s\t%s\t%d", data[i].date, data[i].time, data[i].steps);
        // adding next line
        if (i < count -1) {
            fprintf(outputFile, "\n");
        }
    }

    fclose(outputFile); // closing the file of course!

    // printing complete message
    printf("Data sorted and written to %s\n", outputFilename);
}

int main() {
    // declaring variables
    char filename[100];
    FILE *file;
    int count = 0;
    FitnessData data[100];

    //asking the user for the file name
    printf("Enter filename: ");
    scanf("%s", filename);

    // opening the file
    file = fopen(filename, "r");

    // checking if the file is actually valid
    if (!isFileValid(file) || readDataFromFile(file, data, &count) != 0) {
        return 1; // exits if file is not valid
    }

    fclose(file); // closing the file of course!

    // sorting the data
    bubbleSort(data, count);

    //selectionSort(data, count);

    // writing the bubble sorted data into another file
    writeSortedDataToFile(filename, data, count);

    return 0;
}
