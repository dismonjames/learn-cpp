#include <iostream>

bool isPrime(int num) {
  if (num <= 1)
    return false;

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  std::cin >> n;

  int count = 0;

  for (int j = 2; j <= n; j++) {
    if (isPrime(j)) {
      count++;
    }
  }

  std::cout << count << '\n';
  return 0;
}
