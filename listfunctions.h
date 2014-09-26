typedef struct node *Node;

Node cursor;

Node list = NULL;

void printEntry(const char*n, Node cursor);

Node findKey(Node cursor, char*buffer);

Node updateValue(char *buffer, Node cursor);

Node insertEntry(char *buffer, Node cursor);

Node deleteEntry(char *buffer, Node *list);

void printDB(Node cursor);

