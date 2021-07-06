#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> diff;
  for (int ind=0; ind<nums.size(); ++ind) {
    if (diff.find(nums[ind]) != diff.end()) {
      return {diff[nums[ind]], ind};
    }
    diff[target - nums[ind]] = ind;
  }
}

void printVector(const std::vector<int>& vec) {
  for (auto& el : vec) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

//int main() {
//  std::vector test_case({2, 7, 11, 10});
//  printVector(twoSum(test_case, 9));
//  return 0;
//}
