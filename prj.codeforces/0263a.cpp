// 2022 by Polevoy Dmitry
// task source https://codeforces.com/problemset/problem/263/A
// 263A Красивая матрица

#include <iostream>

int main() { 
  int i = 0;
  int v = 0;
  for (; 0 == v; i += 1) {
    std::cin >> v;
  }
  i -= 1;
  int x = i % 5;
  int y = i / 5;
  std::cout << std::abs(x - 2) + std::abs(y - 2);
}