#include <iostream>
#include <string>
#include <vector>

class Solution{

public:
    bool areNumAscending(std::string s){
      int lastNum = -1;
      size_t pos = 0;
      while (pos < s.length()) {
          size_t next_space = s.find(' ', pos);
          if (next_space == std::string::npos) {
              next_space = s.length();
          }
          std::string word = s.substr(pos, next_space - pos);

          if (!word.empty() && std::isdigit(word[0])) {
              int currentNum = std::stoi(word);
              if (lastNum >= currentNum) {
                  return false;
              }
              lastNum = currentNum;
          }
          pos = next_space + 1;
      }
      return true;
    }
};
