#include <string>
#include "node.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using clk = chrono::high_resolution_clock;

class Sll_plus {
  private:
    Node* head;
    Node* cur;
    Node* temp;
    Node* recent;
    int n;

  public:
    Sll_plus() {
      head = nullptr;
      cur = nullptr;
      temp = nullptr;
      recent = nullptr;
      this->n = 0;
    }

    void traverse() {
      if (this->n == 0){
        cout << "(empty!)" << endl;
        return;
      }
      cur = head;
      cout << "[head -> tail]: ";
      while (cur != nullptr){
        cout << cur->data << " -> ";
        cur = cur->next;
      }
      cout << "nullptr" << endl;
    }

    void insertFront(int val) {
      temp = new Node{val, head};
      head = temp;
      recent = head;
      this->n++;
    }

    void removeFront() {
      if (!head) {
        return;
      }
      Node* temp1 = head;
      head = head->next;
      recent = temp1;
      this->n--;
    }
    
    void undo_add() {
      if (!head || head != recent) {
        return;
      }
      Node* temp2 = head;
      head = head->next;
      delete temp2;
      recent = nullptr;
      this->n--;
    }

    void undo_remove() {
      if (!recent) {
        return;
      }
      recent->next = head;
      head = recent;
      recent = nullptr;
      this->n++;
    }
};

void sll_observe(Sll_plus *obj, void (Sll_plus::*method)(), string msg)
{
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " nanosecond(s)" << endl;
}
