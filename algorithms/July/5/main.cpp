#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
  size_t m = mat.size();
  size_t n = mat[0].size();

  if (m * n != r * c) {
    return mat;
  }

  std::vector<std::vector<int>> new_mat(r, std::vector<int>(c, 0)) ;

  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      size_t flat_idx = i * n + j;
      new_mat[flat_idx / c][flat_idx % c] = mat[i][j];
    }
  }

  return new_mat;
}

int main() {
  std::vector<std::vector<int>> mat = {{1, 2}, {3, 4}};
  matrixReshape(mat, 1, 4);
  return 0;
}
