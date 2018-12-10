//�Լ�������ʾ������Ӧ���ļ���Ȼ����ӵ����̾�����

//Institute of Automation,Chinese Academy of Science

//ShawnSu



//�ļ�main.cpp

#include "CManager.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
void main()
{

	CManager manager;
	manager.GameRun();

}





//CAlgorithm.h�ļ�

#ifndef CAlgorithm_H_H_H_
#define CAlgorithm_H_H_H_
#include "CChessBoard.h"
#include "CPlayer.h"
#include "CPoint.h"

class CAlgorithm
{
public:
	void CountChessModel(const CChessBoard& board, const CPoint& point, const int color, int(*p)[2]);
	CPoint ComputePiecePosition(const CChessBoard& board, const CPlayer& player);

};
#endif


//CChessBoard.h�ļ�

#ifndef CChessBoard_H_H_H_
#define CChessBoard_H_H_H_
#include "CPoint.h"
#include "CPiece.h"

#define SIZE 15


class CChessBoard
{
public:
	CChessBoard();
	~CChessBoard();
	void PlacePiece(const CPiece& piece);
	int ReturnPieceAt(CPoint& pos) const;

private:
	int(*pt)[SIZE + 1];
};

#endif


//CJudge.h�ļ�

#ifndef CJudge_H_H_H_
#define CJudge_H_H_H_
#include "CChessBoard.h"
#include "CPiece.h"

class CJudge
{
public:
	bool IsValid(const CChessBoard& board, const CPiece& piece);
	bool IsForbidden(const CChessBoard& board, const CPiece& piece);
	bool IsWin(const CChessBoard& board, const CPiece& piece);
	bool IsChangLian(const CChessBoard& board, const CPiece& piece);
	void ComputeChessModel(const CChessBoard& board, const CPiece& piece, int(*p)[2]);

};


#endif


//CManager.h�ļ�

#ifndef CManager_H_H_H_
#define CManager_H_H_H_
#include "CChessBoard.h"
#include "COrganizer.h"
#include "CPiece.h"
#include "CPlayer.h"
#include "CPoint.h"
#include "CShow.h"
#include "CJudge.h"
#include "CAlogorithm.h"

class CManager
{
public:
	void GameRun();
};
#endif





//COrganizer.h�ļ�
#ifndef  COrganizer_H_H_H_
#define COrganizer_H_H_H_
#include "CShow.h"
#include "CPlayer.h"
#include "CPoint.h"


class COrganizer
{
public:
	void DecideGameMode(CShow &show);
	int ReturnMode();
	void DecideWhoGoFirst(CPlayer& p1, CPlayer& p2);

	string ReturnPlayer1Name();
	string ReturnPlayer2Name();
	int ReturnFlagTurn();
	CPoint GetInputPosition();
	void ExchangeFlag();
	char GetIsContinueResult();

private:
	int mode;         //1���˶�ս��2�˻���ս
	string player1name;   //1���������
	string player2name;   //2���������
	int flagturn;
};

#endif



//CPiece.h�ļ�
#ifndef CPiece_H_H_H_
#define CPiece_H_H_H_
#include "CPoint.h"
#include <string>
using namespace std;
#define blank 0
#define black 1
#define white 2


class CPiece
{
public:
	void SetColor(int col);
	void SetPosition(const CPoint& p);
	int ReturnColor() const;
	CPoint ReturnPoint() const;
	string ReturnShape();

private:
	int color;
	string shape;
	CPoint point;
};
#endif



//CPlayer.h�ļ�
#ifndef CPlayer_H_H_H_
#define CPlayer_H_H_H_
#include "CPiece.h"
#include "CChessBoard.h"

class CPlayer
{
public:
	void SetColor(int col);
	int ReturnColor() const;
	void GetPiece(CPiece& piece, const CPoint& position);
	void PlacePiece(CChessBoard& board, const CPiece& piece);
	void SetName(string s);
	string ReturnName() const;
private:
	int color;
	string name;
};
#endif


