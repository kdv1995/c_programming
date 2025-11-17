Example
Read the character at position 4 from the start of the file:

FILE \*fptr;
fptr = fopen("filename.txt", "r");

fseek(fptr, 4, SEEK_SET);
char c = fgetc(fptr);
printf("%c", c);

fclose(fptr);
Definition and Usage
The fseek() function moves the position indicator to a specified position in the file.

The fseek() function is defined in the <stdio.h> header file.

Syntax
fseek(FILE \* fptr, long int offset, int origin);
Parameter Values
Parameter Description
fptr Required. A file pointer, usually created by the fopen() function.
offset Required. Specifies a position in the file relative to the origin.
origin Required. Specifies the position in the file from which the offset is applied. It can be one of the following constants:
SEEK_SET - Offset is relative to the beginning of the file
SEEK_CUR - Offset is relative to the current position in the file
SEEK_END - Offset is relative to the end of the file

The SEEK_END value may not be fully supported by some implementations of the library.
Technical Details
Returns: An int value which is zero if successful and non-zero if an error occurred.
More Examples
Example
Find the size of the file by moving the position indicator to the end of the file and then checking its position

// Open a file
FILE \*fptr;
fptr = fopen("filename.txt", "r");

// Move the position indicator to the end of the file
fseek(fptr, 0, SEEK_END);

// Read the position
int position = ftell(fptr);

// Display the value
printf("%d", position);

fclose(fptr);
