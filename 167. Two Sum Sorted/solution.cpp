#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSumSort(std::vector<int>& nums, int target) {
  int i = 0, j = static_cast<int>(nums.size()) - 1;
  while (nums[i] + nums[j] != target) {
    if (nums[i] + nums[j] > target) {
      --j;
    } else {
      ++i;
    }
  }
  return {i, j};
}
