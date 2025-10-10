#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

using clk = chrono::high_resolution_clock;

void c1(int  arr[],int &n,int value[],int index[]){
  for (int i=0;i<3;++i){
    for (int j=n;j>index[i];--j){
      arr[j] = arr[j-1];
    }
    arr[index[i]] = value[i];
  }
}
int main(void) {
  const int MAX_CAP = 100000;
  int n = MAX_CAP/2;
  int arr[MAX_CAP];
  int index[3] = {0,n/2,n};
  int insert[3] = {87,90,40};

  auto t0 = clk::now();

  std::this_thread::sleep_for(chrono::seconds(1));

  c1(arr,n,insert,index);

  auto t1 = clk::now();

  auto time = chrono::duration_cast<chrono::microseconds>(t1-t0);
  cout << "Duartion is " << time.count() << endl;
  cout << arr[0] << "\n";
  cout << arr[n/2] << "\n";
  cout << arr[n] << "\n";
}
