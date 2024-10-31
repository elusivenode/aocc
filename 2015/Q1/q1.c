#include "../../utils.c"
#include <stdio.h>
#include <stdlib.h>

int part1(char *input_data);
int part2(char *input_data);

int q1() {

  const char *homeDir = getenv("HOME");
  if (homeDir == NULL) {
    perror("Failed to get home directory");
    return 1;
  }
  char filePath[1024];
  snprintf(filePath, sizeof(filePath), "%s/Dev/aocc/2015/Q1/q1_input", homeDir);

  char *fileContents = get_input(filePath);
  if (fileContents == NULL) {
    return 1;
  }

  // Use the fileContents string as needed
  // printf("File contents:\n%s\n", fileContents);

  int a = part1(fileContents);
  printf("Part 1: %d\n", a);
  a = part2(fileContents);
  printf("Part 2: %d\n", a);

  // Free the allocated memory
  free(fileContents);

  return 0;
}

int part1(char *input_data) {

  int floor = 0;

  for (int i = 0; input_data[i] != '\0'; i++) {
    char c = input_data[i];
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }
  }
  return floor;
}

int part2(char *input_data) {

  int floor = 0;
  // Iterate over each character in the input_data string
  for (int i = 0; input_data[i] != '\0'; i++) {
    char c = input_data[i];
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }
    if (floor == -1) {
      return i + 1;
    }
  }
  return -1;
}
