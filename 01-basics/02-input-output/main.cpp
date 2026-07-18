#include <iostream>
#include <string>

int main() {
  std::string name;
  std::cout << "Nhập tên: ";
  std::getline(std::cin, name);

  int age;
  std::cout << "Nhập tuổi: ";
  std::cin >> age;

  std::cout << "Xin chào " << name << "!\n";
  std::cout << "Bạn " << age << " tuổi.\n";

  return 0;
}
