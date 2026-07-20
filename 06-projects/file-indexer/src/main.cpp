#include "file_index.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 3 || std::string(argv[1]) != "scan") {
    std::cout << "USAGE: file-indexer scan <directory>\n";
    return 1;
  }

  FileIndex index;

  if (!index.scan(argv[2])) {
    std::cout << "INVALID_PATH\n";
    return 1;
  }

  std::cout << "INDEXED " << index.entries().size() << '\n';

  return 0;
}
