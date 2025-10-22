struct Node {
    int data;
    Node* next;
};

struct SLL_HeadOnly {
    Node* head;

    void push_front(int val) {
        Node* new_node = new Node{val, head};
        head = new_node;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void push_back(int val) {
        Node* new_node = new Node{val, nullptr};
        if (!head) {
            head = new_node;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = new_node;
    }

    void pop_back() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next->next) curr = curr->next;
        delete curr->next;
        curr->next = nullptr;
    }
};
