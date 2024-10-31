#include "../../utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int part1(char *input_data);
int part2(char *input_data);
int area_paper_req(char *dims);

int q2() {

  const char *homeDir = getenv("HOME");
  if (homeDir == NULL) {
    perror("Failed to get home directory");
    return 1;
  }
  char filePath[1024];
  snprintf(filePath, sizeof(filePath), "%s/Dev/aocc/2015/Q2/q2_input", homeDir);

  char *fileContents = get_input(filePath);
  if (fileContents == NULL) {
    return 1;
  }

  int a = part1(fileContents);
  printf("Part 1: %d\n", a);
  /*a = part2(fileContents);
  printf("Part 2: %d\n", a);
*/
  // Free the allocated memory
  free(fileContents);

  return 0;
}

int part1(char *input_data) {

  char *token = strtok(input_data, "\n");
  int total_area_paper = 0;
  while (token != NULL) {
    total_area_paper += area_paper_req(token);
    token = strtok(NULL, "\n");
  }

  return total_area_paper;
}

int area_paper_req(char *dims) {

  int l, w, h;
  sscanf(dims, "%dx%dx%d", &l, &w, &h);

  int lw = l * w;
  int wh = w * h;
  int hl = h * l;

  int min = lw;
  if (wh < min) {
    min = wh;
  }
  if (hl < min) {
    min = hl;
  }

  return 2 * lw + 2 * wh + 2 * hl + min;
}