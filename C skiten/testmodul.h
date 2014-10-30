typedef struct node *Node;

Node emptyNode(void);

Node setKey(char *newKey, Node list);

Node setValue(char *newVal, Node list);

Node setNextEntry(Node head, Node tail);

char *listKey(Node list);

char *listValue(Node list);
 
Node nextEntry(Node list);
