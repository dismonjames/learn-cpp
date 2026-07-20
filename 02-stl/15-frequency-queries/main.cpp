#include <iostream>
#include <unordered_map>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::unordered_map<int, int> frequency;

  for (int i = 0; i < n; i++) {
    int value;
    std::cin >> value;

    frequency[value]++;
  }

  int q;
  std::cin >> q;

  while (q--) {
    int query;
    std::cin >> query;

    std::cout << frequency[query] << '\n';
  }

  return 0;
}
