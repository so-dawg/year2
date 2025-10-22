#include <iostream>
#include <string>
#include "utils/sll.hpp"
#include "utils/dll.hpp"
#include "utils/csll.hpp"
// #include "utils/cdll.hpp"

int main() {
    Sll list;
    Csll listA;
    Dll listB;

    int n = 10000;
    for(int i= n; i>0; i--){
        list.insertFront(i);
        listA.insertFront(i);
        listB.insertFront(i);
    }

    sll_observe(&list, &Sll::traverse, "\nSLL Observe: \n");
    csll_observe(&listA, &Csll::traverse, "\nCSLL Observe: \n");
    dll_observe(&listB, &Dll::traverse, "\nDll Observe: \n");
    
    return 0;
}