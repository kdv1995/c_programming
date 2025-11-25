// JS  data types
// String => methods that we can use in js => .toLowerCase(), .toUpperCase(),
// .length; substring(), split() Objects =>  structure that can hold multiple
// values as  key value pairs; Number => Boolean => true or false; isAdult,
// isLoggedIn Bigint =>  very large integers that are used in the web3
// integration but in this case that bigint doesnt return accurate results;
// 1000000000n / 3n 1000000n
// If you define that your stable coin has 6 decimals, that means that 1 dollar
// will be like 1000000 in the smart contract; formatValue(value, decimals ),
// and vice versa, if you want to parse user input and conver it to the prper
// smart contract value, parseValue(value, decimals);
// Array=> array methods => .push() length++ and set the element on the length
// index, .pop() --length;, .shift(), .unshift(), .map() , sort ,reduce({}, 0,
// [], ), filter(), find(), findIndex(), slice(), splice, foreach, join() , Null
// and Undefined
// if else, switch
// loops
// variables } functional programming
// function }
// OOP =>  {
// properties
// methods

// Data types,
//  How to works and operate over this data types;
// Closure, curring, hoisting, scope
//  Push mode => name me all of the methods of the arrays? how to find the
//  subsstring from the string
// Pull mode => this approach helps you to upgrade your thinking instead of
// outsourcing you mind to the tools;

// }
// for, while, do while, for of, for in
//  Loops
//  Array methods
//  Variables
//  Class, objects
//   What is the file on it low level ?
//   Object.entries(object) {
//   [key, value]
//   key is responbile for path and the value is responsible for file itself =>
//   every key has its type: file or directory;

// }
// offset and total file size
// If we get while iteration over the file EOF which is macros we get -1, which
// means there is not more bytes to read; We know through metadata the total
// size of the file in bytes;
// current offset < total size -> that means we have some more data to read;
// current offset == total size -> we reached the end of file;
// EOF is a mark that helps C to understand that we reached the end of file;
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  const char *path = "./";
  if (access(path, R_OK) == 0) {
    printf("You can read this folder:\n");
  } else {
    perror("access");
    return EXIT_FAILURE;
  }

  DIR *dir;
  dir = opendir(".");
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // #define __DARWIN_STRUCT_DIRENTRY { \
  // 	__uint64_t  d_ino;      /* file number of entry */ \
  // 	__uint64_t  d_seekoff;  /* seek offset (optional, used by servers) */ \
  // 	__uint16_t  d_reclen;   /* length of this record */ \ in bytes \
  // 	__uint16_t  d_namlen;   /* length of string in d_name */ \
  // 	__uint8_t   d_type;     /* file type, see below */ \
  // 	char      d_name[__DARWIN_MAXPATHLEN]; /* entry name (up to MAXPATHLEN
  // bytes) */ \
  // }
  //
  // #if __DARWIN_64_BIT_INO_T
  // struct dirent __DARWIN_STRUCT_DIRENTRY;
  // #endif /* __DARWIN_64_BIT_INO_T */

  // #if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
  // #define d_fileno        d_ino           /* backward compatibility */
  // #define MAXNAMLEN       __DARWIN_MAXNAMLEN
  // /*
  //  * File types
  //  */
  // #define DT_UNKNOWN       0
  // #define DT_FIFO          1
  // #define DT_CHR           2
  // #define DT_DIR           4
  // #define DT_BLK           6
  // #define DT_REG           8
  // #define DT_LNK          10
  // #define DT_SOCK         12
  // #define DT_WHT          14

  struct dirent *entry;
  int counter = 0;
  while ((entry = readdir(dir)) != NULL) {
    printf("Name: %s\n", entry->d_name);
    printf("Type: %d\n", entry->d_type);
    printf("Inode: %llu\n", entry->d_ino);
    printf("Record length: %d\n", entry->d_reclen);
    printf("-------------------\n");
    counter++;
  }

  printf("Total entries: %d\n", counter);

  closedir(dir);

  return EXIT_SUCCESS;
}
