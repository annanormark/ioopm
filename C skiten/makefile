CC = gcc

FLAGS = -Wall -ggdb -g -std=c99

all: db

db: ny2.o treefunctions.o dbfunctions.o
	$(CC) $(FLAGS) -o db ny2.o treefunctions.o dbfunctions.o

ny2.o: ny2.c treefunctions.h dbfunctions.h
	$(CC) $(FLAGS) -c ny2.c

treefunctions.o: treefunctions.c treefunctions.h
	$(CC) $(FLAGS) -c treefunctions.c

dbfunctions.o: dbfunctions.c dbfunctions.h treefunctions.h
	$(CC) $(FLAGS) -c dbfunctions.c

main: ny2.c
	$(CC) $(FLAGS) -o main ny2.c

run: all
	./db /Users/Anna/ioopm14/uppgifter/fas0/sprint1/abstraktion/SWE.db
