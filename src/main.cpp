#include <iostream>
#include <memory>

int main() {
  const int num = 5;
  auto pointer = std::make_shared<int>(num);

  std::cout << *pointer << std::endl;
}
