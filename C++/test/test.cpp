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
    friend class Game;
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

TEST_F(GameTest, RollNotInPenaltyBox) {
    setNumberOfPlayers(3);
    game.roll(5);

    // Check the player's new position
    ASSERT_EQ(game.places[game.currentPlayer], 5 % 12);
}

// Test case for roll function when in penalty box and rolling an odd number
TEST_F(GameTest, RollInPenaltyBoxOddRoll) {
    setNumberOfPlayers(3);
    game.inPenaltyBox[game.currentPlayer] = true;
    game.roll(3);

     ASSERT_TRUE(game.isGettingOutOfPenaltyBox);
    ASSERT_EQ(game.places[game.currentPlayer], 3 % 12);
}

TEST_F(GameTest, RollInPenaltyBoxEvenRoll) {
    setNumberOfPlayers(3);
    game.inPenaltyBox[game.currentPlayer] = true;
    game.roll(4);

    ASSERT_FALSE(game.isGettingOutOfPenaltyBox);
    ASSERT_EQ(game.places[game.currentPlayer], 0);  // Position should not change
}


TEST_F(GameTest, WasCorrectlyAnsweredOutput) {
    setNumberOfPlayers(3);
    game.currentPlayer = 0;

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    game.wasCorrectlyAnswered();
    std::string expectedOutput = "Answer was corrent!!!!\nPlayer1 now has 1 Gold Coins.\n";
    ASSERT_EQ(buffer.str(), expectedOutput);

    buffer.str("");
    buffer.clear();

    game.inPenaltyBox[0] = true;
    game.isGettingOutOfPenaltyBox = true;
    game.wasCorrectlyAnswered();
    expectedOutput = "Answer was correct!!!!\nPlayer1 now has 2 Gold Coins.\n";
    ASSERT_EQ(buffer.str(), expectedOutput);

    buffer.str("");
    buffer.clear();

    game.isGettingOutOfPenaltyBox = false;
    game.wasCorrectlyAnswered();
    expectedOutput = "";
    ASSERT_EQ(buffer.str(), expectedOutput);

    std::cout.rdbuf(oldCout);
}




int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
