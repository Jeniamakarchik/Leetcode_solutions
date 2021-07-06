#include <algorithm>
#include <iostream>
#include <vector>

int BinarySearch(std::vector<int>& arr, int l_border, int r_border, int x) {
  int idx, middle = (l_border + r_border) / 2;
  if (l_border + 1 == r_border || arr[middle] == x) {
    idx =  middle;
  } else if (arr[middle] > x) {
    idx = BinarySearch(arr, l_border, middle, x);
  } else if (arr[middle] < x) {
    idx = BinarySearch(arr, middle, r_border, x);
  }
  return idx;
}

std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
  std::vector<int> neighbours;
  if (x < arr[0]) {
    copy(arr.begin(), arr.begin() + k, back_inserter(neighbours));
  } else if (x > arr[arr.size() - 1]) {
    copy(arr.end() - k, arr.end(), back_inserter(neighbours));
  } else {
    int idx = BinarySearch(arr, 0, arr.size() - 1, x);
    int l_border = std::max(0, idx - k);
    int r_border = std::min(static_cast<int> (arr.size()), idx + k + 1
    );

    copy(arr.begin() + l_border, arr.begin() + r_border, back_inserter(neighbours));

    while (neighbours.size() > k) {
      if (abs(neighbours[0] - x) > abs(neighbours[neighbours.size() - 1] - x)) {
        neighbours.erase(neighbours.begin());
      } else {
        neighbours.pop_back();
      }
    }
  }

  return neighbours;
}

void PrintVector(const std::vector<int>& arr){
  for (auto& el : arr) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> arr({1, 2, 3, 4, 5});
  PrintVector(findClosestElements(arr, 4, 6));
  PrintVector(findClosestElements(arr, 4, 0));
  PrintVector(findClosestElements(arr, 4, 3));

  std::vector<int> one({1, 1, 1, 10, 10, 10});
  PrintVector(findClosestElements(one, 1, 9));

  std::vector<int> equal({1, 1, 1, 1, 1, 1});
  PrintVector(findClosestElements(equal, 2, 1));
  return 0;
}
