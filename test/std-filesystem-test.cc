// Formatting library for C++ - tests of formatters for standard library types
//
// Copyright (c) 2012 - present, Victor Zverovich
// All rights reserved.
//
// For the license information refer to format.h.

#include "fmt/std.h"
#include "gtest/gtest.h"

TEST(std_filesystem_test, path) {
#ifdef __cpp_lib_filesystem
  EXPECT_EQ(fmt::format("{:8}", std::filesystem::path("foo")), "\"foo\"   ");
  EXPECT_EQ(fmt::format("{}", std::filesystem::path("foo\"bar.txt")),
            "\"foo\\\"bar.txt\"");

#  ifdef _WIN32
  const wchar_t cyrillic_path[] = {
//0x0424, 0x0430, 0x0439, 0x043b, 0x002e, 0x0074, 0x0078, 0x0074, 0
0x424, 0x430, 0x439, 0x43b, 0x2e, 0x74, 0x78, 0x74, 0
  };

  EXPECT_EQ(fmt::format("{}", std::filesystem::path(cyrillic_path)),
            "\"\xd0\xa4\xd0\xb0\xd0\xb9\xd0\xbb.txt\"");
#  endif
#endif
}
