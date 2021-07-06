#include <iostream>
#include <map>
#include <vector>
#include <utility>

bool comp(std::pair<int, int>& a, std::pair<int, int>& b) {
  return a.second > b.second;
}

int minSetSize(std::vector<int>& arr) {
  size_t amount = arr.size();
  std::map<int, int> counter;
  for (auto& el : arr) {
    ++counter[el];
  }

  std::vector<std::pair<int, int>> freq;
  for (auto & it : counter) {
    freq.emplace_back(it.first, it.second);
  }
  std::sort(freq.begin(), freq.end(), comp);

  std::vector<int> deleted_items;
  size_t deleted_items_count = 0;
  for (auto& el : freq) {
    if (deleted_items_count >= amount / 2) {
      break;
    }
    deleted_items.insert(deleted_items.begin(), el.first);
    deleted_items_count += el.second;
  }

  return static_cast<int> (deleted_items.size());
}

int main() {
//  std::cout << minSetSize({3,3,3,3,5,5,5,2,2,7}) << std::endl;
//  std::cout << minSetSize({7,7,7,7,7,7}) << std::endl;
//  std::cout << minSetSize({1,2,3,4,5,6,7,8,9,10}) << std::endl;
//  std::cout << minSetSize({1000,1000,3,7}) << std::endl;

  return 0;
}
