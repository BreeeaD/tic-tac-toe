#include "pch.h"
#include "CppUnitTest.h"
#include "../tic-tac-toe/board.hpp"
#include "../tic-tac-toe/point.hpp"
#include "../tic-tac-toe/cell.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
    TEST_CLASS(BoardTests)
    {
    public:

        TEST_METHOD(TestValidPointInsideBoard)
        {
            Board board;
            Point validPoint(1, 1);
            bool isValid = board.Valid(validPoint);
            Assert::IsTrue(isValid);
        }

        TEST_METHOD(TestValidPointOutsideBoard)
        {
            Board board;
            Point invalidPoint(3, 3);
            bool isValid = board.Valid(invalidPoint);
            Assert::IsFalse(isValid);
        }

        TEST_METHOD(TestMarkValidCell)
        {
            Board board;
            Point validPoint(1, 1);
            Cell playerMark = X;
            bool result = board.Mark(validPoint, playerMark);
            Assert::IsTrue(result); 
            Assert::AreEqual(board.ThisCell(validPoint), playerMark);
        }

        TEST_METHOD(TestMarkOccupiedCell)
        {
            Board board;
            Point validPoint(1, 1);
            Cell playerMark = X;
            board.Mark(validPoint, playerMark); 
            bool result = board.Mark(validPoint, O);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestFullBoard)
        {
            Board board;
            board.Mark(Point(0, 0), X);
            board.Mark(Point(0, 1), O);
            board.Mark(Point(0, 2), X);
            board.Mark(Point(1, 0), O);
            board.Mark(Point(1, 1), X);
            board.Mark(Point(1, 2), O);
            board.Mark(Point(2, 0), X);
            board.Mark(Point(2, 1), O);
            board.Mark(Point(2, 2), X);
            bool isFull = board.Full();
            Assert::IsTrue(isFull);
        }

        TEST_METHOD(TestNotFullBoard)
        {
            Board board;
            board.Mark(Point(0, 0), X);
            board.Mark(Point(0, 1), O);
            bool isFull = board.Full();
            Assert::IsFalse(isFull);
        }

        TEST_METHOD(TestRowWin)
        {
            Board board;
            board.Mark(Point(0, 0), X);
            board.Mark(Point(0, 1), X);
            board.Mark(Point(0, 2), X);
            bool hasWon = board.CheckWin(X);
            Assert::IsTrue(hasWon);
        }

        TEST_METHOD(TestColumnWin)
        {
            Board board;
            board.Mark(Point(0, 0), O);
            board.Mark(Point(1, 0), O);
            board.Mark(Point(2, 0), O);
            bool hasWon = board.CheckWin(O);
            Assert::IsTrue(hasWon);
        }

        TEST_METHOD(TestDiagonalWin)
        {
            Board board;
            board.Mark(Point(0, 0), X);
            board.Mark(Point(1, 1), X);
            board.Mark(Point(2, 2), X);
            bool hasWon = board.CheckWin(X);
            Assert::IsTrue(hasWon);
        }
    };
}
