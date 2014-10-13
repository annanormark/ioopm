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
    // if the pointer is empty it makes a new entry
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
    //if the key is smaller than the key you want to insert
    newNode->right = makeTree(keybuf, valuebuf, newNode->right);
  } 
  else {
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

Tree delete(char *buffer, Tree cursor){
  Tree temp = NULL;
  if(cursor != NULL){
    if(strcmp(cursor->key, buffer) == 0) {
      if(cursor->right == NULL){
	if(cursor->left == NULL){
	  cursor = NULL;
	  free(cursor);
	  return NULL;
	}
	else{
	  if(cursor->left->left == NULL) {
	    strcpy(cursor->key, cursor->left->key);
	    strcpy(cursor->value, cursor->left->value);
	    cursor->left = NULL;
	    free(cursor->left);
	    return cursor;
	  }		
	  else{	   
	    temp = minValue(cursor->left);
	    
	      
	      }
	}
      }
      else if(cursor->left == NULL){
	if(cursor->right->left == NULL){
	  temp = cursor->right;
	  strcpy(cursor->key, temp->key);
	  strcpy(cursor->value, temp->value);	  
	  cursor->right = temp->right;
	  free(temp);
	  return cursor;
	}
	else{
	  temp = minValue(cursor->right);
	  strcpy(cursor->key, temp->key);
	  strcpy(cursor->value, temp->value);
	  free(temp);
	  return cursor;
	}
      }
      else{
	if(cursor->right->left != NULL){
	  temp = minValue(cursor->right);
	  strcpy(cursor->key, temp->key);
	  strcpy(cursor->value, temp->value);
	  free(temp);
	  return cursor;
	}
	else{
	  temp = cursor->right;
	  strcpy(cursor->key, temp->key);
	  strcpy(cursor->value, temp->value);	  
	  cursor->right = temp->right;
	  free(temp);
	  return cursor;
      }
    }
    else if(strcmp(buffer, cursor->key) <= 0)
      cursor->right = delete(buffer, cursor->right);
    else
      cursor->left = delete(buffer, cursor->left);
      /*  if(cursor->right == NULL){
	strcpy(cursor->key, cursor->left->key);
	strcpy(cursor->value, cursor->left->value);
	cursor->left = delete(cursor->key, cursor->left);
      }
      else if(cursor->left == NULL){
	  strcpy(cursor->key, cursor->right->key);
	  strcpy(cursor->value, cursor->right->value);
	  cursor->right = delete(cursor->key, cursor->right);
      }
      else{
	temp = minValue(cursor->right);
	strcpy(cursor->key, temp->key);
	strcpy(cursor->value, temp->value);
	cursor->right = delete(cursor->key, cursor->right);
      }
    }
    while(cursor != NULL){
      if(strcmp(cursor->key, buffer) <= 0){
	if(strcmp(cursor->right->key, buffer) == 0){
	  temp = minValue(cursor->right->right);
	  strcpy(cursor->right->key, temp->key);
	  strcpy(cursor->right->value, temp->value);
	  return cursor;
	  break;
	}
	else{
	  cursor->right = delete(buffer, cursor->right);
	}
      }
      else if(strcmp(cursor->key, buffer) >= 0){
	if(strcmp(cursor->left->key, buffer) == 0){
	  temp = minValue(cursor->left->right);
	  cursor->left = temp;
	  return cursor;
	  break;
	}
	else{
	  cursor->left = delete(buffer, cursor->left);
	}
      }
      }*/
  }
  else
    return NULL;
  return cursor;
}
  

Tree deleteEntry(char *buffer, Tree *list){
  Tree cursor = *list;
  cursor = delete(buffer, cursor);
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



