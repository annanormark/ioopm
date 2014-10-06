#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node{
  char *key;
  char *value;
  struct node *right;
  struct node *left;
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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  else if (strcmp(keybuf, newNode->key) > 0){
    newNode->right = makeTree(keybuf, valuebuf, newNode->right);
  } 
  else {
    newNode->left = makeTree(keybuf, valuebuf, newNode->left);
  }
  return newNode;

}

Tree makeDB(FILE *database, Tree list){
  char keybuf[128];
  char valuebuf[128];
  readline(keybuf, 128, database);
  readline(valuebuf, 128, database);
  list = makeTree(keybuf, valuebuf, list);
  return list;
}

void printEntry(const char *n, Tree cursor){
  puts(n);
  printf("key: %s\nvalue: %s\n", cursor->key, cursor->value);
}

Tree findKey(Tree cursor, char *buffer){
  while(!(cursor == NULL)){
    if(strcmp(buffer, cursor->key) == 0){
      printEntry("found entry:", cursor);
      return cursor;
      break;
    }
    else{
      if(cursor->value < buffer) {
	cursor = cursor->right;	
      }
      else{
	cursor =  cursor->left;	
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

Tree insertEntry(char *buffer, Tree list, Tree cursor, FILE *database){  
  cursor = findKey(list, buffer);
  if(cursor == NULL){
    char valbuf[128];
    puts("Key is unique!\n");
    printf("Enter value: ");
    readline(valbuf, 128, stdin);
    list = makeTree(buffer, valbuf, list);
    puts("\nEntry inserted successfully:");
    printf("key: %s\nvalue: %s\n", buffer, valbuf);
    return list;
    }
  else if(!(cursor == NULL)){
    puts("Key not unique");
    return list;
  }
  return list;
}

Tree minValue(Tree cursor){
  while(cursor->right != NULL){
      cursor = cursor->right;
  }
  return cursor;
}

Tree delete(char *buffer, Tree cursor){
  Tree temp = NULL;
  if(cursor != NULL){
    if(strcmp(cursor->key, buffer) == 0){
      if(cursor->right == NULL){
	if(cursor->left == NULL){
	  cursor = NULL;
	  return cursor;
	}
	else{
	  cursor = cursor->left;
	  return cursor;
	}
      }
      else if(cursor->left == NULL){
	cursor = cursor->right;
	return cursor;
      }
      else{
	temp = minValue(cursor->right);
	strcpy(cursor->key, temp->key);
	strcpy(cursor->value, temp->value);
	cursor->right = delete(cursor->key, cursor->right);
      }
    }
    else{
      if(strcmp(cursor->right->key, buffer) <= 0){
	cursor->right = delete(buffer, cursor->right);
      }
      else{
	cursor->left = delete(buffer, cursor->left);
      }
    }
  }
  return cursor;
}

Tree deleteEntry(char *buffer, Tree *list){
  Tree cursor = *list;
  cursor = findKey(cursor, buffer);
  if(cursor == NULL){
    printf("Could not find an entry matching key \"%s\"!\n", buffer);
    return *list;
  } 
  else{
    cursor = delete(buffer, cursor);
    return cursor;
  }
}   

void printDB(Tree cursor){
  if(!(cursor == NULL)){
    puts(cursor->key);
    puts(cursor->value);
  }
  if(cursor->left != NULL) {
    puts("smaller, left");
    printDB(cursor->left);
  }
  if(cursor->right != NULL){
    puts("bigger, right");
    printDB(cursor->right);
  }
}



