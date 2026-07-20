#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string text;
  std::cin >> text;

  int frequency[26] = {};

  for (char ch : text) {
    frequency[ch - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (frequency[i] > 0) {
      char ch = static_cast<char>('a' + i);
      std::cout << ch << ' ' << frequency[i] << '\n';
    }
  }

  return 0;
}
