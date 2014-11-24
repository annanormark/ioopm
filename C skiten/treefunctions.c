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

void readInput(const char *n,char *buffer){
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  puts(n);
}

Tree makeTree(char *keybuf, char *valuebuf, Tree newNode){
  if(newNode == NULL){ 
    // if the pointer is empty it makes a new entry
    Tree newNode = malloc(sizeof(struct node));  
    printf("alloc %s\n", keybuf);
    newNode->key = malloc(strlen(keybuf) + 1);
    strcpy(newNode->key, keybuf);
    printf("alloc %s\n", valuebuf);
    newNode->value = malloc(strlen(valuebuf) + 1);
    strcpy(newNode->value, valuebuf);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }
  else if (strcmp(keybuf, newNode->key) > 0){
    //if the key is smaller than the key you want to insert
     newNode->right = makeTree(keybuf, valuebuf, newNode->right);
  } 
  else if(strcmp(keybuf, newNode->key) < 0){
    //if the key is bigger than the key you wnat to insert
     newNode->left = makeTree(keybuf, valuebuf, newNode->left);
  }
  return newNode;
  
}

Tree makeDB(FILE *database, Tree list){
  //makes a database in tree-form
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
    //it searshes as long as it hasn't reached the end of the tree
    if(strcmp(buffer, cursor->key) == 0){
      printEntry("found entry:", cursor);
      return cursor;
      break;
    }
    else{ 
      //compares if the key we're searching for is bigger or smaller than the existing key
      if(strcmp(cursor->key, buffer) < 0) {
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
    //searches for the entry it wants to update, as long as it hasn't reached the end of the tree
    printf("Enter new value: ");
    readline(buffer, 128, stdin);
    free(cursor->value);
    printf("alloc %s", buffer);
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

Tree insertEntry(char *buffer, Tree list, FILE *database){  
  Tree cursor = list;
  cursor = findKey(list, buffer);
  //if findKey doesn't find a key matching the one we want to insert, it will return NULL 
  if(cursor == NULL){
    //if cursor is NULL the key is unique and we can make a new entry
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

Tree maxValue(Tree cursor){
  Tree temp = NULL;
    while(cursor->right != NULL){
      temp = cursor;
      cursor = cursor->right;
    }  
    if(temp != NULL)
      temp->right = cursor->left;
  return cursor;
}

Tree minValue(Tree cursor){
  Tree temp = NULL;
    while(cursor->left != NULL){
      temp = cursor;
      cursor = cursor->left;
    }  
    if(temp != NULL)
      temp->left = cursor->right;
  return cursor;
}

void delete(char *buffer, Tree cursor){
  Tree temp = NULL;
  if(cursor != NULL) {
    if(strcmp(cursor->key, buffer) == 0) {
      if(cursor->right == NULL){
	if(cursor->left == NULL){
	  printf("freed %s\n", cursor->value);
	  free(cursor->value);
	  printf("freed %s\n", cursor->key);
	  free(cursor->key);
	  free(cursor);
	  cursor = NULL;
	  // return NULL;
	}		
	else{	   
	  temp = maxValue(cursor->left);
	  printf("freed %s\n", cursor->key);
	  free(cursor->key);
	  printf("alloc %s\n", temp->key);
	  cursor->key = malloc(strlen(temp->key) + 1);
	  strcpy(cursor->key, temp->key);
	  printf("freed %s\n", cursor->key);
	  free(cursor->value);
	  printf("alloc %s\n", temp->value);
	  cursor->value = malloc(strlen(temp->value) + 1);
	  strcpy(cursor->value, temp->value);
	  printf("freed %s\n", temp->value);
	  free(temp->value);
	  printf("freed %s\n", temp->key);
	  free(temp->key);
	  free(temp);
	  temp = NULL;
	  // return cursor;
	}
      }
      else if(cursor->left == NULL){
	  temp = minValue(cursor->right);
	  printf("freed %s\n", cursor->key);
	  free(cursor->key);
	  printf("alloc %s\n", temp->key);
	  cursor->key = malloc(strlen(temp->key) + 1);
	  strcpy(cursor->key, temp->key);
	  printf("freed %s\n", cursor->value);
	  free(cursor->value);
	  printf("alloc %s\n", temp->value);
	  cursor->value = malloc(strlen(temp->value) + 1);
	  strcpy(cursor->value, temp->value);
	  printf("freed %s\n", temp->value);
	  free(temp->value);
	  printf("freed %s\n", temp->key);
	  free(temp->key);
	  free(temp);
	  temp = NULL;
	  // return cursor;
	}
      else{
	if(cursor->right->left != NULL){
	  temp = minValue(cursor->right);
	  printf("freed %s\n", cursor->key);
	  free(cursor->key);
	  printf("alloc %s\n", temp->key);
	  cursor->key = malloc(strlen(temp->key) + 1);
	  strcpy(cursor->key, temp->key);
	  printf("freed %s\n", cursor->value);
	  free(cursor->value);
	  printf("alloc %s\n", temp->value);
	  cursor->value = malloc(strlen(temp->value) + 1);
	  strcpy(cursor->value, temp->value);
	  printf("freed %s\n", temp->value);
	  free(temp->value);
	  printf("freed %s\n", temp->key);
	  free(temp->key);
	  free(temp);
	  temp = NULL;
	  // return cursor;
	}
	else{
	  temp = cursor->right;
	  printf("freed %s\n", cursor->value);
	  free(cursor->value);
	  printf("alloc %s\n", temp->value);
	  cursor->value = malloc(strlen(temp->value) + 1);
	  strcpy(cursor->value, temp->value);
	  printf("freed %s\n", cursor->key);
	  free(cursor->key);
	  printf("alloc %s\n", temp->key);
	  cursor->key = malloc(strlen(temp->key) + 1);
	  strcpy(cursor->key, temp->key);	  
	  cursor->right = temp->right;
	  printf("freed %s\n", temp->value);
	  free(temp->value);
	  printf("freed %s\n", temp->key);
	  free(temp->key);
	  free(temp);
	  temp = NULL;
	  //	  return cursor;
	}
      }
    }
    else if((strcmp(buffer, cursor->key)) <= 0){
      if(cursor->left != NULL){
	temp = cursor->left;
	if(strcmp(buffer, cursor->left->key) == 0){
	  if(temp->left == NULL && temp->right == NULL){
	    printf("freed %s\n", temp->value);
	    free(temp->value);
	    printf("freed %s\n", temp->key);
	    free(temp->key);
      	    free(temp);
	    cursor->left = NULL;
	  }
	}
      }
      delete(buffer, cursor->left);
	  
    }
    else{
      if(cursor->right != NULL){
	temp = cursor->right;
	if(strcmp(buffer, cursor->right->key) == 0){
	  if(temp->left == NULL && temp->right == NULL){
	    printf("freed %s\n", temp->value);
	      free(temp->value);
	      printf("freed %s\n", temp->key);
	      free(temp->key);
       	      free(temp);
	      cursor->right = NULL;
	  }
	}
      }
      delete(buffer, cursor->right);
      
    }
  }
  cursor = NULL;
}

Tree deleteEntry(char *buffer, Tree *list){
  Tree cursor = *list;
  delete(buffer, cursor);
  if(cursor == NULL){ //if it does not exists
    printf("Could not find an entry matching key \"%s\"!\n", buffer);
    return *list;
  }
  puts("Entry was deleted sucsessfully");
  return cursor;
}   

void printDB(Tree cursor){
  if(!(cursor == NULL)){
    puts(cursor->key);
    puts(cursor->value);
  }
  if(cursor->left != NULL) {
    printDB(cursor->left);
  }
  if(cursor->right != NULL){
    printDB(cursor->right);
  }
}

void Fmax(Tree cursor){
  Tree temp = NULL;
    while(cursor->right != NULL){
      temp = cursor;
      cursor = cursor->right;
    }
    while(cursor->left != NULL){
      temp = cursor;
      cursor = cursor->left;
    }
    if(cursor->right != NULL){
      Fmax(cursor);
    }
    if(temp->right != NULL){
      if(temp->right->key == cursor->key){
	printf("freed %s\n", cursor->value);
	free(cursor->value);
	printf("freed %s\n", cursor->key);
	free(cursor->key);
	free(cursor);
	temp->right = NULL;
      }
    }
    else{
    printf("freed %s\n", cursor->value);
    free(cursor->value);
    printf("freed %s\n", cursor->key);
    free(cursor->key);
    free(cursor);
    temp->left = NULL;
    }
}

void FreeTree(Tree list){
  while(list != NULL){
    if(list->right != NULL)
      Fmax(list);
    else if(list->left != NULL)
      Fmax(list);
    else{
      printf("freed %s\n", list->value);
      free(list->value);
      printf("freed %s\n", list->key);
      free(list->key);
      free(list);
      list = NULL;
    }
  }
}






