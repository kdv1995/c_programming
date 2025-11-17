Example
Get a pointer to the first occurrence of a string in another string:

char myStr[] = "The rain in Spain falls mainly on the plains";
char \*myPtr = strstr(myStr, "ain");
if (myPtr != NULL) {
printf("%s", myPtr);
}
Definition and Usage
The strstr() function returns a pointer to the position of the first occurrence of a string in another string.

The strstr() function is defined in the <string.h> header file.

Syntax
strchr(char _ str, char _ substring);
Parameter Values
Parameter Description
str Required. A pointer to the string being searched.
substring Required. The string to search for.
Technical Details
Returns: A char type pointer to the position in the string where the substring was found or NULL if the substring was not found.
