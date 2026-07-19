#include <iostream>
#include <string>

bool isPalindrome(const std::string &text) {
  int left = 0;
  int right = static_cast<int>(text.size()) - 1;
  while (left < right) {
    if (text[left] != text[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string text;
  std::cin >> text;

  if (isPalindrome(text)) {
    std::cout << "PALINDROME\n";
  } else {
    std::cout << "NOT_PALINDROME\n";
  }

  return 0;
}
