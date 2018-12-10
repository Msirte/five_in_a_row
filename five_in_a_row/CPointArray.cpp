#include "CPointArray.h"
#include <iostream>
using namespace std;

CPointArray::CPointArray()
{
	// 初始化格点字符
	// 定义四个角的格点初始值
	this->m_gridPoint[0][0] = '┗';
	this->m_gridPoint[14][0] = '┛';
	this->m_gridPoint[14][14] = '┓';
	this->m_gridPoint[0][14] = '┏';

	// 定义四条边的格点初始值
	for (int i = 1; i < 14; i++)
	{
		this->m_gridPoint[i][0] = '┷';
		this->m_gridPoint[i][14] = '┯';
		this->m_gridPoint[0][i] = '┠';
		this->m_gridPoint[14][i] = '┨';
	}

	// 定义内部格点初始值
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			this->m_gridPoint[i][j] = '┼';
		}
	}

	// 初始化“格点全满”为否
	this->m_isFull = false;

	// 初始化总棋子数为0
	this->m_totalNum = 0;
	// 初始化白棋子数为0
	this->m_whiteNum = 0;
	// 初始化黑棋子数为0
	this->m_blackNum = 0;
}

// 判断棋盘是否下满，是返回1，否返回0
bool CPointArray::is_Full()
{
	return this->m_isFull;
}

// 返回总棋子数
int CPointArray::totalNum()
{
	return this->m_totalNum;
}

// 返回白棋子数
int CPointArray::whiteNum()
{
	return this->m_whiteNum;
}

// 返回黑棋子数
int CPointArray::blackNum()
{
	return this->m_blackNum;
}

// 设置格点值（黑子或者白子）
void CPointArray::setPointValue(int x, int y)
{
	if ()
	{

	}
}