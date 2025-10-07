#include <chrono>
#include <thread>
#include <iostream>

using namespace std; 
  

using clk = chrono::high_resolution_clock;


int main(void){
  const int MAX_CAP = 100000;
  int n = 0;

   
  auto t0 = clk::now();

  std::this_thread::sleep_for(chrono::seconds(2));


  auto t1 = clk::now();

  auto time = chrono::duration_cast<chrono::microseconds>(t1-t0);
  cout << "Duration is"<<time.count()<<endl;
}
