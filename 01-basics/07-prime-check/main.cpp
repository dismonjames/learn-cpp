#include <iostream>

int main() {
  int n;
  std::cin >> n;

  bool isPrime = n > 1;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      isPrime = false;
      break;
    }
  }

  if (isPrime) {
    std::cout << "PRIME" << '\n';
  } else {
    std::cout << "NOT_PRIME" << '\n';
  }

  return 0;
}
