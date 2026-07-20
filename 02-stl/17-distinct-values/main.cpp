#include <iostream>
#include <set>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::set<int> values;

  int n;
  int input = 0;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> input;
    values.insert(input);
  }

  std::cout << values.size() << '\n';
  for (int value : values) {
    std::cout << value << ' ';
  }
  std::cout << '\n';
  return 0;
}
