#include "c-echo.h"
#include "c-count.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, Numbers) {
    char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "123456789";
    EXPECT_EQ("123456789", echo(2,test_val));
}

TEST(EchoTest, MoreWords) {
    char* test_val[5]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "computer"; test_val[3] = "science"; test_val[4] = "world";
    EXPECT_EQ("hello computer science world", echo(5,test_val));
}

TEST(EchoTest, SpecialChars) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "Hello"; test_val[2] = "World!";
    EXPECT_EQ("Hello World!", echo(3,test_val));
}

TEST(CountTest, HelloWorld) {
	std::string test_str = "hello world";
	EXPECT_EQ(2, count(test_str));
}

TEST(CountTest, EmptyString) {
	std::string test_str = "";
	EXPECT_EQ(0, count(test_str));
}

TEST(CountTest, ManySpaces) {
	std::string test_str = "  this  string has   weird   spacing";
	EXPECT_EQ(5, count(test_str));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
