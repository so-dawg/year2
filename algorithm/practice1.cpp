#include <chrono>
#include <thread>
#include <iostream>

using namespace std; 
  
using clk = chrono::high_resolution_clock;

void a1(int arr[],int &n,int index,int value){
  for (int i=n;i>index;--i){
    arr[i]=arr[i-1];
  }
  arr[index]=value;
}
void b1(int arr[],int &n,int value,int capacity){
  for (int i=n+1;i<capacity;--i){
    if (arr[i]<=0){
      arr[i]=value;
    }
  }
}
void c1(int arr[],int &n,int value,int index[]){
  for (int i=0;i<3;++i){
    for (int j=n;j>index[i];--j){
      arr[j]=arr[i-1];
    }
    arr[index[i]]=value;
  }
}


int main(void){
  const int MAX_CAP = 100000;
  int n = 0;
  int arr[MAX_CAP];

   
  auto t0 = clk::now();

  std::this_thread::sleep_for(chrono::seconds(2));
  
  a1(arr,n,0,6);
  n=MAX_CAP/2;
  b1(arr,n,10,MAX_CAP);
  //c1();
  

  auto t1 = clk::now();

  auto time = chrono::duration_cast<chrono::microseconds>(t1-t0);
  cout << "Duration is "<<time.count()<<endl;
  cout << arr[1] << endl;
}
