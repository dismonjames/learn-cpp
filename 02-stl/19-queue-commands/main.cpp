#include <iostream>
#include <queue>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  std::cin >> q;

  std::queue<int> HangCho;

  while (q--) {
    std::string command;
    std::cin >> command;

    if (command == "PUSH") {
      int value;
      std::cin >> value;
      HangCho.push(value);
    } else if (command == "POP") {
      if (HangCho.empty()) {
        std::cout << "EMPTY" << '\n';
      } else {
        std::cout << HangCho.front() << '\n';
        HangCho.pop();
      }
    } else if (command == "FRONT") {
      if (HangCho.empty()) {
        std::cout << "EMPTY" << '\n';
      } else {
        std::cout << HangCho.front() << '\n';
      }
    } else if (command == "BACK") {
      if (HangCho.empty()) {
        std::cout << "EMPTY" << '\n';
      } else {
        std::cout << HangCho.back() << '\n';
      }
    } else if (command == "EMPTY") {
      if (HangCho.empty()) {
        std::cout << "YES" << '\n';
      } else {
        std::cout << "NO" << '\n';
      }
    } else if (command == "SIZE")
      std::cout << HangCho.size() << '\n';
  }

  return 0;
}
