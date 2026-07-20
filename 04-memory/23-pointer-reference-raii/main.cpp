#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Student {
private:
  std::string name_;
  int score_;

public:
  Student(std::string name, int score)
      : name_(std::move(name)), score_(std::clamp(score, 0, 100)) {}

  void addScore(int amount) { score_ = std::clamp(score_ + amount, 0, 100); }

  const std::string &name() const { return name_; }

  int score() const { return score_; }
};

// Reference: dùng object gốc, không copy.
void addBonus(Student &student, int bonus) { student.addScore(bonus); }

// const reference: không copy và không được sửa object.
void printStudent(const Student &student) {
  std::cout << student.name() << ' ' << student.score() << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string name;
  int score;
  int bonus;

  std::cin >> name >> score >> bonus;

  // Object được tạo trên heap.
  // unique_ptr sở hữu object và tự giải phóng khi hết scope.
  auto student = std::make_unique<Student>(std::move(name), score);

  // *student lấy object mà pointer đang trỏ tới.
  addBonus(*student, bonus);

  printStudent(*student);

  // Raw pointer chỉ mượn object, không sở hữu.
  Student *view = student.get();

  // Pointer dùng -> để truy cập method.
  std::cout << view->name() << " has " << view->score() << " points\n";

  return 0;
}
