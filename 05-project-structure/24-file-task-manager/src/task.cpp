#include "task.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<Task> loadTasks(const std::string &path) {
  std::ifstream file(path);

  if (!file) {
    return {};
  }

  std::vector<Task> tasks;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream stream(line);

    std::string idText;
    std::string doneText;
    std::string title;

    if (!std::getline(stream, idText, '|')) {
      continue;
    }

    if (!std::getline(stream, doneText, '|')) {
      continue;
    }

    if (!std::getline(stream, title)) {
      continue;
    }

    try {
      int id = std::stoi(idText);
      bool done = doneText == "1";

      tasks.push_back({id, title, done});
    } catch (...) {
      // Bỏ qua dòng dữ liệu bị hỏng.
    }
  }

  return tasks;
}

bool saveTasks(const std::string &path, const std::vector<Task> &tasks) {
  std::ofstream file(path);

  if (!file) {
    return false;
  }

  for (const Task &task : tasks) {
    file << task.id << '|' << (task.done ? 1 : 0) << '|' << task.title << '\n';
  }

  return true;
}

int nextTaskId(const std::vector<Task> &tasks) {
  int maximumId = 0;

  for (const Task &task : tasks) {
    maximumId = std::max(maximumId, task.id);
  }

  return maximumId + 1;
}

bool markTaskDone(std::vector<Task> &tasks, int id) {
  for (Task &task : tasks) {
    if (task.id == id) {
      task.done = true;
      return true;
    }
  }

  return false;
}

void printTasks(const std::vector<Task> &tasks) {
  if (tasks.empty()) {
    std::cout << "EMPTY\n";
    return;
  }

  for (const Task &task : tasks) {
    std::cout << task.id << " [" << (task.done ? 'x' : ' ') << "] "
              << task.title << '\n';
  }
}
