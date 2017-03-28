#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

auto calcWind(int dis) -> int {
  auto td = static_cast<double>(dis) / 60.0;
  { // 四捨五入処理
    auto tmp = td * 10.0;
    td = round(tmp) / 10.0;
  }
#define CASE(min, max, w) if (min <= td && max >= td) { return w; }
  CASE( 0.0,  0.2,  0);
  CASE( 0.3,  1.5,  1);
  CASE( 1.6,  3.3,  2);
  CASE( 3.4,  5.4,  3);
  CASE( 5.5,  7.9,  4);
  CASE( 8.0, 10.7,  5);
  CASE(10.8, 13.8,  6);
  CASE(13.9, 17.1,  7);
  CASE(17.2, 20.7,  8);
  CASE(20.8, 24.4,  9);
  CASE(24.5, 28.4, 10);
  CASE(28.5, 32.6, 11);
#undef CASE
  if (td >= 32.7) {
    return 12;
  }
  assert(false);
}

auto calcDir(int deg) -> std::string {
#define CASE(n, s) if (deg >= 3600.0 / 32.0 * static_cast<double>(n - 1) &&\
                       deg <  3600.0 / 32.0 * static_cast<double>(n + 1)) { return s; }
  CASE( 2, "NNE");
  CASE( 4,  "NE");
  CASE( 6, "ENE");
  CASE( 8,   "E");
  CASE(10, "ESE");
  CASE(12,  "SE");
  CASE(14, "SSE");
  CASE(16,   "S");
  CASE(18, "SSW");
  CASE(20,  "SW");
  CASE(22, "WSW");
  CASE(24,   "W");
  CASE(26, "WNW");
  CASE(28,  "NW");
  CASE(30, "NNW");
#undef CASE
  return "N";
}

auto main() -> int {
  auto deg = 0, dis = 0; std::cin >> deg >> dis;
  auto w = calcWind(dis);
  if (w == 0) {
    std::cout << 'C' << ' ' << 0 << std::endl;
    return 0;
  }
  std::cout << calcDir(deg) << ' ' << w << std::endl;
  return 0;
}
