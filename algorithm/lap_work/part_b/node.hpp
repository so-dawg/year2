#ifndef NODE
#define NODE

struct Node {
    int data;
    Node* next;
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

#endif
