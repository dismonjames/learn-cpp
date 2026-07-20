#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      std::cout << ' ';
    }

    std::cout << nums[i];
  }

  std::cout << '\n';
  return 0;
}
