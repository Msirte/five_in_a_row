#include"CGame.h"
#include"CDisplay.h"
#include"CChessBoard.h"
#include"CClock.h"
#include"CRules.h"
#include"CHumanPlayer.h"
#include"CAI.h"
#include"CChessPiece.h"
#include <iostream>
using namespace std;

CGame::CGame()
{
	m_nGmaes = 0;
	m_gameType = 0;
}

void CGame::run()
{
	while (true)
	{
		CDisplay display;
		CScene scene;
		CChessBoard chessboard;
		CClock clock;
		CRules judge;
		m_gameType = 0;
		bool draw = false;
		int winner = 0;
		display.showWelcome();
		while (m_gameType != 1 && m_gameType != 2 && m_gameType != 3)
			cin >> m_gameType;
		if (m_gameType == 3)
			break;
		else if (m_gameType == 1)
		{
			m_nGmaes++;
			CHumanPlayer player1(black);
			CHumanPlayer player2(white);
			display.showChessBoard(chessboard);
			while (true)
			{
				CChessPiece piece1;
				while (true)
				{
					piece1 = player1.nextMove(player1.getInput());
					if (!judge.isValid(chessboard, piece1))
					{
						display.showInvalid();
						continue;
					}
					break;
				}
				scene.placeUnit(piece1);
				chessboard.refreshChessBoard(scene);
				display.showChessBoard(chessboard);
				if (judge.isForbidden(chessboard, piece1))
				{
					winner = 2;
					display.showForbidden();
					break;
				}
				if (judge.isDraw(chessboard))
				{
					draw = true;
					break;
				}
				if (judge.isWin(chessboard, piece1))
				{
					winner = 1;
					break;
				}
				CChessPiece piece2;
				while (true)
				{
					piece2 = player2.nextMove(player2.getInput());
					if (!judge.isValid(chessboard, piece2))
					{
						display.showInvalid();
						continue;
					}
					break;
				}
				scene.placeUnit(piece2);
				chessboard.refreshChessBoard(scene);
				display.showChessBoard(chessboard);
				if (judge.isForbidden(chessboard, piece2))
				{
					winner = 1;
					display.showForbidden();
					break;
				}
				if (judge.isDraw(chessboard))
				{
					draw = true;
					break;
				}
				if (judge.isWin(chessboard, piece2))
				{
					winner = 2;
					break;
				}
			}
			if (draw)
			{
				display.showDraw();
				continue;
			}
			if (winner)
			{
				display.showWin(winner);
				continue;
			}
		}

		else if (m_gameType == 2)
		{
			display.showSelectOrder();
			int type1 = 0;
			int type2;
			while (type1 != 1 && type1 != 2 && type1 != 3)
				cin >> type1;
			if (type1 == 3)
				continue;
			if (type1 == 1)
			{
				type1 = black;
				type2 = white;
			}
			else
			{
				type1 = white;
				type2 = black;
			}
			m_nGmaes++;
			CHumanPlayer player1(type1);
			CAI player2(type2);
			display.showChessBoard(chessboard);
			bool first = true;
			while (true)
			{
				if (!first || type1 == black)
				{
					CChessPiece piece1;
					while (true)
					{
						piece1 = player1.nextMove(player1.getInput());
						if (!judge.isValid(chessboard, piece1))
						{
							display.showInvalid();
							continue;
						}
						break;
					}
					scene.placeUnit(piece1);
					chessboard.refreshChessBoard(scene);
					display.showChessBoard(chessboard);
					if (judge.isForbidden(chessboard, piece1))
					{
						winner = 2;
						display.showForbidden();
						break;
					}
					if (judge.isDraw(chessboard))
					{
						draw = true;
						break;
					}
					if (judge.isWin(chessboard, piece1))
					{
						winner = 1;
						break;
					}
				}
				
				CChessPiece piece2 = player2.nextMove(player2.calculate(chessboard));
				scene.placeUnit(piece2);
				chessboard.refreshChessBoard(scene);
				display.showChessBoard(chessboard);
				if (judge.isForbidden(chessboard, piece2))
				{
					winner = 1;
					display.showForbidden();
					break;
				}
				if (judge.isDraw(chessboard))
				{
					draw = true;
					break;
				}
				if (judge.isWin(chessboard, piece2))
				{
					winner = 2;
					break;
				}
				first = false;
			}
			if (draw)
			{
				display.showDraw();
				continue;
			}
			if (winner)
			{
				display.showWin(winner);
				continue;
			}
		}
	}
}

int CGame::m_nGmaes = 0;
