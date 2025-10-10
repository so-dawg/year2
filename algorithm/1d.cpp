#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

using clk = chrono::high_resolution_clock;

void d2(int arr[],int &n,int value,int index){
  int count = 0;
  for (int i=n;i>0;--i){
    if (arr[i]>0){
      count++;
    }else if (arr[i]==0){
      arr[i] = value;
      break;
    }
  }
  if (count==n){
    
  }
}
