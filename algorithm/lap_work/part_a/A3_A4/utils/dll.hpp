// dll.hpp
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "node.hpp"
using namespace std;
using clk = chrono::high_resolution_clock;

class Dll
{
private:
    DNode *head;
    DNode *cur;
    DNode *temp;
    int n;

public:
    Dll()
    {
        head = nullptr;
        cur = nullptr;
        temp = nullptr;
        this->n = 0;
    }

    void traverse()
    {
        if (this->n == 0)
        {
            cout << "(empty!)" << endl;
            return;
        }
        cur = head;
        while (cur != nullptr)
        {
            // cout << cur->data << "<->";
            cur = cur->next;
        }
    }

    void insertFront(int val)
    {
        temp = new DNode{val, nullptr, head};

        // If list not empty, update old head's 'prev' pointer
        if (head != nullptr)
        {
            head->prev = temp;
        }
        head = temp;
        this->n++;
    }

    void rotateRight(int k)
    {
        if (!head || k == 0 || n == 0 || n == 1)
            return;

        k = k % n; // effective rotation
        if (k == 0)
            return;

        // Find tail
        DNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        // Make list circular (easier rotation)
        tail->next = head;
        head->prev = tail;

        // Find new head (n - k) positions from old head
        DNode *newHead = tail;
        for (int i = 0; i < k; ++i)
        {
            newHead = newHead->prev;
        }

        // node *before* new head is new tail
        DNode *newTail = newHead->prev;

        // Break circular links to form new list
        newTail->next = nullptr; // New tail's next is null
        newHead->prev = nullptr; // New head's prev is null

        // Update head
        head = newHead;
    }

    // Helpers for benchmarking and A4
    int size() const { return n; }
    DNode *headPtr() const { return head; }
    DNode *at(int idx) const
    {
        if (idx < 0)
            return nullptr;
        DNode *p = head;
        while (idx-- > 0 && p)
            p = p->next;
        return p;
    }
    // O(1): erase a given node pointer
    void eraseNode(DNode *p)
    {
        if (!p)
            return;
        if (p->prev)
            p->prev->next = p->next;
        else
            head = p->next;
        if (p->next)
            p->next->prev = p->prev;
        delete p;
        --n;
    }
};

void dll_observe(Dll *obj, void (Dll::*method)(), string msg)
{
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
}