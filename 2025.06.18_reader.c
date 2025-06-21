#include <stdio.h>
#include <string.h> // For strlen and strchr

// Function to read a string with spaces using fgets
char *readStringWithSpaces(char *str, int size, FILE *stream) {
    if (fgets(str, size, stream) != NULL) {
        // Remove the trailing newline character if it exists
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        } else if (len == size - 1 && str[size - 1] != '\n' && stream != stdin) {
             // If the buffer is full and no newline, check if we need to
             // discard remaining characters in the stream to prevent
             // issues with subsequent reads from a file.
             int ch;
             while ((ch = fgetc(stream)) != '\n' && ch != EOF);
        }
        return str; // Return the pointer to the string on success
    } else {
        return NULL; // Return NULL on error or end-of-file
    }
}

int main() {
    char sentence[100]; // Declare a character array to hold the string

    printf("Enter a sentence: ");

    // Call the function to read the string
    if (readStringWithSpaces(sentence, sizeof(sentence), stdin) != NULL) {
        printf("You entered: %s\n", sentence);
    } 
    else {
        printf("Error reading input.\n");
    }
    
    return 0;
}
