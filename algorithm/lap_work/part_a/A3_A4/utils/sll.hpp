#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "node.hpp"
using namespace std;
using clk = chrono::high_resolution_clock;

class Sll
{
private:
    Node *head;
    Node *cur;
    Node *temp;
    int n;

public:
    Sll()
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
            // cout << cur->data << "->";
            cur = cur->next;
        }
    }

    void insertFront(int val)
    {
        temp = new Node{val, nullptr};
        temp->next = head;
        head = temp;
        this->n++;
    }

    void rotateRight(int k)
    {
        if (!head || k == 0 || n == 0)
            return;

        k = k % n; // effective rotation
        if (k == 0)
            return;

        // Find the new tail: (n-k-1)th node
        Node *cur = head;
        for (int i = 0; i < n - k - 1; ++i)
        {
            cur = cur->next;
        }

        Node *newHead = cur->next;
        cur->next = nullptr; // break link

        // Find old tail
        Node *tail = newHead;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = head; 

        head = newHead;
    }

    // Helpers
    int size() const { return n; }
    Node *headPtr() const { return head; }
    Node *at(int idx) const
    {
        if (idx < 0)
            return nullptr;
        Node *p = head;
        while (idx-- > 0 && p)
            p = p->next;
        return p;
    }
    // O(1): erase node after known predecessor
    void eraseAfter(Node *prev)
    {
        if (!prev || !prev->next)
            return;
        Node *victim = prev->next;
        prev->next = victim->next;
        delete victim;
        --n;
    }
    // O(n): given a pointer to target, find its predecessor and erase
    void eraseGivenNodeWithoutPred(Node *target)
    {
        if (!head || !target)
            return;
        if (target == head)
        {
            head = head->next;
            delete target;
            --n;
            return;
        }
        Node *p = head;
        while (p && p->next != target)
            p = p->next;
        if (!p)
            return; // target not in list
        p->next = target->next;
        delete target;
        --n;
    }
};

void sll_observe(Sll *obj, void (Sll::*method)(), string msg)
{
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
}
