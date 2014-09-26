#include <stdio.h>

#include "dbfunctions.h"
#include "listfunctions.h"

int main(int argc, char *argv[]){
  checkArguments(argc); //går ej ur main om den returnerar -1
  printWelcome();
  // Read the input file
  char *filename = argv[1];
  printf("Loading database \"%s\"...\n\n", filename);
  FILE *database = fopen(filename, "r");
  char buffer[128];

  while(!(feof(database))){
    list = makeDB(buffer, database, list);
  }    // Main loop
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
      cursor = findKey(list, buffer);
      list = insertEntry(buffer, list, cursor);      // Insert new node to the front of the list
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
      break;
    default:
      // Please try again
      puts("Could not parse choice! Please try again"); 
    }
    puts(""); 
    } 
  return 0;
}

