#include <iostream>
#include <chrono>
#include "node.hpp"
#include <string>
#include <thread>

using namespace std;
using clk = chrono::high_resolution_clock;

class Dll {
  private:
    DNode* head;
    DNode* cur;
    DNode* temp;
    DNode* recent;
    int n;

  public:
    Dll() {
      head = nullptr;
      cur = nullptr;
      temp = nullptr;
      recent = nullptr;
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
        cout << "[head -> tail]: ";
        while (cur != nullptr)
        {
            cout << cur->data << " <-> ";
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }


    void insertFront(int val)
    {
        temp = new DNode{val, nullptr, head};

        if (head)
        {
            head->prev = temp;
        }
        head = temp;
        recent = head;
        this->n++;
    }

    void removeFront() {
      if (!head) {
        return;
      }
      DNode* temp1 = head;
      head = head->next;
      if (head) {
        head->prev = nullptr;
      }
      recent = temp1;
      this->n--;
    }

    void undo_remove() {
      if (!recent) {
        return;
      }
      recent->next = head;
      if (head) {
        head->prev = recent;
      }
      head = recent;
      recent = nullptr;
      this->n++;
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
