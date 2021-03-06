@file

#include <stdio.h>
#include "dbfunctions.h"
#include "treefunctions.h"
#include <stdlib.h>
#include <string.h>


/** Runs the whole program whith all the other files and also with the different cases that you find in dbfunctions.c file, it also then prints the following events for the different options*/

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
  while(!(feof(database))){
    list = makeDB(database, list);
  }
  fclose(database);
  int choice = -1;
  while(choice != 0) {
    makeChoice(choice);
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    switch(choice){
    case 1:
      // Query
      readInput("Searching database...", buffer);
      cursor = findKey(list, buffer);
      if(cursor == NULL){
	printf("Could not find an entry matching key \"%s\"!\n", buffer);
      }
      break;
    case 2:
      // Update
      readInput("Searching database...", buffer); 
      cursor = findKey(list, buffer);
      updateValue(buffer, cursor);
      break;   
    case 3:
      // Insert
      readInput("Searching database for duplicate keys...", buffer);
      list = insertEntry(buffer, list, database);      // Insert new node to the front of the list
      break;	      
    case 4:
      // Delete
      readInput("Searching database...", buffer);
      cursor = deleteEntry(buffer, &list);
      break;     
    case 5:
      // Print database
      printDB(list);
      break;
    case 0:
      // Exit
      puts("Good bye!");
      FreeTree(list);
      break;
    default:
      // Please try again
      puts("Could not parse choice! Please try again"); 
    }
    puts(""); 
  } 
  
  return 0;
}


