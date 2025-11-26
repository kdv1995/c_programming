// Simple File Explorer (CLI Tool)
// Create a program that:
// Lists files in the current pathectory
// Lets you open one to view contents
// Allows deletion or renaming
// 1. I'm planning to use several functions, openpath(), reapath(), closepath()
// from <pathent.h> for listing files.; also I will use
// That how I think about this task:
// I'm having a while loop that is controlled by a flag variable running; until
// it running, I will be listing all possible operations that user can use: list
// all d
// commands is a keyword that would start the program itself;

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum Operation { LIST_FILES = 1, VIEW_FILE, DELETE_FILE, RENAME_FILE, EXIT };

int main() {
  DIR *dir;
  const char *path = "./";
  char *buffer;
  buffer = malloc(256 * sizeof(char));
  int operation_input;
  bool running = true;

  if (access(path, R_OK) == 0 && access(path, X_OK) == 0 &&
      access(path, W_OK) == 0) {
    printf("You can read, write and execute commands in the current folder:\n");
  } else {
    perror("access");
    return EXIT_FAILURE;
  }

  struct dirent *entry;

  dir = opendir(path);

  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }
  while (running) {
    printf("Select an operation:\n");
    scanf("%d", &operation_input);

    switch (operation_input) {
    case LIST_FILES:
      while ((entry = readdir(dir)) != NULL) {
        printf("Name: %s\n", entry->d_name);
        printf("Type: %d\n", entry->d_type);
        printf("Inode: %llu\n", entry->d_ino);
        printf("Record length: %d\n", entry->d_reclen);
        printf("-------------------\n");
      }
      break;

    case VIEW_FILE: {
      FILE *file;
      const char *path = "./README.md";
      file = fopen(path, "r");
      if (file == NULL) {
        perror("fopen");
        break;
      }

      printf("Enter the file name to view: \n");
      while (fgets(buffer, 256, file) != NULL) {
        printf("%s", buffer);
      }
      break;
    }

    case DELETE_FILE: {
      char filename[256];
      int result = 0;
      printf("Delete file operation selected.\n");
      scanf("%s", filename);
      result = remove(filename);
      if (result == 0) {
        printf("File deleted successfully.\n");
      } else {
        perror("Error deleting file");
        break;
      }
      printf("Would you like to continue? (1 for yes / 0 for no): \n");

      break;
    }

    case RENAME_FILE: {
      char newname[256];
      char oldname[256];
      printf("Rename file operation selected.\n");

      printf("Enter old filename and new filename: \n");

      scanf("%s %s", oldname, newname);
      if (rename(oldname, newname) == 0) {
        printf("File renamed successfully.\n");
      } else {
        perror("Error renaming file");
        break;
      }
    }
    case EXIT:
      running = false;
      break;
    }
  }

  closedir(dir);

  return EXIT_SUCCESS;
}
