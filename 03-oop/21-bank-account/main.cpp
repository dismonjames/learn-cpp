#include <iostream>
#include <string>

class BankAccount {
private:
  std::string owner;
  long long balance;

public:
  BankAccount(const std::string &ownerName, long long initialBalance)
      : owner(ownerName), balance(initialBalance) {}

  bool deposit(long long amount) {
    if (amount <= 0) {
      return false;
    }

    balance += amount;
    return true;
  }

  bool withdraw(long long amount) {
    if (amount <= 0 || amount > balance) {
      return false;
    }

    balance -= amount;
    return true;
  }

  long long getBalance() const { return balance; }

  const std::string &getOwner() const { return owner; }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string owner;
  long long initialBalance;
  int q;

  std::cin >> owner >> initialBalance >> q;

  BankAccount account(owner, initialBalance);

  while (q--) {
    std::string command;
    std::cin >> command;

    if (command == "DEPOSIT") {
      long long amount;
      std::cin >> amount;

      if (account.deposit(amount)) {
        std::cout << "OK\n";
      } else {
        std::cout << "INVALID_AMOUNT\n";
      }

    } else if (command == "WITHDRAW") {
      long long amount;
      std::cin >> amount;

      if (account.withdraw(amount)) {
        std::cout << "OK\n";
      } else {
        std::cout << "FAILED\n";
      }

    } else if (command == "BALANCE") {
      std::cout << account.getBalance() << '\n';

    } else if (command == "OWNER") {
      std::cout << account.getOwner() << '\n';
    }
  }

  return 0;
}
