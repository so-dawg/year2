#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node {
    int value;
    Node* next;
};

// ==== Utility Build Functions ====
Node* buildSLL(int n) {
    if (n <= 0) return nullptr;
    Node* head = new Node{0, nullptr};
    Node* cur = head;
    for (int i = 1; i < n; i++) {
        cur->next = new Node{i, nullptr};
        cur = cur->next;
    }
    return head;
}

Node* buildCSLL(int n) {
    if (n <= 0) return nullptr;
    Node* head = new Node{0, nullptr};
    Node* cur = head;
    for (int i = 1; i < n; i++) {
        cur->next = new Node{i, nullptr};
        cur = cur->next;
    }
    cur->next = head;
    return head;
}

// ==== Part 5: push_front / pop_front ====
Node* sll_push_front(Node* head, int value) {
    Node* n = new Node{value, head};
    return n;
}

Node* sll_pop_front(Node* head) {
    if (!head) return nullptr;
    Node* nxt = head->next;
    delete head;
    return nxt;
}

Node* csll_push_front(Node* head, int value) {
    Node* n = new Node{value, nullptr};
    if (!head) {
        n->next = n;
        return n;
    }
    n->next = head->next;
    head->next = n;
    swap(head->value, n->value);
    return head;
}

Node* csll_pop_front(Node* head) {
    if (!head) return nullptr;
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    Node* toDelete = head->next;
    head->value = toDelete->value;
    head->next = toDelete->next;
    delete toDelete;
    return head;
}

// ==== Part 6: audit + delete ====
size_t auditSLL(Node* head) {
    size_t c = 0;
    Node* cur = head;
    while (cur) {
        ++c;
        cur = cur->next;
    }
    return c;
}

size_t auditCSLL(Node* head) {
    if (!head) return 0;
    size_t c = 1;
    Node* cur = head->next;
    while (cur != head) {
        ++c;
        cur = cur->next;
    }
    return c;
}

void deleteSLL(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void deleteCSLL(Node* head) {
    if (!head) return;
    Node* cur = head->next;
    while (cur != head) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    delete head;
}

// main placeholder
int main(){
    cout << "Part 5 & 6 Linked List Operations Demo" << endl;
    return 0;
}
