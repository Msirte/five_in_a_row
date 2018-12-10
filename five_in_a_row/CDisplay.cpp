#include "CDisplay.h"
#include <iostream>

using namespace std;

void CDisplay::showWelcome()
{
	cout << "Welcome to the five-in-a-row game!" << endl;
	cout << "You can enjoy yourself by playing PvP game or PvC game." << endl;
	cout << "Type [1] to play a PvP game;" << endl;
	cout << "Type [2] to play a PvC game;" << endl;
	cout << "Type [3] to exit." << endl;
}

void CDisplay::showSelectOrder()
{
	cout << "Now you need to input your order." << endl;
	cout << "Type [1] to choose black;" << endl;
	cout << "Type [2] to choose white;" << endl;
	cout << "Type [3] to go back to the main menu." << endl;
}

void CDisplay::showChessBoard(CChessBoard & chessBoard)
{
	CChessBoard dispBoard;
	dispBoard = chessBoard;

	if (dispBoard.gettype1() == black) dispBoard[dispBoard.getx1()][dispBoard.gety1()] = cblack;
	if (dispBoard.gettype1() == white) dispBoard[dispBoard.getx1()][dispBoard.gety1()] = cwhite;
	if (dispBoard.gettype2() == black) dispBoard[dispBoard.getx2()][dispBoard.gety2()] = cblack;
	if (dispBoard.gettype2() == white) dispBoard[dispBoard.getx2()][dispBoard.gety2()] = cwhite;

	// display the first row
	cout << 15;
	switch (dispBoard[0][0])
	{
	case blank:
		cout << "©³©¥";
		break;
	case black:
		cout << "¡ñ";
		break;
	case white:
		cout << "¡ð";
		break;
	case cblack:
		cout << "¡ø";
		break;
	case cwhite:
		cout << "¡÷";
		break;
	default:
		break;
	}
	
	for (int col = 1; col < 14; col++)
	{
		switch (dispBoard[0][col])
		{
		case blank:
			cout << "©Ó©¥";
			break;
		case black:
			cout << "¡ñ";
			break;
		case white:
			cout << "¡ð";
			break;
		case cblack:
			cout << "¡ø";
			break;
		case cwhite:
			cout << "¡÷";
			break;
		default:
			break;
		}
	}

	switch (dispBoard[0][14])
	{
	case blank:
		cout << "©·";
		break;
	case black:
		cout << "¡ñ";
		break;
	case white:
		cout << "¡ð";
		break;
	case cblack:
		cout << "¡ø";
		break;
	case cwhite:
		cout << "¡÷";
		break;
	default:
		break;
	}
	cout << endl;

	// display 2-14 rows
	for (int row = 1; row < 14; row++)
	{
		cout << 14 - row + 1;
		if (15 - row < 10)
			cout << " ";
		switch (dispBoard[row][0])
		{
		case blank:
			cout << "©Ä©¤";
			break;
		case black:
			cout << "¡ñ";
			break;
		case white:
			cout << "¡ð";
			break;
		case cblack:
			cout << "¡ø";
			break;
		case cwhite:
			cout << "¡÷";
			break;
		default:
			break;
		}

		for (int col = 1; col < 14; col++)
		{
			switch (dispBoard[row][col])
			{
			case blank:
				cout << "©à©¤";
				break;
			case black:
				cout << "¡ñ";
				break;
			case white:
				cout << "¡ð";
				break;
			case cblack:
				cout << "¡ø";
				break;
			case cwhite:
				cout << "¡÷";
				break;
			default:
				break;
			}
		}

		switch (dispBoard[row][14])
		{
		case blank:
			cout << "©Ì";
			break;
		case black:
			cout << "¡ñ";
			break;
		case white:
			cout << "¡ð";
			break;
		case cblack:
			cout << "¡ø";
			break;
		case cwhite:
			cout << "¡÷";
			break;
		default:
			break;
		}
		cout << endl;
	}

	// display 15 row
	cout << 1 << " ";
	switch (dispBoard[14][0])
	{
	case blank:
		cout << "©»©¥";
		break;
	case black:
		cout << "¡ñ";
		break;
	case white:
		cout << "¡ð";
		break;
	case cblack:
		cout << "¡ø";
		break;
	case cwhite:
		cout << "¡÷";
		break;
	default:
		break;
	}

	for (int col = 1; col < 14; col++)
	{
		switch (dispBoard[14][col])
		{
		case blank:
			cout << "©Û©¥";
			break;
		case black:
			cout << "¡ñ";
			break;
		case white:
			cout << "¡ð";
			break;
		case cblack:
			cout << "¡ø";
			break;
		case cwhite:
			cout << "¡÷";
			break;
		default:
			break;
		}
	}

	switch (dispBoard[14][14])
	{
	case blank:
		cout << "©¿";
		break;
	case black:
		cout << "¡ñ";
		break;
	case white:
		cout << "¡ð";
		break;
	case cblack:
		cout << "¡ø";
		break;
	case cwhite:
		cout << "¡÷";
		break;
	default:
		break;
	}
	cout << endl;
	cout << "  A B C D E F G H I J K L M N O" << endl;
}

void CDisplay::showWin(int player)
{
	cout << "Player" << player << "Wins!" << endl;
}

void CDisplay::showInvalid()
{
	cout << "Invalid move, please input again." << endl;
}

void CDisplay::showForbidden()
{
	cout << "You tried to place a forbidden piece, and you lose." << endl;
}

void CDisplay::showDraw()
{
	cout << "Nobody wins, it's draw." << endl;
}