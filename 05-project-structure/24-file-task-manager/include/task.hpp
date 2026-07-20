#pragma once

#include <string>
#include <vector>

struct Task {
  int id;
  std::string title;
  bool done;
};

std::vector<Task> loadTasks(const std::string &path);

bool saveTasks(const std::string &path, const std::vector<Task> &tasks);

int nextTaskId(const std::vector<Task> &tasks);

bool markTaskDone(std::vector<Task> &tasks, int id);

void printTasks(const std::vector<Task> &tasks);
