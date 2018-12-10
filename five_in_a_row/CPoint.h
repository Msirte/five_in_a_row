#pragma once
#include<math.h>

template<class T>
class CPoint
{
public:
	CPoint();
	CPoint(T, T);
	CPoint(const CPoint &);
	void set(T, T);
	T getx();
	T gety();
	double distance(const CPoint &) const;
	void move(T, T);
	CPoint& operator=(const CPoint &);
	CPoint operator+(const CPoint &) const;
	CPoint operator-(const CPoint &) const;
	bool operator==(const CPoint &) const;
	bool operator!=(const CPoint &) const;
private:
	T m_x;
	T m_y;
};

template<class T>
CPoint<T>::CPoint()
{
	m_x = 0;
	m_y = 0;
}

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
void CPoint<T>::set(T x, T y)
{
	m_x = x;
	m_y = y;
}

template<class T>
T CPoint<T>::getx()
{
	return m_x;
}

template<class T>
T CPoint<T>::gety()
{
	return m_y;
}

template<class T>
double CPoint<T>::distance(const CPoint & point) const
{
	double dx = (double)(this->m_x - point.m_x);
	double dy = (double)(this->m_y - point.m_y);
	return sqrt(dx*dx + dy*dy);
}

template<class T>
void CPoint<T>::move(T x, T y)
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