#include <stdio.h>
#include <stdlib.h>

void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char current, previous;
    int count = 1;
    previous = fgetc(in);

    while ((current = fgetc(in)) != EOF) {
        if (current == previous) {
            count++;
        } else {
            fprintf(out, "%c%d", previous, count);
            previous = current;
            count = 1;
        }
    }
    fprintf(out, "%c%d", previous, count);

    fclose(in);
    fclose(out);
    printf("File compressed successfully!\n");
}

int main() {
    char inputFile[100], outputFile[100];

    printf("Enter the input file name: ");
    scanf("%s", inputFile);
    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    compressFile(inputFile, outputFile);
    return 0;
}
