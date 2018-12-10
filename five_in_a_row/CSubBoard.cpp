#include"CSubBoard.h"

CSubBoard::CSubBoard(CChessBoard & chessboard, CChessPiece piece, direction dir)
{
	int x = piece.getPosition().getx();
	int y = piece.getPosition().gety();
	int type = piece.getType();
	int opponent;
	if (type == black)
		opponent = white;
	else opponent = black;
	for (int i = 0; i < 9; i++)
		board[i] = opponent;
	int left, right, up, down;
	left = right = x;
	up = down = y;
	switch (dir)
	{
	case row:
		while (left >= 0 && left >= x - 4)
		{
			board[left - x + 4] = chessboard[left][y];
			left--;
		}
		while (right <= 14 && right <= x + 4)
		{
			board[right - x + 4] = chessboard[right][y];
			right++;
		}
		break;
	case col:
		while (up >= 0 && up >= y - 4)
		{
			board[up - y + 4] = chessboard[x][up];
			up--;
		}
		while (down <= 14 && down <= y + 4)
		{
			board[down - y + 4] = chessboard[x][down];
			down++;
		}
		break;
	case x1:
		while (left >= 0 && left >= x - 4 && up >= 0 && up >= y - 4)
		{
			board[left - x + 4] = chessboard[left][up];
			left--;
			up--;
		}
		while (right <= 14 && right <= x + 4 && down <= 14 && down <= y + 4)
		{
			board[right - x + 4] = chessboard[right][down];
			right++;
			down++;
		}
		break;
	case x2:
		while (left >= 0 && left >= x - 4 && down <= 14 && down <= y + 4)
		{
			board[left - x + 4] = chessboard[left][down];
			left--;
			down++;
		}
		while (right <= 14 && right <= x + 4 && up >= 0 && up >= y - 4)
		{
			board[right - x + 4] = chessboard[right][up];
			right++;
			up--;
		}
		break;
	}
	board[4] = type;
	begin = end = 4;
	while (begin > 0 && board[begin - 1] == type)
		begin--;
	while (end < 8 && board[end + 1] == type)
		end++;
	count = end - begin + 1;
	score = nothreat;
	switch (count)
	{
	case 9:
		score = overline;
		break;
	case 8:
		score = overline;
		break;
	case 7:
		score = overline;
		break;
	case 6:
		score = overline;
		break;
	case 5:
		score = win5;
		break;
	case 4:
		if (board[begin - 1] == blank && board[end + 1] == blank)
			score = live4;
		else if (board[begin - 1] == opponent && board[end + 1] == opponent)
			score = nothreat;
		else score = die4;
		break;
	case 3:
		if (board[begin - 1] == blank && board[end + 1] == blank)
		{
			if (board[begin - 2] == opponent && board[end + 2] == opponent)
				score = die3;
			else if (board[begin - 2] == type || board[end + 2] == type)
				score = lowdie4;
			else score = live3;
		}
		else if (board[begin - 1] == opponent && board[end + 1] == opponent)
			score = nothreat;
		else
		{
			if (board[begin - 1] == opponent)
			{
				if (board[end + 1] == opponent)
					score = nothreat;
				else if (board[end + 1] == blank)
					score = die3;
				else score = lowdie4;
			}
			if (board[end + 1] == opponent)
			{
				if (board[begin - 1] == opponent)
					score = nothreat;
				else if (board[begin - 1] == blank)
					score = die3;
				else score = lowdie4;
			}
		}
		break;
	case 2:
		if (board[begin - 1] == blank && board[end + 1] == blank)
		{
			if ((board[end + 2] == blank && board[end + 3] == type) ||
				(board[begin - 2] == blank && board[begin - 3] == type))
				score = die3;
			else if (board[begin - 2] == blank && board[end + 2] == blank)
				score = live2;
			else if ((board[end + 2] == type && board[end + 3] == opponent) ||
				(board[begin - 2] == type && board[begin - 3] == opponent))
				score = die3;
			else if ((board[end + 2] == type && board[end + 3] == type) ||
				(board[begin - 2] == type && board[begin - 3] == type))
				score = double4;
			else if ((board[end + 2] == type && board[end + 3] == type) ||
				(board[begin - 2] == type && board[begin - 3] == type))
				score = lowdie4;
			else if ((board[end + 2] == type && board[end + 3] == blank) ||
				(board[begin - 2] == type && board[begin - 3] == blank))
				score = jump3;
		}
		else if (board[begin - 1] == opponent && board[end + 1] == opponent)
			score = nothreat;
		else if (board[begin - 1] == blank || board[end + 1] == blank)
		{
			if (board[begin - 1] == opponent)
			{
				if (board[end + 2] == opponent || board[end + 3] == opponent)
					score = nothreat;
				else if (board[end + 2] == blank && board[end + 3] == blank)
					score = die2;
				else if (board[end + 2] == type && board[end + 3] == type)
					score = lowdie4;
				else if (board[end + 2] == type || board[end + 3] == type)
					score = die3;
			}
			if (board[end + 1] == opponent)
			{
				if (board[begin - 2] == opponent || board[begin - 3] == opponent)
					score = nothreat;
				else if (board[begin - 2] == blank && board[begin - 3] == blank)
					score = die2;
				else if (board[begin - 2] == type && board[begin - 3] == type)
					score = lowdie4;
				else if (board[begin - 2] == type || board[begin - 3] == type)
					score = die3;
			}
		}
		break;
	case 1:
		if (board[begin - 1] == blank && board[begin - 2] == type &&
			board[begin - 3] == type && board[begin - 4] == type)
			score = lowdie4;
		else if (board[end + 1] == blank && board[end + 2] == type &&
			board[end + 3] == type && board[end + 4] == type)
			score = lowdie4;
		else if (board[begin - 1] == blank && board[begin - 2] == type &&
			board[begin - 3] == type && board[begin - 4] == blank && board[end + 1] == blank)
			score = jump3;
		else if (board[end + 1] == blank && board[end + 2] == type &&
			board[end + 3] == type && board[end + 4] == blank && board[begin - 1] == blank)
			score = jump3;
		else if (board[begin - 1] == blank && board[begin - 2] == type &&
			board[begin - 3] == type && board[begin - 4] == opponent && board[end + 1] == blank)
			score = die3;
		else if (board[end + 1] == blank && board[end + 2] == type &&
			board[end + 3] == type && board[end + 4] == opponent && board[begin - 1] == blank)
			score = die3;
		else if (board[begin - 1] == blank && board[begin - 2] == blank &&
			board[begin - 3] == type && board[begin - 4] == type)
			score = die3;
		else if (board[end + 1] == blank && board[end + 2] == blank &&
			board[end + 3] == type && board[end + 4] == type)
			score = die3;
		else if (board[begin - 1] == blank && board[begin - 2] == type &&
			board[begin - 3] == blank && board[begin - 4] == type)
			score = die3;
		else if (board[end + 1] == blank && board[end + 2] == type &&
			board[end + 3] == blank && board[end + 4] == type)
			score = die3;
		else if (board[begin - 1] == blank && board[begin - 2] == type &&
			board[begin - 3] == blank && board[begin - 4] == blank && board[end + 1] == blank)
			score = lowlive2;
		else if (board[end + 1] == blank && board[end + 2] == type &&
			board[end + 3] == blank && board[end + 4] == blank && board[begin - 1] == blank)
			score = lowlive2;
		else if (board[begin - 1] == blank && board[begin - 2] == blank &&
			board[begin - 3] == type && board[begin - 4] == blank && board[end + 1] == blank)
			score = lowlive2;
		else if (board[end + 1] == blank && board[end + 2] == blank &&
			board[end + 3] == type && board[end + 4] == blank && board[begin - 1] == blank)
			score = lowlive2;
		break;
	default:
		score = nothreat;
		break;
	}
}

int CSubBoard::operator[](int n)
{
	return board[n];
}

int CSubBoard::getCount()
{
	return count;
}

int CSubBoard::getBegin()
{
	return begin;
}

int CSubBoard::getEnd()
{
	return end;
}

int CSubBoard::getScore()
{
	return score;
}