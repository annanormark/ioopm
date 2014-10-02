#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listfunctions.h"



void readInput(const char *n,char *buffer){
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  puts(n);
}
  
void printWelcome(void){
  puts("Welcome to");
  puts(" ____    ____       ");
  puts("/\\  _`\\ /\\  _`\\     ");
  puts("\\ \\ \\/\\ \\ \\ \\L\\ \\   ");
  puts(" \\ \\ \\ \\ \\ \\  _ <\\ ");
  puts("  \\ \\ \\_\\ \\ \\ \\L\\ \\ ");
  puts("   \\ \\____/\\ \\____/ ");
  puts("    \\/___/  \\/___/  ");
  puts("");
}

void makeChoice(int choice){
    puts("Please choose an operation");
    puts("1. Query a key");
    puts("2. Update an entry");
    puts("3. New entry");
    puts("4. Remove entry");
    puts("5. Print database");
    puts("0. Exit database");
    printf("? ");
}

void mainloop(char *buffer, FILE *database){
  while(!(feof(database))){
    list = makeDB(buffer, database, list);
  }
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
    
  }