//CPoint.h�ļ�
#ifndef CPoint_H_H_H_
#define CPoint_H_H_H_
class CPoint
{
public:
	CPoint();
	CPoint(int a, int b);
	void SetPoint(int a, int b);
	void operator=(const CPoint& p);
	bool operator==(const CPoint& p);
	int x;
	int y;
};

#endif




//CShow.h�ļ�
#ifndef CShow_H_H_H_
#define CShow_H_H_H_
#include "CChessBoard.h"
#include "CPiece.h"
#include "CPoint.h"
#include "CPlayer.h"



class CShow
{
public:
	void Welcome();
	void DisplayBoard();
	void DisplayBoard(const CChessBoard& board, const CPiece& pie);
	void ShowChoseGameMode();
	void ShowInputPosition(const CPlayer& player);
	void ShowWin(const CPlayer& player);
	void ShowIsContinue();
	void ShowForbidden(const CPlayer& player);


};

#endif




//CAlogorithm.cpp�ļ�
#include "CAlogorithm.h"
#include <vector>
#include<math.h>
using namespace std;



CPoint CAlgorithm::ComputePiecePosition(const CChessBoard& board, const CPlayer& player, CJudge& judge)
{
	CChessBoard boardtemp;
	boardtemp = board;      //���´��һ�����̱�
	int myvalue[SIZE + 1][SIZE + 1];
	int opponentvalue[SIZE + 1][SIZE + 1];

	int col = 0;
	int row = 0;
	for (col = 0; col <= SIZE; col++)
	{
		for (row = 0; row <= SIZE; row++)
		{
			myvalue[col][row] = -2;
			opponentvalue[col][row] = -2;
		}
	}
	int mycolor = player.ReturnColor();
	int opponentcolor = 0;        //���������ɫ
	if (black == mycolor)
	{
		opponentcolor = white;
	}
	else
		opponentcolor = black;









	int FValue[6][2] = { { 0,0 },{ 1,4 },{ 16,80 },{ 400,2000 },{ 10000,50000 },{ 100000,100000 } };
	int LValue[6][2] = { { 0,0 },{ 1,4 },{ 8,40 },{ 200,1000 },{ 5000,25000 },{ 50000,50000 } };
	CPoint temp;
	CPiece piece;
	for (col = 1; col <= SIZE; col++)
	{
		for (row = 1; row <= SIZE; row++)
		{
			temp.SetPoint(col, row);
			if (blank == boardtemp.ReturnPieceAt(temp))
			{
				piece.SetColor(mycolor);
				piece.SetPosition(temp);
				boardtemp.PlacePiece(piece);          //�ȼ����ڴ˿�λ�����Լ�������
				if (!judge.IsForbidden(boardtemp, piece))    //���̸õ�Ϊ��λʱ
				{
					int a[4][2];
					judge.ComputeChessModel(boardtemp, piece, a);
					for (int k = 0; k<4; k++)
					{

						myvalue[col][row] += FValue[a[k][0]][a[k][1]];
					}
					piece.SetColor(opponentcolor);
					boardtemp.PlacePiece(piece);           //��������ڴ˿�λ�����˶��ֵ���    
					judge.ComputeChessModel(boardtemp, piece, a);

					for (k = 0; k<4; k++)
					{

						opponentvalue[col][row] += LValue[a[k][0]][a[k][1]];
					}
				}
				boardtemp.RetractPieceAt(temp);
			}
		}
	}//�������������ϣ�

	int mymax = -2;
	int opponentmax = -2;
	vector<CPoint> mymaxpoint;
	vector<CPoint> opponentmaxpoint;
	mymaxpoint.erase(mymaxpoint.begin(), mymaxpoint.end());
	opponentmaxpoint.erase(opponentmaxpoint.begin(), opponentmaxpoint.end());

	for (col = 1; col <= SIZE; col++)
	{
		for (row = 1; row <= SIZE; row++)
		{
			mymax = __max(mymax, myvalue[col][row]);  //�ҳ����������ֵ


		}
	}
	for (col = 1; col <= SIZE; col++)
	{
		for (row = 1; row <= SIZE; row++)
		{
			if (mymax == myvalue[col][row])
			{
				mymaxpoint.push_back(CPoint(col, row));     //��¼���ֵ������
			}


		}
	}

	for (col = 1; col <= SIZE; col++)
	{
		for (row = 1; row <= SIZE; row++)
		{
			opponentmax = __max(opponentmax, opponentvalue[col][row]); //�ҳ����������ֵ


		}
	}
	for (col = 1; col <= SIZE; col++)
	{
		for (row = 1; row <= SIZE; row++)
		{
			if (opponentmax == opponentvalue[col][row])
			{
				opponentmaxpoint.push_back(CPoint(col, row));     //��¼���ֵ������
			}


		}
	}

	int x0 = (SIZE + 1) / 2;   //�������ĵ�λ��
	int y0 = (SIZE + 1) / 2;
	int d;              //�����ĵ�����ĵ�ľ���ֵ
	CPoint dpoint;      //���������ĵ�����ĵ�
	if (mymax >= opponentmax)
	{
		d = pow(mymaxpoint[0].x - x0, 2) + pow(mymaxpoint[0].y - y0, 2);       //ѡ�������ĵ�����ĵ�
		dpoint = mymaxpoint[0];
		for (int k = 1; k<mymaxpoint.size(); k++)
		{

			int dtemp = pow(mymaxpoint[k].x - x0, 2) + pow(mymaxpoint[k].y - y0, 2);
			if (dtemp <= d)
			{
				d = dtemp;    //��С�������
				dpoint = mymaxpoint[k];
			}
		}
		return dpoint;

	}
	else
	{
		d = pow(opponentmaxpoint[0].x - x0, 2) + pow(opponentmaxpoint[0].y - y0, 2);       //ѡ�������ĵ�����ĵ�
		dpoint = opponentmaxpoint[0];
		for (int k = 1; k<opponentmaxpoint.size(); k++)
		{

			int dtemp = pow(opponentmaxpoint[k].x - x0, 2) + pow(opponentmaxpoint[k].y - y0, 2);
			if (dtemp <= d)
			{
				d = dtemp;   ////��С�������
				dpoint = opponentmaxpoint[k];
			}
		}
		return dpoint;

	}


}







