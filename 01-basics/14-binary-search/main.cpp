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

  int target;
  std::cin >> target;

  int left = 0;
  int right = n - 1;
  int ans = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      ans = mid;
      break;
    }

    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  std::cout << ans << '\n';
  return 0;
}
