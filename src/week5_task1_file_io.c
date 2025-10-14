// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// Orkhan Hajizada(241ADB170)
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char filename[100] = "data.txt";
  char line[256];
  int lineCount = 0;

  printf("Enter filename to create (e.g., data.txt): ");
  if (scanf("%99s", filename) != 1) {
    fprintf(stderr, "Invalid filename input.\n");
    return 1;
  }

  printf("Writing lines to %s...\n", filename);

  // TODO: 1. Open file for writing (mode = "w")
  fp = fopen(filename, "w");
  // TODO: 2. Check if file opened successfully
  if (fp == NULL) {
    perror("Error opening file for writing");
    return 1;
  }
  // TODO: 3. Write 2–3 lines of text to the file using fprintf()
  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");
  fprintf(fp, "File handling is easy once you practice.\n");
  // TODO: 4. Close the file
  fclose(fp);

  printf("Finished writing to %s.\n\n", filename);

  // TODO: 5. Open file again for reading (mode = "r")
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return 1;
  }
  // TODO: 6. Use fgets() in a loop to read and print each line to the console
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    lineCount++;
  }
  // TODO: 7. Close the file
  fclose(fp);

  printf("\nTotal lines read: %d\n", lineCount);

  return 0;

  // BONUS: ask user for filename instead of using default "data.txt"
  // BONUS: count number of lines read

  return 0;
}
