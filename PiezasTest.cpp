/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck) {
	ASSERT_TRUE(true);
}

TEST(PiezasTest, buildPiezas) {
	Piezas TP;
	ASSERT_TRUE(true);
}

TEST(PiezasTest, DropPiece) {
	Piezas TP;
	TP.dropPiece(0);
	ASSERT_EQ(TP.pieceAt(0,0), X);
}

TEST(PiezasTest, resetFunctionality) {
	Piezas TP;
	TP.dropPiece(0);
	TP.reset();
	ASSERT_EQ(TP.pieceAt(0,0), Blank);
	ASSERT_EQ(TP.gameState(), Invalid);
}

TEST(PiezasTest, changePlayer) {
	Piezas TP;
	TP.dropPiece(0);
	ASSERT_EQ(TP.pieceAt(0,0), X);
	TP.dropPiece(0);
	ASSERT_EQ(TP.pieceAt(1,0), O);
}

TEST(PiezasTest, OutOfBoundsColumn) {
	Piezas TP;
	ASSERT_EQ(TP.dropPiece(5), Invalid);
	ASSERT_EQ(TP.dropPiece(0), O);
	ASSERT_EQ(TP.pieceAt(0,0), O);
}

TEST(PiezasTest, TieHorizontalGame) {
	Piezas TP;
	TP.dropPiece(0);
	TP.dropPiece(0);
	TP.dropPiece(1);
	TP.dropPiece(1);
	TP.dropPiece(2);
	TP.dropPiece(2);
	TP.dropPiece(3);
	TP.dropPiece(3);
	TP.dropPiece(0);
	TP.dropPiece(1);
	TP.dropPiece(2);
	TP.dropPiece(3);
	ASSERT_EQ(TP.gameState(), Blank);
}

TEST(PiezasTest, TieVerticalGame) {
	Piezas TP;
	TP.dropPiece(0);
	TP.dropPiece(1);
	TP.dropPiece(2);
	TP.dropPiece(3);
	TP.dropPiece(0);
	TP.dropPiece(1);
	TP.dropPiece(2);
	TP.dropPiece(3);
	TP.dropPiece(0);
	TP.dropPiece(1);
	TP.dropPiece(2);
	TP.dropPiece(3);
	ASSERT_EQ(TP.gameState(), Blank);
}
