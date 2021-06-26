#include "pch.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Test1, TestName1) {
	char input[] = "1+1";
	ASSERT_DOUBLE_EQ(2, Obratnaipoliskai(input));
}
TEST(Test2, TestName2) {
	char input[] = "2 + 3";
	ASSERT_DOUBLE_EQ(5, Obratnaipoliskai(input));
}
TEST(Test3, TestName3) {
	char input[] = "(2 * 3) + (4 * 5)";
	ASSERT_DOUBLE_EQ(26, Obratnaipoliskai(input));
}
TEST(Test4, TestName4) {
	char input[] = "2 / (3 - (4 + (5 * 6)))";
	ASSERT_DOUBLE_EQ(0, Obratnaipoliskai(input));
}
TEST(Test5, TestName5) {
	char input[] = "(1+2)*4+3";
	ASSERT_DOUBLE_EQ(15, Obratnaipoliskai(input));
}
TEST(Test6, TestName6) {
	char input[] = "1*2*3*4*5";
	ASSERT_DOUBLE_EQ(120, Obratnaipoliskai(input));
}
TEST(Test7, TestName7) {
	char input[] = "8*(5-6)";
	ASSERT_DOUBLE_EQ(-8, Obratnaipoliskai(input));
}

TEST(Test9, TestName9) {
	char input[] = "1+2+3+4+5+6+7+8+9+0";
	ASSERT_DOUBLE_EQ(45, Obratnaipoliskai(input));
}
TEST(Test10, TestName10) {
	char input[] = "0/8";
	ASSERT_DOUBLE_EQ(0, Obratnaipoliskai(input));
}
TEST(Test11, TestName11) {
	char input[] = "1+2-3+4-5+6-7+8-9+0";
	ASSERT_DOUBLE_EQ(-3, Obratnaipoliskai(input));
}
TEST(Test12, TestName12) {
	char input[] = "(1+3) * (3-2) / (7+3) + (2 + 1)-(4-2)";
	ASSERT_DOUBLE_EQ(1, Obratnaipoliskai(input));
}
TEST(Test13, TestName13) {
	char input[] = "(6+(7-(8*(9/5))))";
	ASSERT_DOUBLE_EQ(5, Obratnaipoliskai(input));
}
TEST(Test14, TestName14) {
	char input[] = "9/(5/2)";
	ASSERT_DOUBLE_EQ(4, Obratnaipoliskai(input));
}

TEST(Tes1t6, TestName16) {
	char input[] = "(1-(2+(2*4)))-(((2*4)+2)-1)";
	ASSERT_DOUBLE_EQ(-18, Obratnaipoliskai(input));
}

TEST(Test18, TestName18) {
	char input[] = "(3+3)+(3-3)+(3*3)+(3/3)";
	ASSERT_DOUBLE_EQ(16, Obratnaipoliskai(input));
}

TEST(Test20, TestName20) {
	char input[] = "9/2/3/1";
	ASSERT_DOUBLE_EQ(1, Obratnaipoliskai(input));
}
TEST(Test21, TestName21) {
	char input[] = "(((1+2)))";
	ASSERT_DOUBLE_EQ(3, Obratnaipoliskai(input));
}
TEST(Test22, TestName22) {
	char input[] = "5";
	ASSERT_DOUBLE_EQ(5, Obratnaipoliskai(input));
}
TEST(Test23, TestName23) {
	char input[] = "  (  ( 2      - 1  )  *6)   ";
	ASSERT_DOUBLE_EQ(6, Obratnaipoliskai(input));
}
TEST(Test24, TestName24) {
	char input[] = "((((((((((((((((((((((((2))))))))))))))))))))))))";
	ASSERT_DOUBLE_EQ(2, Obratnaipoliskai(input));
}
TEST(Test25, TestName25) {
	char input[] = "    8";
	ASSERT_DOUBLE_EQ(8, Obratnaipoliskai(input));
}
TEST(Test26, TestName26) {
	char input[] = "(2*((2*((2)))*2))*2";
	ASSERT_DOUBLE_EQ(32, Obratnaipoliskai(input));
}
TEST(Test27, TestName27) {
	char input[] = "1    ";
	ASSERT_DOUBLE_EQ(1, Obratnaipoliskai(input));
}
TEST(Test28, TestName28) {
	char input[] = "(2-3) + (1-9)";
	ASSERT_DOUBLE_EQ(-9, Obratnaipoliskai(input));
}
TEST(Test29, TestName29) {
	char input[] = "(6-9) - (1-2)";
	ASSERT_DOUBLE_EQ(-2, Obratnaipoliskai(input));
}
TEST(Test30, TestName30) {
	char input[] = "(1-4) * (2-4)";
	ASSERT_DOUBLE_EQ(6, Obratnaipoliskai(input));
}
TEST(Test31, TestName31) {
	char input[] = "(1-4) * (2+4)";
	ASSERT_DOUBLE_EQ(-18, Obratnaipoliskai(input));
}
TEST(Test32, TestName32) {
	char input[] = "(1-9) / (1-3)";
	ASSERT_DOUBLE_EQ(4, Obratnaipoliskai(input));
}
TEST(Test33, TestName33) {
	char input[] = "(1-9) / (1+1)";
	ASSERT_DOUBLE_EQ(-4, Obratnaipoliskai(input));
}
TEST(Test34, TestName34) {
	char input[] = "(1+4) * (2-4)";
	ASSERT_DOUBLE_EQ(-10, Obratnaipoliskai(input));
}
TEST(Test35, TestName35) {
	char input[] = "(1+9) / (1-3)";
	ASSERT_DOUBLE_EQ(-5, Obratnaipoliskai(input));
}
TEST(Test36, TestName36) {
	char input[] = "0";
	ASSERT_DOUBLE_EQ(0, Obratnaipoliskai(input));
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}