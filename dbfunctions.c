#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listfunctions.h"

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
  Node newNode =  return malloc(sizeof(struct node));
  readline(buffer, 128, database);
  newNode = setKey(buffer, newNode);
  readline(buffer, 128, database);
  newNode = setValue(buffer, newNode);
  newNode = setNextEntry(newNode, list);
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
  
