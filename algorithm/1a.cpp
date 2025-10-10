#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

using clk=chrono::high_resolution_clock;

void a1(int arr[],int &n,int index,int value){
  for (int i=n;i>index;--i){
    arr[i]=arr[i-1];
  }
  arr[index]=value;
}

int main(void){

  const int MAX_CAP = 100000;
  int n=0;
  int arr[MAX_CAP];

  auto t0 = clk::now();

  std::this_thread::sleep_for(chrono::seconds(2));

  a1(arr,n,0,99);

  auto t1 = clk::now();

  auto time = chrono::duration_cast<chrono::microseconds>(t1-t0);
  cout << "Duration is " << time.count() << endl;
  cout << arr[0] << endl;

}
