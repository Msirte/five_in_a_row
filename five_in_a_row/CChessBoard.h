#pragma once
#include"PieceType.h"
#include"CScene.h"

class CChessBoard
{
public:
	CChessBoard();
	CChessBoard(CChessBoard &);
	void refreshChessBoard(CScene&);
	int getChessBoard(int, int);
	int* operator[](int);
	CChessBoard& operator=(CChessBoard &);
	int getx1();
	int gety1();
	int gettype1();
	int getx2();
	int gety2();
	int gettype2();
private:
	int chessBoard[15][15];
	int x1, y1, type1;
	int x2, y2, type2;
};