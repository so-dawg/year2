#include "sll+.hpp"
#include "dll+.hpp"
#include "node.hpp"
#include "d_arr.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;



int main() {
  Dll test_dll;
  test_dll.insertFront(99);
  test_dll.insertFront(55);
  dll_observe(&test_dll, &Dll::traverse, "time: ");

  test_dll.removeFront();
  dll_observe(&test_dll, &Dll::removeFront, "time: ");
  test_dll.traverse();

  test_dll.undo_remove();
  dll_observe(&test_dll, &Dll::undo_remove, "time: ");
  test_dll.traverse();

  // Dynamic array tests
  d_arr test_arr;
  test_arr.insertFront(5);
  test_arr.insertFront(10);
  arr_observe(&test_arr, &d_arr::show, "time: ");
  test_arr.show();
  
  test_arr.removeFront();
  
  arr_observe(&test_arr, &d_arr::removeFront, "time: ");
  test_arr.show();
  
  test_arr.undo_remove();
  
  arr_observe(&test_arr, &d_arr::undo_remove, "time: ");
  test_arr.show();

  // SLL tests
  Sll_plus sll_test;
  
  sll_test.insertFront(20);
  sll_observe(&sll_test, &Sll_plus::traverse, "First traverse");
  
  sll_test.insertFront(30);
  sll_observe(&sll_test, &Sll_plus::removeFront, "Remove front");
  sll_test.traverse();
  
  sll_observe(&sll_test, &Sll_plus::undo_remove, "Undo removal");
  sll_test.traverse();

  return 0;
}
