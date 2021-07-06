#include <iostream>
#include <string>

int myAtoi(std::string str) {
  int number = 0;
  bool is_beginning = true;
  bool is_negative = false;

  for (char ch : str) {
    if (is_beginning && ch == ' ') {
      continue;
    } else if (is_beginning && ch == '+') {
      is_beginning = false;
    } else if (is_beginning && ch == '-') {
      is_beginning = false;
      is_negative = true;
    } else if (!std::isdigit(ch)) {
      break;
    } else {
      is_beginning = false;
      int sign_number = is_negative ? number*(-1) : number;
      if (sign_number > std::numeric_limits<int>::max() / 10 ||
          (sign_number == std::numeric_limits<int>::max() / 10 && (ch - '0') > 7)) {
        return std::numeric_limits<int>::max();
      }
      if (sign_number < std::numeric_limits<int>::min() / 10 ||
          (sign_number == std::numeric_limits<int>::min() / 10 && (ch - '0') > 8)) {
        return std::numeric_limits<int>::min();
      }
      number *= 10;
      number += (ch - '0');
    }
  }

  number = is_negative ? number*(-1) : number;
  return number;
}

//int main() {
//  std::cout << myAtoi("42") << std::endl;
//  std::cout << myAtoi("   -42") << std::endl;
//  std::cout << myAtoi("4193 with words") << std::endl;
//  std::cout << myAtoi("words and 987") << std::endl;
//  std::cout << myAtoi("-91283472332") << std::endl;
//  std::cout << myAtoi("-2147483647") << std::endl;
//  std::cout << myAtoi("  -0012a42") << std::endl;
//  std::cout << myAtoi("   +-42") << std::endl;
//}
