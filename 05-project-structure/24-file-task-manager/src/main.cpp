#include "task.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string databasePath = "tasks.db";

  if (argc >= 2) {
    databasePath = argv[1];
  }

  std::vector<Task> tasks = loadTasks(databasePath);

  std::string line;

  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      continue;
    }

    if (line == "LIST") {
      printTasks(tasks);

    } else if (line.starts_with("ADD ")) {
      std::string title = line.substr(4);

      if (title.empty()) {
        std::cout << "INVALID_TITLE\n";
        continue;
      }

      int id = nextTaskId(tasks);

      tasks.push_back({
          id,
          title,
          false,
      });

      if (!saveTasks(databasePath, tasks)) {
        std::cout << "SAVE_ERROR\n";
        continue;
      }

      std::cout << "ADDED " << id << '\n';

    } else if (line.starts_with("DONE ")) {
      std::istringstream stream(line.substr(5));

      int id;

      if (!(stream >> id)) {
        std::cout << "INVALID_ID\n";
        continue;
      }

      if (!markTaskDone(tasks, id)) {
        std::cout << "NOT_FOUND\n";
        continue;
      }

      if (!saveTasks(databasePath, tasks)) {
        std::cout << "SAVE_ERROR\n";
        continue;
      }

      std::cout << "DONE " << id << '\n';

    } else if (line == "EXIT") {
      break;

    } else {
      std::cout << "INVALID_COMMAND\n";
    }
  }

  return 0;
}
