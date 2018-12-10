#include"CAI.h"
#include"CChessPiece.h"
#include"CSubBoard.h"
#include"CRules.h"

CAI::CAI(int n) : CPlayer(n)
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
		{
			score[i][j] = 0;
			loss[i][j] = 0;
		}
}

CAI::CAI(int num, int type) : CPlayer(num, type)
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
		{
			score[i][j] = 0;
			loss[i][j] = 0;
		}
}

CChessPiece CAI::nextMove(CPoint<int> pos)
{
	CChessPiece piece(this->getNum(), this->getType(), pos);
	return piece;
}

CPoint<int> CAI::calculate(CChessBoard chessboard)
{
	CRules judge;
	int attackx, attacky, defendx, defendy, maxgain, maxloss;
	attackx = attacky = defendx = defendy = 7;
	maxgain = maxloss = 1;
	int oppositenum, oppositetype;
	if (this->getNum() == 1)
		oppositenum = 2;
	else oppositenum = 1;

	if (this->getType() == black)
		oppositetype = white;
	else oppositetype = black;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			CPoint<int> pos(i, j);
			CChessPiece piece(this->getNum(), this->getType(), pos);
			if (chessboard[i][j] != blank || judge.isForbidden(chessboard, piece))
				score[i][j] = -1;
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
				int cntdouble4, cntoverline, cntwin5, cntlive4, cntnothreat, cntdie4, cntdie3, cntlowdie4, cntlive3, cntlive2, cntjump3, cntdie2, cntlowlive2;
				cntdouble4 = cntoverline = cntwin5 = cntlive4 = cntnothreat = cntdie4 = cntdie3 = cntlowdie4 = cntlive3 = cntlive2 = cntjump3 = cntdie2 = cntlowlive2 = 0;

				for (int k = 0; k < 4; k++)
				{
					switch (fourcase[k])
					{
					case double4:
						cntdouble4++;
						break;
					case overline:
						cntoverline++;
						break;
					case win5:
						cntwin5++;
						break;
					case live4:
						cntlive4++;
						break;
					case nothreat:
						cntnothreat++;
						break;
					case die4:
						cntdie4++;
						break;
					case die3:
						cntdie3++;
						break;
					case lowdie4:
						cntlowdie4++;
						break;
					case live3:
						cntlive3++;
						break;
					case live2:
						cntlive2++;
						break;
					case jump3:
						cntjump3++;
						break;
					case die2:
						cntdie2++;
						break;
					case lowlive2:
						cntlowlive2++;
						break;
					}
				}

				if (cntoverline >= 1)
					score[i][j] = 100000;
				else if (cntwin5 >= 1 || cntdouble4 >= 1)
					score[i][j] = 100000;
				else if (cntlive4 >= 1 || cntdie4 >= 2 || (cntdie4 >= 1 && cntlive3 >= 1))
					score[i][j] = 10000;
				else if (cntlive3 >= 2)
					score[i][j] = 5000;
				else if (cntdie3 >= 1 && cntlive3 >= 1)
					score[i][j] = 1000;
				else if (cntdie4 >= 1)
					score[i][j] = 500;
				else if (cntlowdie4 >= 1)
					score[i][j] = 400;
				else if (cntlive3 >= 1)
					score[i][j] = 100;
				else if (cntjump3 >= 1)
					score[i][j] = 90;
				else if (cntlive2 >= 2)
					score[i][j] = 50;
				else if (cntlive2 >= 1)
					score[i][j] = 10;
				else if (cntlowlive2 >= 1)
					score[i][j] = 9;
				else if (cntdie3 >= 1)
					score[i][j] = 5;
				else if (cntdie2 >= 1)
					score[i][j] = 2;
				else score[i][j] = 1;
			}

			if (maxgain < score[i][j])
			{
				attackx = i;
				attacky = j;
				maxgain = score[i][j];
			}
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			CPoint<int> pos(i, j);
			CChessPiece piece(oppositenum, oppositetype, pos);
			if (chessboard[i][j] != blank || judge.isForbidden(chessboard, piece))
				loss[i][j] = 0;
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
				int cntdouble4, cntoverline, cntwin5, cntlive4, cntnothreat, cntdie4, cntdie3, cntlowdie4, cntlive3, cntlive2, cntjump3, cntdie2, cntlowlive2;
				cntdouble4 = cntoverline = cntwin5 = cntlive4 = cntnothreat = cntdie4 = cntdie3 = cntlowdie4 = cntlive3 = cntlive2 = cntjump3 = cntdie2 = cntlowlive2 = 0;

				for (int k = 0; k < 4; k++)
				{
					switch (fourcase[k])
					{
					case double4:
						cntdouble4++;
						break;
					case overline:
						cntoverline++;
						break;
					case win5:
						cntwin5++;
						break;
					case live4:
						cntlive4++;
						break;
					case nothreat:
						cntnothreat++;
						break;
					case die4:
						cntdie4++;
						break;
					case die3:
						cntdie3++;
						break;
					case lowdie4:
						cntlowdie4++;
						break;
					case live3:
						cntlive3++;
						break;
					case live2:
						cntlive2++;
						break;
					case jump3:
						cntjump3++;
						break;
					case die2:
						cntdie2++;
						break;
					case lowlive2:
						cntlowlive2++;
						break;
					}
				}

				if (cntoverline >= 1)
					loss[i][j] = 100000;
				else if (cntwin5 >= 1 || cntdouble4 >= 1)
					loss[i][j] = 100000;
				else if (cntlive4 >= 1 || cntdie4 >= 2 || (cntdie4 >= 1 && cntlive3 >= 1))
					loss[i][j] = 10000;
				else if (cntlive3 >= 2)
					loss[i][j] = 5000;
				else if (cntdie3 >= 1 && cntlive3 >= 1)
					loss[i][j] = 1000;
				else if (cntdie4 >= 1)
					loss[i][j] = 500;
				else if (cntlowdie4 >= 1)
					loss[i][j] = 400;
				else if (cntlive3 >= 1)
					loss[i][j] = 100;
				else if (cntjump3 >= 1)
					loss[i][j] = 90;
				else if (cntlive2 >= 2)
					loss[i][j] = 50;
				else if (cntlive2 >= 1)
					loss[i][j] = 10;
				else if (cntlowlive2 >= 1)
					loss[i][j] = 9;
				else if (cntdie3 >= 1)
					loss[i][j] = 5;
				else if (cntdie2 >= 1)
					loss[i][j] = 2;
				else loss[i][j] = 1;
			}

			if (maxloss < loss[i][j])
			{
				defendx = i;
				defendy = j;
				maxloss = loss[i][j];
			}
		}
	}

	if (maxgain >= maxloss)
	{
		CPoint<int> point(attackx, attacky);
		return point;
	}
	else
	{
		CPoint<int> point(defendx, defendy);
		return point;
	}
}
