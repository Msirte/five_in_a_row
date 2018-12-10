#pragma once
#include"CChessBoard.h"

class CDisplay
{
public:
	void showWelcome();
	void showSelectOrder();
	void showChessBoard(CChessBoard &);
	void showWin(int);
	void showInvalid();
	void showForbidden();
	void showDraw();
};