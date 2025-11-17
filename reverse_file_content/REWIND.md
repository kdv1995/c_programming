Example
Use the rewind() function to read the beginning of the file twice:

FILE \*fptr;
fptr = fopen("filename.txt", "r");

char myString[100];

fgets(myString, 100, fptr);
printf("%s", myString);

rewind(fptr);

fgets(myString, 100, fptr);
printf("%s", myString);

fclose(fptr);
Definition and Usage
The rewind() function moves the position indicator to the beginning of the file.

The rewind() function is defined in the <stdio.h> header file.

Syntax
rewind(FILE \* fptr);
Parameter Values
Parameter Description
fptr Required. A file pointer, usually created by the fopen() function.
