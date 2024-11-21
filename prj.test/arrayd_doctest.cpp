// 2024 by Polevoi Dmitry under Unlicense

#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[arrayd] - ctor") {
  CHECK(ArrayD().Size() == 0);
}