//CChessBoard.cpp�ļ�
#include "CChessBoard.h"

CChessBoard::CChessBoard()
{
	pt = new int[16][16];
	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j <= 15; j++)
		{
			pt[i][j] = 0;
		}
	}
}
void CChessBoard::PlacePiece(const CPiece& piece)
{
	CPoint pos = piece.ReturnPoint();
	pt[pos.x][pos.y] = piece.ReturnColor();
}
int CChessBoard::ReturnPieceAt(CPoint& pos) const
{
	return pt[pos.x][pos.y];
}
CChessBoard::~CChessBoard()
{
	delete[]pt;
}











//CJudge.cpp�ļ�

#include "CJudge.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

bool CJudge::IsValid(const CChessBoard& board, const CPiece& piece)
{
	CPoint pos = piece.ReturnPoint();
	if (pos.x <= 0 || pos.x>SIZE || pos.y <= 0 || pos.y>SIZE)
	{
		cout << "Error! Out of bounds.";
		cout << endl;
		return false;
	}
	if (0 != board.ReturnPieceAt(pos))
	{
		cout << "Error! The position has already placed piece";
		cout << endl;
		return false;
	}
	return true;
}

bool CJudge::IsChangLian(const CChessBoard& board, const CPiece& piece)
{

	for (int i = 1; i <= 4; i++)
	{
		int sum = 1;
		for (int j = 0; j <= 1; j++)
		{
			CPoint pos = piece.ReturnPoint();
			int direction = i + j * 4;
			while (1) //���������������ʱ�˳�
			{
				switch (direction)
				{
				case 1:
					pos.x++;
					break;
				case 2:
					pos.x++;
					pos.y--;
					break;
				case 3:
					pos.y--;
					break;
				case 4:
					pos.x--;
					pos.y--;
					break;
				case 5:
					pos.x--;
					break;
				case 6:
					pos.x--;
					pos.y++;
					break;
				case 7:
					pos.y++;
					break;
				case 8:
					pos.x++;
					pos.y++;
					break;
				default:
					break;
				}
				if (pos.x<1 || pos.y<1 || pos.x>SIZE || pos.y>SIZE)
				{
					break;             //�����˳�ѭ��
				}
				if (piece.ReturnColor() == board.ReturnPieceAt(pos))
				{
					sum++;             //ͬɫ����Ŀ���
				}
				else
					break;
			}//while����
		}
		if (sum>5)
		{
			return true;
		}
	}
	return false;

}

