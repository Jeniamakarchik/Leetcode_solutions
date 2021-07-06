#include <unordered_set>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool checkSubTree(TreeNode* root, int k, std::unordered_set<int>& diff) {
  if (root == nullptr) {
    return false;
  }
  if (diff.find(root->val) != diff.end()) {
    return true;
  }

  diff.insert(k - root->val);
  return checkSubTree(root->left, k, diff) || checkSubTree(root->right, k, diff);
}

bool findTarget(TreeNode* root, int k) {
  std::unordered_set<int> diff;
  return checkSubTree(root, k, diff);
}

//int main() {
//  auto* left = new TreeNode(1);
//  auto* right = new TreeNode(3);
//  auto* root = new TreeNode(2, left, right);
//
//  if (findTarget(root, 4)) {
//    std::cout << "True" << std::endl;
//  } else {
//    std::cout << "False" << std::endl;
//  }
//
//  return 0;
//}
