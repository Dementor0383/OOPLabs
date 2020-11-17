#include <iostream>
#include <gtest/gtest.h>
#include "Trit.h"
#include "TritSet.h"

TEST(MemoryTests, ConstructorAllocationTest){
    for(int i = 0; i <= 1000; ++i){
        TritSet setTrits(i);
        size_t allocLength = setTrits.capacity();
        EXPECT_GE(allocLength, i * 2 / 8 / sizeof(uint32));
    }
}

TEST(MemoryTest, UnknownTrit){
    TritSet setTrits(6);
    setTrits[0] = trit::True;
    EXPECT_TRUE(setTrits[6] == trit::Unknown);
}

TEST(MemoryTest, TritValueMemory){
    TritSet setTrits(6);
    setTrits[0] = trit::True;
    setTrits[1] = trit::Unknown;
    setTrits[2] = trit::False;
    setTrits[3] = trit::True;
    setTrits[4] = trit::Unknown;
    setTrits[5] = trit::False;

    EXPECT_TRUE(setTrits[0] == trit::True);
    EXPECT_TRUE(setTrits[1] == trit::Unknown);
    EXPECT_TRUE(setTrits[2] == trit::False);
    EXPECT_TRUE(setTrits[3] == trit::True);
    EXPECT_TRUE(setTrits[4] == trit::Unknown);
    EXPECT_TRUE(setTrits[5] == trit::False);
}

TEST(MemoryTest, ShrinkTest){
    TritSet setTrits(1000);
    setTrits[999] = trit::True;
    setTrits[998] = trit::False;
    setTrits.shrink();
    EXPECT_EQ(setTrits.getTritSize(), 0);
}

TEST(OperationTest, OrTest)
{
    TritSet setA(5);
    TritSet setB(5);

    setA[0] = trit::Unknown;
    setA[1] = trit::Unknown;
    setA[2] = trit::Unknown;
    setA[3] = trit::True;
    setA[4] = trit::False;

    setB[0] = trit::True;
    setB[1] = trit::False;
    setB[2] = trit::Unknown;
    setB[3] = trit::False;
    setB[4] = trit::True;

    TritSet setC = setA | setB;

    EXPECT_TRUE(setC[0] == trit::True);
    EXPECT_TRUE(setC[1] == trit::Unknown);
    EXPECT_TRUE(setC[2] == trit::Unknown);
    EXPECT_TRUE(setC[3] == trit::True);
    EXPECT_TRUE(setC[4] == trit::True);
}

TEST(OperationTest, AndTest)
{
    TritSet setA(5);
    TritSet setB(5);

    setA[0] = trit::Unknown;
    setA[1] = trit::Unknown;
    setA[2] = trit::Unknown;
    setA[3] = trit::True;
    setA[4] = trit::False;

    setB[0] = trit::True;
    setB[1] = trit::False;
    setB[2] = trit::Unknown;
    setB[3] = trit::False;
    setB[4] = trit::True;

    TritSet setC = setA & setB;

    EXPECT_TRUE(setC[0] == trit::Unknown);
    EXPECT_TRUE(setC[1] == trit::False);
    EXPECT_TRUE(setC[2] == trit::Unknown);
    EXPECT_TRUE(setC[3] == trit::False);
    EXPECT_TRUE(setC[4] == trit::False);
}

TEST(OperationTest, NegationTest){
  TritSet setA(3);
  setA[0] = trit::Unknown;
  setA[1] = trit::True;
  setA[2] = trit::False;
  TritSet setC = !setA;
  EXPECT_TRUE(setC[0] == trit::Unknown);
  EXPECT_TRUE(setC[1] == trit::False);
  EXPECT_TRUE(setC[2] == trit::True);
}

TEST(MethodTest, CardinalityTest){
    TritSet setTrits(6);
    setTrits[0] = trit::True;
    setTrits[1] = trit::True;
    setTrits[2] = trit::False;
    setTrits[3] = trit::False;
    setTrits[4] = trit::Unknown;
    setTrits[6] = trit::Unknown;
    EXPECT_EQ(setTrits.cardinality(trit::True), 2);
    EXPECT_EQ(setTrits.cardinality(trit::False), 2);
    EXPECT_EQ(setTrits.cardinality(trit::Unknown), 2);
}

TEST(MethodTest, LogicalLengthTest)
{
    TritSet setTrits(6);
    setTrits[0] = trit::True;
    setTrits[1] = trit::True;
    setTrits[2] = trit::False;
    setTrits[3] = trit::False;
    setTrits[4] = trit::Unknown;
    setTrits[5] = trit::Unknown;

    EXPECT_EQ(setTrits.logicalLength(), 5);
}

TEST(MethodTest, TrimTest)
{
    TritSet set(7);

    set[0] = trit::True;
    set[1] = trit::Unknown;
    set[2] = trit::False;
    set[3] = trit::False;
    set[4] = trit::Unknown;
    set[5] = trit::True;
    set[6] = trit::Unknown;

    set.trim(2);
    EXPECT_TRUE(set[2] == trit::Unknown && set[3] == trit::Unknown && set[4] == trit::Unknown && set[5] == trit::Unknown && set[6] == trit::Unknown);
}