void CJudge::ComputeChessModel(const CChessBoard& board, const CPiece& piece, int(*p)[2])
{
	int(*chessmodel)[2] = p;   //4��2ά���飬��һ��������,ÿ����ά����������������������
	for (int i = 0; i<4; i++)
	{
		p[i][0] = 0;
		p[i][1] = 0;
	}



	for (i = 1; i <= 4; i++)
	{
		CPoint current = piece.ReturnPoint();



		CPoint left = current;
		CPoint right = current;
		CPoint directiondelta(0, 0);
		switch (i)
		{
		case 1:
			directiondelta.x = 1;
			break;
		case 2:
			directiondelta.y = 1;
			break;
		case 3:
			directiondelta.x = 1;
			directiondelta.y = 1;
			break;
		case 4:
			directiondelta.x = 1;
			directiondelta.y = -1;
		default:
			break;
		}


		for (int j = 1; j <= 4; j++)
		{
			int a = left.x - directiondelta.x;
			int b = left.y - directiondelta.y;
			if (a<1 || b<1 || a>SIZE || b>SIZE || white == board.ReturnPieceAt(CPoint(a, b)))  //������������ӣ����˳�
				break;
			left.x = a;
			left.y = b;
		}
		for (j = 1; j <= 4; j++)
		{
			int a = right.x + directiondelta.x;
			int b = right.y + directiondelta.y;
			if (a<1 || b<1 || a>SIZE || b>SIZE || white == board.ReturnPieceAt(CPoint(a, b)))  //������������ӣ����˳�
				break;
			right.x = a;
			right.y = b;
		}


		int distance;
		distance = __max(abs(right.x - left.x), abs(right.y - left.y));
		if (distance<4)
			continue;


		vector<int> sumlist;       //��ź�����
		for (j = 0; j <= distance - 4; j++)           //������Ϊdistance-4
		{

			int sum = 0;
			for (int k = 0; k <= 4; k++)
			{
				CPoint temp;

				temp.x = left.x + (k + j)*directiondelta.x;
				temp.y = left.y + (k + j)*directiondelta.y;
				if (black == board.ReturnPieceAt(temp))
				{
					sum++;                 //�����һ�еĺ�����
				}

			}
			sumlist.push_back(sum);
		}//����������е��廷����������

		int max = sumlist[0];               //��¼sumlist�е����ֵ

		for (int k = 0; k<sumlist.size(); k++)
		{
			max = __max(max, sumlist[k]);
		}

		int number = 0;                     //��¼���ֵ�ĸ���
		for (k = 0; k<sumlist.size(); k++)
		{
			if (sumlist[k] == max)
			{
				number++;
			}

		}


		chessmodel[i - 1][0] = max;
		chessmodel[i - 1][1] = number;

	}//4������ɨ����  

}

bool CJudge::IsForbidden(const CChessBoard& board, const CPiece& piece)
{

	if (white == piece.ReturnColor())
	{
		return false;
	}

	else
	{
		if (IsChangLian(board, piece))
			return true;                        //�������ؽ���
		int chessmodelarray[4][2];
		ComputeChessModel(board, piece, chessmodelarray);

		int three = 0;     //�����ĸ���
		int four = 0;      //���ģ����ĵĸ���
		int five = 0;      //�����ĸ���

		for (int i = 0; i<4; i++)
		{

			if (chessmodelarray[i][0] == 3)
			{
				if (chessmodelarray[i][1]>1)
					three++;
			}
			if (chessmodelarray[i][0] == 4)
			{
				if (chessmodelarray[i][1] >= 1)
					four++;
			}
			if (chessmodelarray[i][0] == 5)
			{
				five++;
			}


		}
		if (three == 2 && five == 0)
			return true;
		if (four == 2 && five == 0)
			return true;
	}
	return false;
}

