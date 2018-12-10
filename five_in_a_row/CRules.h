#pragma once
#include"CChessBoard.h"
#include"CChessPiece.h"

class CRules
{
public:
	bool isValid(CChessBoard &, CChessPiece);
	bool isForbidden(CChessBoard &, CChessPiece);
	bool isWin(CChessBoard &, CChessPiece);
	bool isDraw(CChessBoard &);
};
