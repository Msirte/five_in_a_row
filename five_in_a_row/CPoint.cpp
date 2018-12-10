#include"CPoint.h"
#include<math.h>

template<class T>
CPoint<T>::CPoint(T x, T y)
{
	m_x = x;
	m_y = y;
}

template<class T>
CPoint<T>::CPoint(const CPoint & point)
{
	this->m_x = point.m_x;
	this->m_y = point.m_y;
}

template<class T>
CPoint<T>::~CPoint()
{
	delete m_x;
	delete m_y;
}

template<class T>
void CPoint<T>::Set(T x, T y)
{
	m_x = x;
	m_y = y;
}

template<class T>
T CPoint<T>::GetX()
{
	return m_x;
}

template<class T>
T CPoint<T>::GetY()
{
	return m_y;
}

template<class T>
double CPoint<T>::Distance(const CPoint & point) const
{
	double dx = (double)(this->m_x - point.m_x);
	double dy = (double)(this->m_y - point.m_y);
	return sqrt(dx*dx + dy*dy);
}

template<class T>
void CPoint<T>::Move(T x, T y)
{
	m_x += x;
	m_y += y;
}

template<class T>
CPoint<T>& CPoint<T>::operator=(const CPoint & point)
{
	this->m_x = point.m_x;
	this->m_y = point.m_y;
	return *this;
}

template<class T>
CPoint<T> CPoint<T>::operator+(const CPoint & point) const
{
	T x = this->m_x + point.m_x;
	T y = this->m_y + point.m_y;
	return CPoint(x, y);
}

template<class T>
CPoint<T> CPoint<T>::operator-(const CPoint & point) const
{
	T x = this->m_x - point.m_x;
	T y = this->m_y - point.m_y;
	return CPoint(x, y);
}

template<class T>
CPoint<T> CPoint<T>::operator*(T n) const
{
	T x = this->m_x * n;
	T y = this->m_y * n;
	return CPoint(x, y);
}

template<class T>
CPoint<T> CPoint<T>::operator/(T n) const
{
	T x = this->m_x / n;
	T y = this->m_y / n;
	return CPoint(x, y);
}

template<class T>
bool CPoint<T>::operator==(const CPoint & point) const
{
	if (this->m_x == point.m_x && this->m_y == point.m_y)
		return true;
	else
		return false;
}

template<class T>
bool CPoint<T>::operator!=(const CPoint & point) const
{
	if (this->m_x == point.m_x && this->m_y == point.m_y)
		return false;
	else
		return true;
}