bool CJudge::IsWin(const CChessBoard& board, const CPiece& piece)
{



	for (int i = 1; i <= 4; i++)
	{
		int sum = 1;
		for (int j = 0; j <= 1; j++)
		{
			CPoint pos = piece.ReturnPoint();
			int direction = i + j * 4;
			while (1) //���������������ʱ�˳�
			{
				switch (direction)
				{
				case 1:
					pos.x++;
					break;
				case 2:
					pos.x++;
					pos.y--;
					break;
				case 3:
					pos.y--;
					break;
				case 4:
					pos.x--;
					pos.y--;
					break;
				case 5:
					pos.x--;
					break;
				case 6:
					pos.x--;
					pos.y++;
					break;
				case 7:
					pos.y++;
					break;
				case 8:
					pos.x++;
					pos.y++;
					break;
				default:
					break;
				}
				if (pos.x<1 || pos.y<1 || pos.x>SIZE || pos.y>SIZE)
				{
					break;             //�����˳�ѭ��
				}
				if (piece.ReturnColor() == board.ReturnPieceAt(pos))
				{
					sum++;             //ͬɫ����Ŀ���
				}
				else
					break;
			}//while����


		}
		if (sum >= 5)
		{
			return true;
		}
	}

	return false;
}

//CManager.cpp�ļ�
#include "CManager.h"
#include <iostream>
using namespace std;

void CManager::GameRun()
{


	while (1)    //IsContinueΪ��ʱ�˳�
	{
		CPlayer player1, player2;
		CJudge judge;
		CChessBoard board;
		CPiece piece;
		CShow show;
		COrganizer organizer;
		show.Welcome();
		show.DisplayBoard();
		organizer.DecideGameMode(show);


		if (1 == organizer.ReturnMode())
		{
			organizer.DecideWhoGoFirst(player1, player2);

			show.Welcome();                //������ʾһ������
			show.DisplayBoard();
			while (1)
			{
				if (1 == organizer.ReturnFlagTurn())        //�ֵ�1�����
				{

					do {
						show.ShowInputPosition(player1);
						CPoint point = organizer.GetInputPosition();
						player1.GetPiece(piece, point);

					} while (!judge.IsValid(board, piece));

					board.PlacePiece(piece);
					show.Welcome();
					show.DisplayBoard(board, piece);


				}
				else                                     //�ֵ�2�����
				{

					do {
						show.ShowInputPosition(player2);
						CPoint point = organizer.GetInputPosition();
						player2.GetPiece(piece, point);

					} while (!judge.IsValid(board, piece));

					board.PlacePiece(piece);
					show.Welcome();
					show.DisplayBoard(board, piece);


				}

				if (judge.IsForbidden(board, piece))
				{
					if (1 == organizer.ReturnFlagTurn())
					{
						show.ShowForbidden(player1);
					}
					else
						show.ShowForbidden(player2);
					break;

				}




				if (judge.IsWin(board, piece))
				{
					if (1 == organizer.ReturnFlagTurn())
					{
						show.ShowWin(player1);
					}
					else
						show.ShowWin(player2);
					break;

				}
				organizer.ExchangeFlag();

			}//while�������˳���Ϸ
		}



		else
		{
			CAlgorithm algorithm;       //�㷨��
			organizer.DecideWhoGoFirst(player1, player2);

			show.Welcome();                //������ʾһ������
			show.DisplayBoard();
			while (1)
			{
				if (1 == organizer.ReturnFlagTurn())        //�ֵ�1�����
				{

					do {
						show.ShowInputPosition(player1);
						CPoint point = organizer.GetInputPosition();
						player1.GetPiece(piece, point);

					} while (!judge.IsValid(board, piece));

					board.PlacePiece(piece);
					show.Welcome();
					show.DisplayBoard(board, piece);


				}
				else                                     //�ֵ�2�����
				{



					CPoint point = algorithm.ComputePiecePosition(board, player2);
					player2.GetPiece(piece, point);


					board.PlacePiece(piece);
					show.Welcome();
					show.DisplayBoard(board, piece);


				}

				if (judge.IsForbidden(board, piece))
				{
					if (1 == organizer.ReturnFlagTurn())
					{
						show.ShowForbidden(player1);
					}
					else
						show.ShowForbidden(player2);
					break;

				}




				if (judge.IsWin(board, piece))
				{
					if (1 == organizer.ReturnFlagTurn())
					{
						show.ShowWin(player1);
					}
					else
						show.ShowWin(player2);
					break;

				}
				organizer.ExchangeFlag();

			}//while�������˳���Ϸ





		}




		int choice = 0;
		do {
			show.ShowIsContinue();
			choice = organizer.GetIsContinueResult();
		} while (choice != 'Y' && choice != 'N');
		if ('N' == choice)
			break;
	}
}











