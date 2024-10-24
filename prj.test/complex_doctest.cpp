// 2024 by Polevoi Dmitry under Unlicense

#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[complex] - ctor") {
  CHECK(Complex() == Complex(0.0, 0.0));
  CHECK(Complex(2.0) == Complex(2.0, 0.0));
}
