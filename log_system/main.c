#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

enum Operation { LIST_FILES = 1, VIEW_FILE, DELETE_FILE, RENAME_FILE, EXIT };

int main() {
  FILE *logFile;
  logFile = fopen("log.txt", "a");
  if (logFile == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char *line_to_append = "This is a new line appended to the file.\n";
  time_t currentTime = time(NULL);
  struct tm *t = localtime(&currentTime);

  DIR *dir;
  const char *path = "./";
  char buffer[256];

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
      strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", t);
      fprintf(logFile, "List files of the directory: %s\n", buffer);
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

      strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", t);
      fprintf(logFile, "View file content: %s\n", buffer);

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

      strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", t);
      fprintf(logFile, "File removed: %s, %s\n", buffer, filename);

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
      strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", t);

      fprintf(logFile, "File rename from old %s to new %s filename  %s\n",
              oldname, newname, buffer);
    }
    case EXIT:
      running = false;
      strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", t);

      fprintf(logFile, "File successfully closed on %s\n", buffer);

      break;
    }
  }

  closedir(dir);
  fclose(logFile);

  return EXIT_SUCCESS;
}
