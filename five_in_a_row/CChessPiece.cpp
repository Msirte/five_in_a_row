#include "CChessPiece.h"

CChessPiece::CChessPiece(int owner, int type, CPoint<int> pos) :CUnit(owner, type, pos){}

CChessPiece::CChessPiece() : CUnit() {}
