#include <gtest/gtest.h>
#include "switch_lib.hpp"

TEST(SWITCH_LIB, ADD_FUNCTION) {

    EXPECT_EQ( add(1, 2), 3);
}
