#include <iostream>

auto main() -> int {
  auto dm = 0;
  std::cin >> dm;
  auto dk = static_cast<float>(dm) / 1000.0;
  if (dk < 0.1) {
    std::cout << "00" << std::endl;
  } else if (dk >= 0.1 && dk <= 5) {
    auto t = dk * 10;
    if (t < 10) {
      std::cout << '0' << static_cast<int>(t) << std::endl;
    } else {
      std::cout << static_cast<int>(t) << std::endl;
    }
  } else if (dk >= 6 && dk <= 30) {
    std::cout << static_cast<int>(dk) + 50 << std::endl;
  } else if (dk >= 35 && dk <= 70) {
    std::cout << (static_cast<int>(dk) - 30) / 5 + 80 << std::endl;
  } else if (dk > 70) {
    std::cout << "89" << std::endl;
  }
}
