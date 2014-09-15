#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//test hdusahfuondakfnpidanfcpdanvpdnaop
typedef struct node{
  char *key;
  char *value;
  struct node *next;
} *Node;

void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}

int checkArguments(int argc){
  if (argc < 2){
    puts("Usage: db [FILE]");
    return -1;
  }
  return 0;
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

Node makeDB(char *buffer, FILE *database, Node list){
  Node newNode = malloc(sizeof(struct node));
  readline(buffer, 128, database);
  newNode->key = malloc(strlen(buffer) + 1);
  strcpy(newNode->key, buffer);
  readline(buffer, 128, database);
  newNode->value = malloc(strlen(buffer) + 1);
  strcpy(newNode->value, buffer);
  newNode->next = list; 
  return newNode;
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

void readInput(const char *n,char *buffer){
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  puts(n);
}

void printEntry(const char *n, Node cursor){
  puts(n);
  printf("key: %s\nvalue: %s\n", cursor->key, cursor->value);
}

Node findKey(Node cursor, char *buffer){
  while(cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){
      printEntry("found entry:", cursor);
      return cursor;
    }else{
      cursor = cursor->next;
    }
  }
  return NULL;
}

Node updateValue(char *buffer, Node cursor){
  if(cursor != NULL){
    printf("Enter new value: ");
    readline(buffer, 128, stdin);
    free(cursor->value);
    cursor->value = malloc(strlen(buffer) + 1);
    strcpy(cursor->value, buffer);
    puts("Value inserted successfully!");
    return cursor;
  }
 else{
   printf("Could not find an entry matching key \"%s\"!\n", buffer);
   return cursor;
 }
}

Node insertEntry(char *buffer, Node list, Node cursor){
  if(cursor == NULL){
    puts("Key is unique!\n");
    Node newNode = malloc(sizeof(struct node));	
    newNode->key = malloc(strlen(buffer) + 1);
    strcpy(newNode->key, buffer);
    printf("Enter value: ");
    readline(buffer, 128, stdin);
    newNode->value = malloc(strlen(buffer) + 1);
    strcpy(newNode->value, buffer);
    newNode->next = list;
    list = newNode;    
    puts("");
    puts("Entry inserted successfully:");
    printf("key: %s\nvalue: %s\n", list->key, list->value);
    return list;
  }
  return list;
}

Node deleteEntry(Node cursor, char *buffer){
  Node prev = NULL;
  while(cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){
      if(prev == NULL){ // Delete first node
	cursor = cursor->next;
	printf("Deleted the following entry:\nkey: %s\nvalue: %s\n", cursor->key, cursor->value);
      	return cursor;
      }
      else{
	prev->next = cursor->next;
	printf("Deleted the following entry:\nkey: %s\nvalue: %s\n", cursor->key, cursor->value);   
     	return prev;
      }
    }
    else{
      prev = cursor;
      cursor = cursor->next;
    }
  }
  printf("Could not find an entry matching key \"%s\"!\n", buffer);
  return prev;
}    

void printDB(Node cursor){
  while(cursor != NULL){
    puts(cursor->key);
    puts(cursor->value);
    cursor = cursor->next;
  }
}  

int main(int argc, char *argv[]){
  checkArguments(argc); //går ej ur main om den returnerar -1
  printWelcome();
  // Read the input file
  char *filename = argv[1];
  printf("Loading database \"%s\"...\n\n", filename);
  FILE *database = fopen(filename, "r");
  char buffer[128];
  Node list = NULL;
  while(!(feof(database))){
    list = makeDB(buffer, database, list);
  }    // Main loop
  int choice = -1;
  while(choice != 0) {
    makeChoice(choice);
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    Node cursor;
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
      cursor = deleteEntry(list, buffer);
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
  
