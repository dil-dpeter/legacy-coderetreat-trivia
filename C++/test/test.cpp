#include "pch.h"
#include <gtest/gtest.h>
#include "..\game.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

class GameTest : public ::testing::Test {
protected:
    Game game;  // Create an instance of Game
    void setNumberOfPlayers(int numPlayers) {

        for (int i = 0; i < numPlayers; ++i) {
            game.add("Player" + std::to_string(i + 1));
        }
    }
};

TEST_F(GameTest, CreateRockQuestion) {
    int index = 5;
    std::string expected = "Rock Question 5";
    std::string result = game.createRockQuestion(index);
    EXPECT_EQ(result, expected);
}

TEST_F(GameTest, IsPlayable) {
   
    setNumberOfPlayers(1);
    EXPECT_FALSE(game.isPlayable());


    setNumberOfPlayers(2);
    EXPECT_TRUE(game.isPlayable());

    setNumberOfPlayers(3);
    EXPECT_TRUE(game.isPlayable());
}
