typedef struct node *Node;

Node cursor;

Node list = NULL;

void readline(char *dest, int n, FILE *source);

Node makeDB(char *buffer, FILE *database, Node list);

void printEntry(const char*n, Node cursor);

Node findKey(Node cursor, char*buffer);

Node updateValue(char *buffer, Node cursor);

Node insertEntry(char *buffer, Node list, Node cursor);

Node deleteEntry(char *buffer, Node *list);

void printDB(Node cursor);

