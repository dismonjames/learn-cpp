#include <iostream>
#include <utility>
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

  int left = 0;
  int right = n - 1;

  while (left < right) {
    std::swap(nums[left], nums[right]);

    left++;
    right--;
  }

  for (int value : nums) {
    std::cout << value << ' ';
  }

  std::cout << '\n';

  return 0;
}
