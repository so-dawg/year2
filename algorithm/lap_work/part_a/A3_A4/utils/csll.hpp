#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "node.hpp"
using namespace std;
using clk = chrono::high_resolution_clock;

class Csll
{
private:
    Node *head;
    Node *cur;
    Node *temp;
    Node *tail; // keep tail for O(1) front insert fix
    int n;

public:
    Csll()
    {
        head = nullptr;
        cur = nullptr;
        temp = nullptr;
        tail = nullptr;
        this->n = 0;
    }

    void traverse()
    {
        if (n == 0)
        {
            cout << "(empty!)" << endl;
            return;
        }
        Node *cur = head;
        int count = 0;
        do
        {
            // cout << cur->data << " -> ";
            cur = cur->next;
            count++;
        } while (cur != head && count < n);
        cout << "(head)" << endl;
    }

    void insertFront(int val)
    {
        Node *temp = new Node{val, nullptr};

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            tail->next = head;
        }
        else
        {
            temp->next = head;
            head = temp;
            tail->next = head; // keep circular link in O(1)
        }
        n++;
    }

    void rotateRight(int k)
    {
        if (!head || k == 0 || n == 0)
            return;
        k = k % n;
        if (k == 0)
            return;

        int steps = n - k;
        for (int i = 0; i < steps; ++i)
        {
            head = head->next;
            tail = tail->next;
        }
    }

    // Helpers
    int size() const { return n; }
    Node *headPtr() const { return head; }
    Node *at(int idx) const
    {
        if (!head || idx < 0)
            return nullptr;
        Node *p = head;
        // walk up to n steps max to avoid infinite loop
        for (int i = 0; i < idx && i < n && p; ++i)
            p = p->next;
        return p;
    }
};

void csll_observe(Csll *obj, void (Csll::*method)(), string msg)
{
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
}
