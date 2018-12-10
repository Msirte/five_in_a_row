#include"CChessBoard.h"

CChessBoard::CChessBoard()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			chessBoard[i][j] = blank;
	}
	x1 = x2 = 0;
	y1 = y2 = 0;
	type1 = type2 = blank;
}

CChessBoard::CChessBoard(CChessBoard & other)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			this->chessBoard[i][j] = other[i][j];
	}
	x1 = other.getx1();
	y1 = other.gety1();
	type1 = other.gettype1();
	x2 = other.getx2();
	y2 = other.gety2();
	type2 = other.gettype2();
}


void CChessBoard::refreshChessBoard(CScene& scene)
{
	x2 = x1;
	y2 = y1;
	type2 = type1;
	x1 = scene.getLastUnit().getPosition().getx();
	y1 = scene.getLastUnit().getPosition().gety();
	type1 = scene.getLastUnit().getType();
	chessBoard[x1][y1] = type1;
}

int CChessBoard::getChessBoard(int i, int j)
{
	return chessBoard[i][j];
}

int* CChessBoard::operator[](int n)
{
	return &chessBoard[n][0];
}

CChessBoard& CChessBoard::operator=(CChessBoard & other)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
			this->chessBoard[i][j] = other[i][j];
	}
	x1 = other.getx1();
	y1 = other.gety1();
	type1 = other.gettype1();
	x2 = other.getx2();
	y2 = other.gety2();
	type2 = other.gettype2();
	return *this;
}

int CChessBoard::getx1()
{
	return x1;
}

int CChessBoard::gety1()
{
	return y1;
}

int CChessBoard::gettype1()
{
	return type1;
}

int CChessBoard::getx2()
{
	return x2;
}

int CChessBoard::gety2()
{
	return y2;
}

int CChessBoard::gettype2()
{
	return type2;
}
