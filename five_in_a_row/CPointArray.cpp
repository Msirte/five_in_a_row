#include "CPointArray.h"
#include <iostream>
using namespace std;

CPointArray::CPointArray()
{
	// ��ʼ������ַ�
	// �����ĸ��ǵĸ���ʼֵ
	this->m_gridPoint[0][0] = '��';
	this->m_gridPoint[14][0] = '��';
	this->m_gridPoint[14][14] = '��';
	this->m_gridPoint[0][14] = '��';

	// ���������ߵĸ���ʼֵ
	for (int i = 1; i < 14; i++)
	{
		this->m_gridPoint[i][0] = '��';
		this->m_gridPoint[i][14] = '��';
		this->m_gridPoint[0][i] = '��';
		this->m_gridPoint[14][i] = '��';
	}

	// �����ڲ�����ʼֵ
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			this->m_gridPoint[i][j] = '��';
		}
	}

	// ��ʼ�������ȫ����Ϊ��
	this->m_isFull = false;

	// ��ʼ����������Ϊ0
	this->m_totalNum = 0;
	// ��ʼ����������Ϊ0
	this->m_whiteNum = 0;
	// ��ʼ����������Ϊ0
	this->m_blackNum = 0;
}

// �ж������Ƿ��������Ƿ���1���񷵻�0
bool CPointArray::is_Full()
{
	return this->m_isFull;
}

// ������������
int CPointArray::totalNum()
{
	return this->m_totalNum;
}

// ���ذ�������
int CPointArray::whiteNum()
{
	return this->m_whiteNum;
}

// ���غ�������
int CPointArray::blackNum()
{
	return this->m_blackNum;
}

// ���ø��ֵ�����ӻ��߰��ӣ�
void CPointArray::setPointValue(int x, int y)
{
	if ()
	{

	}
}