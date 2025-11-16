#include "../utils/Exercise.hpp"
#include <cassert>

int main(){
    Solution ss;
    int expected[] = {0, 1, 0};
    std::vector<std::string> text_tests{
        "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s",
        "1 box has 3 blue 4 red 6 green and 12 yellow marbles",
        "hello world 5 x 5"
    };

    for (int i = 0; i < text_tests.size(); i++) 
    assert(ss.areNumAscending(text_tests[i]) == expected[i]);
}