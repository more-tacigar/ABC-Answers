#include <iostream>
#include <string>

bool array[24 * 12] = {false};

auto timeToIndex(const std::string& time, bool up) -> int {
  auto hs = time.substr(0, 2);
  auto ms = time.substr(2, 2);
  auto hi = std::stoi(hs);
  auto mi = std::stoi(ms);
  auto index = 0;
  index += hi * 12;
  if (up) {
    if (mi % 5 != 0) {
      index += mi / 5 + 1;
    } else {
      index += mi / 5;
    }
  } else {
    index += mi / 5;
  }
  return index;
}

auto indexToTime(int index) -> std::string {
  auto hi = index / 12;
  auto mi = index % 12;
  auto hs = std::to_string(hi);
  auto ms = std::to_string(mi * 5);
  if (hs.size() == 1) {
    hs = "0" + hs;
  }
  if (ms.size() == 1) {
    ms = "0" + ms;
  }
  return hs + ms;
}

auto main() -> int {
  auto N = 0; std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::string tmp; std::cin >> tmp;
    auto bt = tmp.substr(0, 4);
    auto et = tmp.substr(5, 4);
    auto bi = timeToIndex(bt, false);
    auto ei = timeToIndex(et, true);
    for (int j = bi; j < ei; j++) {
      array[j] = true;
    }
  }
  for (int i = 0; i < 24 * 12; i++) {
    if (array[i]) {
      auto bs = indexToTime(i);
      do i++; while(array[i]);
      auto es = indexToTime(i);
      std::cout << bs << '-' << es << std::endl;
    }
  }
}
