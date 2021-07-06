#include <iostream>
#include <limits>

int reverse(int x) {
  int new_val = 0;
  while (x != 0) {
    int resid = x % 10;
    x /= 10;
    if (new_val > std::numeric_limits<int>::max() / 10 ||
        (new_val == std::numeric_limits<int>::max() / 10 && resid >= 7)) {
      return 0;
    } else {
      new_val *= 10;
      new_val += resid;
    }
  }

  return new_val;
}

//int main() {
//  std::cout << reverse(123) <<std::endl;
//  std::cout << reverse(-10) <<std::endl;
//  std::cout << reverse(2147483647) <<std::endl;
//  std::cout << reverse(2100000008) <<std::endl;
//  return 0;
//}
