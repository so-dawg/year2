#include <iostream>

using namespace std;

struct Node{
  int value;
  Node* next;
};

int main(void){
  int n = 5;
  Node* head = nullptr;
  Node* cur = nullptr;

  for (int i=n; i>0; i--){
    cur = new Node{i, head};
    head = cur;
  }
  
  //Challenge 1: Insert at the front
  Node* new_node = new Node{8,nullptr};
  new_node->next = head;
  head = new_node;
  n++;

  //Challenge 2: Insert at the end
  cur = head;
  for (int i=0; i<n-1; i++){
    cur = cur->next;
  }
  Node* new_node1 = new Node{14,nullptr};
  new_node1->next = cur->next;
  cur->next = new_node1;
  n++;

  //Challenge 4: Delete from the front
  cur = head;
  Node* temp = cur;
  cur = cur->next;
  delete temp;
  head = cur;
  n--;

  //Challenge 3: Insert at the middle
  cur = head;
  for (int i=0; i<(n/2); i++){
    cur = cur->next;
  }
  Node* new_node2 = new Node{99,nullptr};
  new_node2->next = cur->next;
  cur->next = new_node2;
  n++;

  //Challenge 5: Delete from the end
  cur = head;
  for (int i=0; i<n-2; i++){
    cur = cur->next;
  }
  temp = cur->next;
  cur->next = nullptr;
  delete temp;
  n--;

  //Challenge 6: Delete from the middle
  cur = head;
  for (int i=0; i<(n/2); i++){
    cur = cur->next;
  }
  Node* cur1 = cur->next;
  cur->next = cur1->next;
  delete cur1;
  n--;
  
  //Challenge 7: Traverse list
  cur = head;
  while (cur){
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << "\n";

  //Challenge 8: Swap two Node
  cur = head;
  cur = cur->next;
  head->next = cur->next;
  cur->next = head;
  head = cur;

  //Challenge 9: Search the list
  cur = head;
  while (cur->value != 3){
    cur = cur->next;
  }
  cout << cur->value << "\n";

}
