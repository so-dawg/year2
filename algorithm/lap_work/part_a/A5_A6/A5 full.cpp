#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>

// Singly Linked List with Head Only
struct SLL_HeadOnly {
    struct Node {
        int data;
        Node* next;
    };
    Node* head = nullptr;

    void push_front(int val) {
        head = new Node{val, head};
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

// Singly Linked List with Head and Tail
struct SLL_HeadTail {
    struct Node {
        int data;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;

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

// Doubly Linked List with Head and Tail
struct DLL_HeadTail {
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_front(int val) {
        Node* new_node = new Node{val, head, nullptr};
        if (head) head->prev = new_node;
        head = new_node;
        if (!tail) tail = head;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void push_back(int val) {
        Node* new_node = new Node{val, nullptr, tail};
        if (tail) tail->next = new_node;
        tail = new_node;
        if (!head) head = tail;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }
};

// Benchmark runner
template<typename ListType>
void benchmark(const std::string& label) {
    ListType list;
    const int N = 100000;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        if (rand() % 100 < 70)
            list.push_back(i);
        else
            list.pop_front();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << label << " took " << duration.count() << " seconds\n";
}

int main() {
    benchmark<SLL_HeadOnly>("SLL Head Only");
    benchmark<SLL_HeadTail>("SLL Head+Tail");
    benchmark<DLL_HeadTail>("DLL Head+Tail");
    return 0;
}
