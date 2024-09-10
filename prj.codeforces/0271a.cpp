// 2021 by Polevoy Dmitry
// task description https://codeforces.com/problemset/problem/271/A
// 271A Красивый год

#include <iostream>

int main() {
  int y = 0;
  std::cin >> y;
  for (int b = y + 1; b < 9999; b += 1) {
    const int d1 = b / 1000;
    const int d2 = (b - 1000 * d1) / 100;
    const int d3 = (b - 1000 * d1 - 100 * d2) / 10;
    const int d4 = b - 1000 * d1 - 100 * d2 - 10 * d3;
    if (d4 != d3 && d4 != d2 && d4 != d1 && d3 != d2 && d3 != d1 && d2 != d1) {
      std::cout << d1 << d2 << d3 << d4;
      break;
    }
  }
}