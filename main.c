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
int word_count(FILE *file) {
  int words = 0;
  int in_word = 0;
  char ch;

  while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ' || ch == '\n' || ch == '\t') {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      words++;
    }
  }
  return words;
}

int main(int argc, char *argv[]) {
  FILE *file;

  if (argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }

  file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("Unable to open file \n");
    return 0;
  }

  printf("The number of characters in the file is %d\n", character_count(file));
  rewind(file);
  printf("The number of lines in the file is %d\n", line_count(file));
  rewind(file);
  printf("The number of words in the file is %d\n", word_count(file));

  fclose(file);

  return 0;
}
