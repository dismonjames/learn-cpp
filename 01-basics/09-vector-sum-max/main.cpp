#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> num(n);

  for (int i = 0; i < n; i++) {
    std::cin >> num[i];
  }

  long long total = 0;
  int max = num[0];

  for (int j = 0; j < n; j++) {
    total += num[j];
    if (max < num[j]) {
      max = num[j];
    }
  }

  std::cout << total << ' ' << max << '\n';
}
