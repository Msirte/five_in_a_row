#include"CHumanPlayer.h"
#include<iostream>

CHumanPlayer::CHumanPlayer(int n) : CPlayer(n) {}

CHumanPlayer::CHumanPlayer(int num, int type) : CPlayer(num, type) {}

CChessPiece CHumanPlayer::nextMove(CPoint<int> pos)
{
	CChessPiece piece(this->getNum(), this->getType(), pos);
	return piece;
}

CPoint<int> CHumanPlayer::getInput()
{
	char x;
	int y;
	std::cin >> x >> y;
	int i, j;
	i = 15 - y;
	j = x-65;
	CPoint<int> point(i, j);
	return point;
}