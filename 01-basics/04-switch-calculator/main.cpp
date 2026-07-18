#include <iostream>

int main() {
  int a, b;
  char op;

  std::cin >> a >> op >> b;

  switch (op) {
  case '+':
    std::cout << a + b;
    break;

  case '-':
    std::cout << a - b;
    break;

  case '*':
    std::cout << a * b;
    break;

  case '/':
    if (b == 0) {
      std::cout << "DIVISION_BY_ZERO";
    } else {
      std::cout << a / b;
    }
    break;

  default:
    std::cout << "INVALID_OPERATOR";
    break;
  }
}
