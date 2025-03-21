//
// Created by mr on 1/18/24.
//
#include <gtest/gtest.h>
#include "../src/calc.h"

TEST(SumTest, BasicTest) {
    calc* c = new calc();
    EXPECT_EQ(c->sum(1,2), 3);
    delete c;
}