//COrganizer.cpp�ļ�
#include "CManager.h"
#include<iostream>
#include <string>
#include <cctype>
using namespace std;

void COrganizer::DecideGameMode(CShow &show)
{
	do {
		show.ShowChoseGameMode();
		cin >> mode;
	} while (mode != 1 && mode != 2);
}
int COrganizer::ReturnMode()
{
	return mode;
}

string COrganizer::ReturnPlayer1Name()
{
	return player1name;
}
string COrganizer::ReturnPlayer2Name()
{
	return player2name;
}

void COrganizer::DecideWhoGoFirst(CPlayer& p1, CPlayer& p2)
{
	if (1 == mode)
	{
		p1.SetName("Player1");
		p2.SetName("Player2");
	}
	else
	{
		p1.SetName("Human");
		p2.SetName("Computer");
	}
	do {
		cout << endl;
		cout << "Player List :";
		cout << p1.ReturnName() << " , " << p2.ReturnName();
		cout << endl;
		cout << p1.ReturnName() << " go first( 1)";
		cout << endl;
		cout << p2.ReturnName() << " go first( 2)";
		cout << endl;
		cout << "Please decide who go first ( 1 or 2) : ";
		cin >> flagturn;
	} while (flagturn != 1 && flagturn != 2);

	if (1 == flagturn)
	{
		p1.SetColor(black);
		p2.SetColor(white);
	}
	else
	{
		p1.SetColor(white);
		p2.SetColor(black);
	}

}

int COrganizer::ReturnFlagTurn()
{
	return flagturn;
}


CPoint COrganizer::GetInputPosition()
{
	string str;
	cin >> str;         //����Ļ�ж�ȡ�ַ���
	int x = 0, y = 0;
	if (str.at(0) >= 48 && str.at(0) <= 57)         //������������ʱ������ǰ�棬��ĸ�ں�������
	{
		if (2 == str.length())
		{
			x = int(toupper(str.at(1))) - 64;
			y = int(str.at(0)) - 48;
			return CPoint(x, y);
		}
		else
		{
			x = int(toupper(str.at(2))) - 64;
			y = int(str.at(0)) - 48;
			y = y * 10 + int(str.at(1)) - 48;
			return CPoint(x, y);
		}


	}
	else                                       //������������ʱ��ĸ��ǰ�棬�����ں�������
	{
		if (2 == str.length())
		{
			x = int(toupper(str.at(0))) - 64;
			y = int(str.at(1)) - 48;
			return CPoint(x, y);
		}
		else
		{
			x = int(toupper(str.at(0))) - 64;
			y = int(str.at(1)) - 48;
			y = y * 10 + int(str.at(2)) - 48;
			return CPoint(x, y);
		}


	}
}
void COrganizer::ExchangeFlag()
{
	if (1 == flagturn)
	{
		flagturn = 2;
	}
	else
	{
		flagturn = 1;
	}
}

char COrganizer::GetIsContinueResult()
{
	char choice;
	cin >> choice;
	choice = toupper(choice);
	return choice;

}




