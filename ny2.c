#include <stdio.h>
#include "dbfunctions.h"
//#include "listfunctions.h"

int main(int argc, char *argv[]){
  if (argc < 2){
    puts("Usage: db [FILE]");
    return -1;
  }
  printWelcome();
  // Read the input file
  char *filename = argv[1];
  printf("Loading database \"%s\"...\n\n", filename);
  FILE *database = fopen(filename, "r");
  char buffer[128];
      // Main loop
  mainloop(buffer, database);
  return 0;
}

