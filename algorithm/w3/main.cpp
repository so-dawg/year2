#include "utils/Exercise.hpp"

using namespace std;

int main(){
    Solution solution;
    string sentence = "Hello, world 12 35 697";

    if (solution.areNumAscending(sentence)){
      cout << "Happy coding!" << endl;
    }else {
      cout << "Not happy coding" << endl;
    }

    return 0;
}
