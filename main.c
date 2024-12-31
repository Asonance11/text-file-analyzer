#include <stdio.h>

int character_count(FILE *file) {
  int count = 0;
  char ch;

  while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ' || ch == '\n') {
      continue;
    } else {
      count++;
    }
  }

  return count;
}

int line_count(FILE *file) {
  int lines = 0;
  char ch;

  while ((ch = fgetc(file)) != EOF) {
    if (ch == '\n') {
      lines++;
    }
  }

  return lines;
}

int main(int argc, char *argv[]) {
  FILE *file;

  file = fopen("example.txt", "r");

  if (file == NULL) {
    printf("Unable to open file \n");
    return 0;
  }

  printf("The number of characters in the file is %d\n", character_count(file));
  rewind(file);
  printf("The number of lines in the file is %d\n", line_count(file));

  fclose(file);

  return 0;
}
