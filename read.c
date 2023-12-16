#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int file_descriptor;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Open the file for reading
    file_descriptor = open("example.txt", O_RDONLY);
    
    if (file_descriptor == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read from the file
    bytesRead = read(file_descriptor, buffer, BUFFER_SIZE - 1);

    if (bytesRead == -1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer to treat it as a string
    buffer[bytesRead] = '\0';

    // Display the read content
    printf("Read from file:\n%s\n", buffer);

    // Close the file descriptor
    close(file_descriptor);

    return 0;
}

