#include <stdlib.h>
#include <string.h>

typedef struct node{
  char *key;
  char *value;
  struct node *next;
} *Node;

Node emptyNode(void){
  return malloc(sizeof(struct node));
}

Node setKey(const char *newKey, Node list){
  list->key = malloc(strlen(newKey) + 1);
  strcpy(list->key, newKey);
  return list;
}

Node setValue(const char *newVal, Node list){
  list->value = malloc(strlen(newVal) + 1);
  strcpy(list->value, newVal);
  return list;
}

Node setNextEntry(Node head, Node tail){
  head->next = tail; 
  return head;
}

char *listKey(Node list){
  return list->key;
}

char *listValue(Node list){
  return list->value;
}
 
Node nextEntry(Node list){
   return list->next;
}




