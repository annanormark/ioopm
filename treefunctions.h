typedef struct node *Tree;

extern Tree cursor;
extern Tree list;

void readline(char *dest, int n, FILE *source);

Tree makeTree(char keybuf, char valuebuf, Tree newNode);

Tree makeDB(char *buffer, FILE *database, Tree list);

void printEntry(const char *n, Tree cursor);

Tree findKey(Tree cursor, char *buffer);

Tree updateValue(char *buffer, Tree cursor);

Tree insertEntry(char *buffer, Tree list, Tree cursor);

Tree minValue(Tree cursor);

Tree deleteEntry(char *buffer, Tree *list);

void printDB(Tree cursor);
