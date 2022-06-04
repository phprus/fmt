// Formatting library for C++ - tests of formatters for standard library types
//
// Copyright (c) 2012 - present, Victor Zverovich
// All rights reserved.
//
// For the license information refer to format.h.

#include "fmt/std.h"

#include "gtest/gtest.h"

TEST(std_test, thread_id) {
  EXPECT_FALSE(fmt::format("{}", std::this_thread::get_id()).empty());
}
