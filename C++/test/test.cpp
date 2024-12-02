#include "pch.h"
#include "..\game.h"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

class GameTest : public ::testing::Test {
protected:
    Game game;  // Create an instance of Game
};

TEST_F(GameTest, CreateRockQuestion) {
    int index = 5;
    std::string expected = "Rock Question 5";
    std::string result = game.createRockQuestion(index);
    EXPECT_EQ(result, expected);
}