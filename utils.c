#include <stdio.h>
#include <stdlib.h>

char *get_input(const char *filePath) {
  FILE *file = fopen(filePath, "r");
  if (file == NULL) {
    perror("Failed to open file");
    return NULL;
  }

  // Determine the file size
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the string
  char *fileContents = (char *)malloc(fileSize + 1);
  if (fileContents == NULL) {
    perror("Failed to allocate memory");
    fclose(file);
    return NULL;
  }

  // Read the file contents into the string
  fread(fileContents, 1, fileSize, file);
  fileContents[fileSize] = '\0'; // Null-terminate the string

  // Close the file
  fclose(file);

  return fileContents;
}