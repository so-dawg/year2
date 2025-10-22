struct SLL_HeadTail {
    Node* head;
    Node* tail;

    void push_front(int val) {
        Node* new_node = new Node{val, head};
        head = new_node;
        if (!tail) tail = head;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    void push_back(int val) {
        Node* new_node = new Node{val, nullptr};
        if (!tail) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop_back() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next != tail) curr = curr->next;
        delete tail;
        tail = curr;
        tail->next = nullptr;
    }
};

