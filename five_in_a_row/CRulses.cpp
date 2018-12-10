#include"CRules.h"
#include"CSubBoard.h"

bool CRules::isValid(CChessBoard & chessboard, CChessPiece piece)
{
	int x = piece.getPosition().getx();
	int y = piece.getPosition().gety();
	bool inboard = (0 <= x <= 14 && 0 <= y <= 14);
	bool nopiece = (chessboard[x][y] == blank);
	if (inboard && nopiece) return true;
	else return false;
}

bool CRules::isForbidden(CChessBoard & chessboard, CChessPiece piece)
{
	if (piece.getType() == white)
		return false;
	else
	{
		CSubBoard boardx(chessboard, piece, row);
		CSubBoard boardy(chessboard, piece, col);
		CSubBoard boardxy(chessboard, piece, x1);
		CSubBoard boardyx(chessboard, piece, x2);
		int fourcase[4];
		fourcase[0] = boardx.getScore();
		fourcase[1] = boardy.getScore();
		fourcase[2] = boardxy.getScore();
		fourcase[3] = boardyx.getScore();
		int cntlive3, cnt4;
		cntlive3 = cnt4 = 0;
		for (int k = 0; k < 4; k++)
		{
			switch (fourcase[k])
			{
			case double4:
				return true;
			case overline:
				return true;
			case live3:
				cntlive3++;
				break;
			case jump3:
				cntlive3++;
				break;
			case live4:
				cnt4++;
				break;
			case die4:
				cnt4++;
				break;
			case lowdie4:
				cnt4++;
				break;
			}
		}

		if (cntlive3 >= 2 || cnt4 >= 2)
			return true;
		else return false;
	}
}

bool CRules::isWin(CChessBoard & chessboard, CChessPiece piece)
{
	if (piece.getType() == white)
	{
		CSubBoard boardx(chessboard, piece, row);
		CSubBoard boardy(chessboard, piece, col);
		CSubBoard boardxy(chessboard, piece, x1);
		CSubBoard boardyx(chessboard, piece, x2);
		int fourcase[4];
		fourcase[0] = boardx.getScore();
		fourcase[1] = boardy.getScore();
		fourcase[2] = boardxy.getScore();
		fourcase[3] = boardyx.getScore();
		int cntwin5, cntoverline;
		cntwin5 = cntoverline = 0;
		for (int k = 0; k < 4; k++)
		{
			switch (fourcase[k])
			{
			case win5:
				cntwin5++;
				break;
			case overline:
				cntoverline++;
				break;
			}
		}

		if (cntwin5 >= 1 || cntoverline >= 1)
			return true;
		else return false;
	}
	else
	{
		CSubBoard boardx(chessboard, piece, row);
		CSubBoard boardy(chessboard, piece, col);
		CSubBoard boardxy(chessboard, piece, x1);
		CSubBoard boardyx(chessboard, piece, x2);
		int fourcase[4];
		fourcase[0] = boardx.getScore();
		fourcase[1] = boardy.getScore();
		fourcase[2] = boardxy.getScore();
		fourcase[3] = boardyx.getScore();
		int cntwin5 = 0;
		for (int k = 0; k < 4; k++)
		{
			if (fourcase[k] == win5)
				cntwin5++;
		}

		if (cntwin5 >= 1)
			return true;
		else return false;
	}
}

bool CRules::isDraw(CChessBoard & chessboard)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (chessboard[i][j] == blank)
				return false;
		}
	}
	return true;
}