//CPiece.cpp�ļ�
#include "CPiece.h"
void CPiece::SetColor(int col)
{
	color = col;
	if (1 == color)
	{
		shape = "��";
	}
	else if (2 == color)
	{
		shape = "��";
	};
}
void CPiece::SetPosition(const CPoint& p)
{
	point = p;
}
int CPiece::ReturnColor() const
{
	return color;
}
CPoint CPiece::ReturnPoint() const
{
	return point;

}
string CPiece::ReturnShape()
{
	return shape;
}







//CPlayer.cpp�ļ�
#include "CPlayer.h"
#include <string>
using namespace std;

void CPlayer::SetColor(int col)
{
	color = col;
}
int CPlayer::ReturnColor() const
{
	return color;
}
void CPlayer::GetPiece(CPiece& piece, const CPoint& pos)
{
	piece.SetColor(color);
	piece.SetPosition(pos);
}
void CPlayer::SetName(string s)
{
	name = s;
}

string CPlayer::ReturnName() const
{
	return name;
}









//CPoint.cpp�ļ�
#include "CPoint.h"

CPoint::CPoint()
{

}
CPoint::CPoint(int a, int b)
{
	x = a;
	y = b;
}
void CPoint::SetPoint(int a, int b)
{
	x = a;
	y = b;
}
void CPoint::operator=(const CPoint& p)
{
	x = p.x;
	y = p.y;
}
bool CPoint::operator ==(const CPoint& p)
{
	if (x == p.x && y == p.y)
		return true;
	else
		return false;
}





















//CShow.cpp�ļ�
#include "CShow.h"


#include <iostream>
using namespace std;



void CShow::Welcome()
{
	system("cls");   //����
	cout << endl;
	cout << "  ==Welcome to FiveInRow Game==";
	cout << endl;
	cout << endl;
}



void CShow::ShowChoseGameMode()
{
	//cout<<"Game Mode"<<endl;
	cout << "People VS People  ( 1)" << endl;
	cout << "People VS Computer( 2)" << endl;
	cout << "Please Choose Game Mode ( 1 or 2 ): ";
}



void CShow::DisplayBoard()
{
	int row = 0, col = 0;


	if (SIZE<10)
	{
		cout << " ";
	}
	cout << SIZE;
	cout << "��";

	for (col = 2; col <= SIZE - 1; col++)
	{
		cout << "��";
	}
	cout << "��";
	cout << endl;





	for (row = SIZE - 1; row >= 2; row--)
	{
		if (row >= 10)                  //��ʾ����
		{
			cout << row;
		}
		else
			cout << ' ' << row;
		cout << "��";
		for (col = 2; col <= SIZE - 1; col++)
		{
			cout << "��";
		}
		cout << "��";
		cout << endl;
	}





	cout << " 1";
	cout << "��";
	for (col = 2; col <= SIZE - 1; col++)
	{
		cout << "��";
	}
	cout << "��";
	cout << endl;
	//������ʾA B C D ...
	cout << "  ";
	char alpha = 65;
	for (col = 1; col <= SIZE; col++)
	{
		cout << alpha;
		cout << ' ';
		alpha = alpha + 1;

	}
	cout << endl;
	cout << endl;

}





