#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node{
  char *key;
  char *value;
  struct node *smaller;
  struct node *bigger;
} *Tree;

Tree cursor;
Tree list = NULL;

void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}

Tree makeTree(char *keybuf, char *valuebuf, Tree newNode){
  if(newNode == NULL){ 
    Tree newNode = malloc(sizeof(struct node));  
    newNode->key = malloc(strlen(keybuf) + 1);
    strcpy(newNode->key, keybuf);
    newNode->value = malloc(strlen(valuebuf) + 1);
    strcpy(newNode->value, valuebuf);
    newNode->bigger = NULL;
    newNode->smaller = NULL;
    return newNode;
  }
  else if (strcmp(keybuf, newNode->key) > 0){
    newNode->smaller = makeTree(keybuf, valuebuf, newNode->smaller);
  } 
  else {
    newNode->bigger = makeTree(keybuf, valuebuf, newNode->bigger);
  }
  return newNode;

}

Tree makeDB(char *buffer, FILE *database, Tree list){
  char keybuf[128];
  char valuebuf[128];
  readline(keybuf, 128, database);
  readline(valuebuf, 128, database);
  list = makeTree(keybuf, valuebuf, list);
  return list;
}

void printEntry(const char *n, Tree cursor){
  puts(n);
  printf("ke: %s\nvalue: %s\n", cursor->key, cursor->value);
}

Tree findKey(Tree cursor, char *buffer){
  while(cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){
      printEntry("found entry:", cursor);
      return cursor;
    }else{
      if(cursor->value < buffer) {
	findKey(cursor->smaller, buffer);
      }
      else{
	findKey(cursor->bigger, buffer);
      }
    }
  }
  return NULL;
}

Tree updateValue(char *buffer, Tree cursor){
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

Tree insertEntry(char *buffer, Tree list, Tree cursor){
  if(cursor == NULL){
    if(buffer < list->key){
      insertEntry(buffer, list->smaller, cursor);
    }
    if(buffer > list->key){
      insertEntry(buffer, list->bigger, cursor);
    }
    if(list == NULL){
    puts("Key is unique!\n");
    Tree newNode = malloc(sizeof(struct node));	
    newNode->key = malloc(strlen(buffer) + 1);
    strcpy(newNode->key, buffer);
    printf("Enter value: ");
    readline(buffer, 128, stdin);
    newNode->value = malloc(strlen(buffer) + 1);
    strcpy(newNode->value, buffer);
    list = newNode;    
    puts("");
    puts("Entry inserted successfully:");
    printf("key: %s\nvalue: %s\n", list->key, list->value);
    return list;
    }
  }
  return list;
}

Tree minValue(Tree cursor){
  if(cursor != NULL){
    if(!(cursor->smaller == NULL)){
      minValue(cursor->smaller);
    }
    else
      return cursor->smaller;
  }
  return cursor;
  
}

Tree deleteEntry(char *buffer, Tree *list){
  Tree temp = NULL;
  Tree cursor = *list;
  while(cursor != NULL){
    if(strcmp(buffer, cursor->key) == 0){
      if(cursor->smaller == NULL){
	if(cursor->bigger == NULL){
	  cursor = NULL;
	}
	else{
	  cursor=cursor->bigger;
	}
      }
      if(cursor->bigger == NULL){
	cursor = cursor->bigger;
      }
      else{
	temp = minValue(cursor->bigger);
	cursor->value = temp->value;
	cursor->key = temp->key;
	deleteEntry(temp->key, &cursor->bigger);
      }
    }  
    else{
      if(buffer < cursor->key){
	deleteEntry(buffer, &cursor->smaller);
      }  
      if(buffer > cursor->key){
	deleteEntry(buffer, &cursor->bigger);
      }
    }
  }
  printf("Could not find an entry matching key \"%s\"!\n", buffer);
  return cursor;
}    

void printDB(Tree cursor){
  if(!(cursor == NULL)){
    puts(cursor->key);
    puts(cursor->value);
  }
  if(cursor->bigger != NULL) {
    printDB(cursor->bigger);
  }
  if(cursor->smaller != NULL){
    printDB(cursor->smaller);
  }
}


