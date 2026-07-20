#include <iostream>
#include <stack>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q;
  std::cin >> q;

  std::stack<int> db;

  while (q--) {
    std::string command;
    std::cin >> command;

    if (command == "PUSH") {
      int value;
      std::cin >> value;
      db.push(value);
    } else if (command == "POP") {
      if (db.empty()) {
        std::cout << "EMPTY" << '\n';
      } else {
        int result = db.top();
        std::cout << result << '\n';
        db.pop();
      }
    } else if (command == "TOP") {
      if (db.empty()) {
        std::cout << "EMPTY" << '\n';
      } else {
        int result = db.top();
        std::cout << result << '\n';
      }
    } else if (command == "SIZE") {
      std::cout << db.size() << '\n';
    } else if (command == "EMPTY") {
      if (db.empty()) {
        std::cout << "YES" << '\n';
      } else {
        std::cout << "NO" << '\n';
      }
    }
  }

  return 0;
}
