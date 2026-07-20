#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using Task = std::pair<int, std::string>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  auto compare = [](const Task &a, const Task &b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }

    return a.second > b.second;
  };

  std::priority_queue<Task, std::vector<Task>, decltype(compare)> tasks(
      compare);

  int q;
  std::cin >> q;

  while (q--) {
    std::string command;
    std::cin >> command;

    if (command == "ADD") {
      int priority;
      std::string name;

      std::cin >> priority >> name;
      tasks.push({priority, name});

    } else if (command == "RUN") {
      if (tasks.empty()) {
        std::cout << "EMPTY\n";
        continue;
      }

      Task task = tasks.top();
      tasks.pop();

      std::cout << task.second << ' ' << task.first << '\n';

    } else if (command == "PEEK") {
      if (tasks.empty()) {
        std::cout << "EMPTY\n";
        continue;
      }

      const Task &task = tasks.top();
      std::cout << task.second << ' ' << task.first << '\n';

    } else if (command == "SIZE") {
      std::cout << tasks.size() << '\n';

    } else if (command == "EMPTY") {
      std::cout << (tasks.empty() ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
