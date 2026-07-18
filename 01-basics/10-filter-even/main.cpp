#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> nums(n);
  std::vector<int> evenNum;

  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  }

  for (int num : nums) {
    if (num % 2 == 0) {
      evenNum.push_back(num);
    }
  }

  if (evenNum.size() == 0) {
    std::cout << 0;
    return 0;
  }

  std::cout << evenNum.size() << ' ';

  for (int val : evenNum) {
    std::cout << val << " ";
  }
  std::cout << '\n';
  return 0;
}
