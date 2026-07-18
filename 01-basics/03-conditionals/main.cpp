#include <iostream>

int main() {
  int age;
  std::cin >> age;

  if (age < 0) {
    std::cout << "INVALID";
  } else if (age >= 0 && age <= 12) {
    std::cout << "CHILD";
  } else if (age >= 13 && age <= 17) {
    std::cout << "TEENAGER";
  } else if (age >= 18 && age <= 59) {
    std::cout << "ADULT";
  } else {
    std::cout << "SENIOR";
  }

  return 0;
}
