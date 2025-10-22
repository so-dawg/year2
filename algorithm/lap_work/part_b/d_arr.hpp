#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <vector>

using namespace std;
using clk = chrono::high_resolution_clock;

class d_arr {
  private:
    vector<int> items;
    vector<int> recent;
    
  public:
    void insertFront(int value) {
      items.push_back(value);
      recent.clear();
    }

    void show() {
      cout << "[top -> bottom]: ";
      for (auto it = items.rbegin(); it != items.rend(); ++it)
        cout << *it << " ";
      cout << "\n";
    }

    void removeFront() {
      if (items.empty()) {
        return;
      }
      int last = items.back();
      items.pop_back();
      recent.push_back(last);
    }

    void undo_remove() {
      if (recent.empty()) {
        return;
      }
      int last = recent.back();
      recent.pop_back();
      items.push_back(last);
    }
};

void arr_observe(d_arr* obj, void (d_arr::*method)(), string msg) {
    auto t0 = clk::now();
    (obj->*method)();
    auto t1 = clk::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout << msg << ": " << duration.count() << " ns" << endl;
}
