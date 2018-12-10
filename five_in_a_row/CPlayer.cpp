#include"CPlayer.h"

CPlayer::CPlayer(int n)
{
	num = n;
	type = num;
}

CPlayer::CPlayer(int num, int type)
{
	this->num = num;
	this->type = type;
}

int CPlayer::getNum()
{
	return num;
}

int CPlayer::getType()
{
	return type;
}