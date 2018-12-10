#pragma once

class CPointArray
{
public:
	CPointArray();
	bool is_Full();
	int totalNum();
	int whiteNum();
	int blackNum();
	void setPointValue(int x, int y);
private:
	char m_gridPoint[15][15];
	bool m_isFull;
	int m_totalNum;
	int m_whiteNum;
	int m_blackNum;
};