void CShow::DisplayBoard(const CChessBoard& board, const CPiece& pie)
{
	int row = 0, col = 0;



	CPiece piece;
	piece.SetColor(black);
	string blackshape = piece.ReturnShape();
	piece.SetColor(white);
	string whiteshape = piece.ReturnShape();
	string currentshape;
	if (black == pie.ReturnColor())
	{
		currentshape = "��";
	}
	else
	{
		currentshape = "��";
	}


	CPoint pos = pie.ReturnPoint();    //�õ���ǰ���ӵ�



	if (SIZE<10)
	{
		cout << " ";
	}
	cout << SIZE;

	if (pos == CPoint(1, 15))
	{
		cout << currentshape;
	}
	else
	{
		switch (board.ReturnPieceAt(CPoint(1, SIZE)))
		{
		case blank:
			cout << "��";
			break;
		case black:
			cout << blackshape;
			break;
		case white:
			cout << whiteshape;
		}
	}
	for (col = 2; col <= SIZE - 1; col++)
	{
		if (pos == CPoint(col, SIZE))
		{
			cout << currentshape;
		}
		else
		{
			switch (board.ReturnPieceAt(CPoint(col, SIZE)))
			{
			case blank:
				cout << "��";
				break;
			case black:
				cout << blackshape;
				break;
			case white:
				cout << whiteshape;
			}
		}

	}
	if (pos == CPoint(SIZE, SIZE))
	{
		cout << currentshape;
	}
	else
	{
		switch (board.ReturnPieceAt(CPoint(SIZE, SIZE)))
		{
		case blank:
			cout << "��";
			break;
		case black:
			cout << blackshape;
			break;
		case white:
			cout << whiteshape;
		}
	}

	cout << endl;





	for (row = SIZE - 1; row >= 2; row--)
	{
		if (row >= 10)                  //��ʾ����
		{
			cout << row;
		}
		else
			cout << ' ' << row;
		if (pos == CPoint(1, row))
		{
			cout << currentshape;
		}
		else
		{
			switch (board.ReturnPieceAt(CPoint(1, row)))
			{
			case blank:
				cout << "��";
				break;
			case black:
				cout << blackshape;
				break;
			case white:
				cout << whiteshape;
			}
		}

		for (col = 2; col <= SIZE - 1; col++)
		{
			if (pos == CPoint(col, row))
			{
				cout << currentshape;
			}
			else
			{
				switch (board.ReturnPieceAt(CPoint(col, row)))
				{
				case blank:
					cout << "��";
					break;
				case black:
					cout << blackshape;
					break;
				case white:
					cout << whiteshape;
				}
			}

		}
		if (pos == CPoint(SIZE, row))
		{
			cout << currentshape;
		}
		else
		{
			switch (board.ReturnPieceAt(CPoint(SIZE, row)))
			{
			case blank:
				cout << "��";
				break;
			case black:
				cout << blackshape;
				break;
			case white:
				cout << whiteshape;
			}
		}

		cout << endl;
	}





	cout << " 1";
	if (pos == CPoint(1, 1))
	{
		cout << currentshape;
	}
	else
	{
		switch (board.ReturnPieceAt(CPoint(1, 1)))
		{
		case blank:
			cout << "��";
			break;
		case black:
			cout << blackshape;
			break;
		case white:
			cout << whiteshape;
		}
	}

	for (col = 2; col <= SIZE - 1; col++)
	{
		if (pos == CPoint(col, 1))
		{
			cout << currentshape;
		}
		else
		{
			switch (board.ReturnPieceAt(CPoint(col, 1)))
			{
			case blank:
				cout << "��";
				break;
			case black:
				cout << blackshape;
				break;
			case white:
				cout << whiteshape;
			}
		}

	}
	if (pos == CPoint(SIZE, 1))
	{
		cout << currentshape;
	}
	else
	{
		switch (board.ReturnPieceAt(CPoint(SIZE, 1)))
		{
		case blank:
			cout << "��";
			break;
		case black:
			cout << blackshape;
			break;
		case white:
			cout << whiteshape;
		}
	}

	cout << endl;
	//������ʾA B C D ...
	cout << "  ";
	char alpha = 65;
	for (col = 1; col <= SIZE; col++)
	{
		cout << alpha;
		cout << ' ';
		alpha = alpha + 1;

	}
	cout << endl;
	cout << endl;




}

void CShow::ShowInputPosition(const CPlayer& player)
{
	CPiece pie;
	pie.SetColor(player.ReturnColor());
	cout << player.ReturnName() << "(" << pie.ReturnShape() << ")" << " ,please input piece position ^_^ : ";

}
void CShow::ShowWin(const CPlayer& player)
{
	cout << "Congratuations!" << player.ReturnName() << " win!";
	cout << endl;

}

void CShow::ShowForbidden(const CPlayer& player)
{
	cout << "Sorry!" << player.ReturnName() << " forbidden!";
	cout << endl;
}

void CShow::ShowIsContinue()
{
	cout << "One more game?( Y/N ) :";
}


//ף���ѧϰc++��죡

