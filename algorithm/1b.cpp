#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

using clk = chrono::high_resolution_clock;

void b1(int arr[],int &n,int value,int capacity){
  for (int i=0;i<n;++i){
    if (arr[i]==0){
      arr[i]=value;
      break;
    }
  }
}


int main(void){
  const int MAX_CAP = 100000;
  int n = MAX_CAP/2;
  int arr[MAX_CAP];


  arr[1] = -10;

  auto t0 = clk::now();

  std::this_thread::sleep_for(chrono::seconds(2));

  b1(arr,n,88,MAX_CAP);

  auto t1 = clk::now();

  auto time = chrono::duration_cast<chrono::microseconds>(t1-t0);

  cout << "Duration is " << time.count() << endl;
  cout << arr[0] << endl;

  cout << arr[1] << endl;
}
