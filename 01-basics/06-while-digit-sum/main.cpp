#include <iostream>

int main() {
  int n;
  int total = 0;

  std::cin >> n;

  while (n > 0) {
    int digit = n % 10;
    n /= 10;
    total += digit;
  }

  std::cout << total << '\n';
}
