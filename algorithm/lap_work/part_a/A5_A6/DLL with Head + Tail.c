struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

struct DLL_HeadTail {
    DNode* head;
    DNode* tail;

    void push_front(int val) {
        DNode* new_node = new DNode{val, head, nullptr};
        if (head) head->prev = new_node;
        head = new_node;
        if (!tail) tail = head;
    }

    void pop_front() {
        if (!head) return;
        DNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void push_back(int val) {
        DNode* new_node = new DNode{val, nullptr, tail};
        if (tail) tail->next = new_node;
        tail = new_node;
        if (!head) head = tail;
    }

    void pop_back() {
        if (!tail) return;
        DNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }
};
