#pragma once

template<class T>
class CArray
{
public:
	CArray();
	CArray(int);
	CArray(const CArray &);
	~CArray();
	CArray& operator=(const CArray &);
	T& operator[](int);
	const T& operator[](int) const;
	int getLength();
	void reallocate();
	void pushBack(T);
	T popBack();
	T& last();
	const T& last() const;
	void insert(int, T);
	void erase(int);
	void clear();
private:
	int m_size;
	int m_capacity;
	T* pdata;
};

template<class T>
CArray<T>::CArray()
{
	m_size = 0;
	m_capacity = 0;
	pdata = nullptr;
}

template<class T>
CArray<T>::CArray(int n)
{
	m_size = n;
	m_capacity = 2 * n + 1;
	pdata = new T[m_capacity];
}

template<class T>
CArray<T>::CArray(const CArray & arr)
{
	this->m_size = arr.m_size;
	this->m_capacity = arr.m_capacity;
	pdata = new T[m_capacity];
	for (int i = 0; i < m_size; i++)
		pdata[i] = arr.pdata[i]
}

template<class T>
CArray<T>::~CArray()
{
	if (pdata != nullptr)
		delete[] pdata;
	pdata = nullptr;
}

template<class T>
CArray<T>& CArray<T>::operator=(const CArray & arr)
{
	if (this == &arr)
		return *this;
	m_size = arr.m_size;
	m_capacity = arr.m_capacity;
	if (pdata != nullptr)
	{
		delete[] pdata;
		pdata = nullptr;
	}
	pdata = new T[m_capacity];
	for (int i = 0; i < m_size; i++)
		pdata[i] = arr.pdata[i];
	return *this;
}

template<class T>
T& CArray<T>::operator[](int n)
{
	return pdata[n];
}

template<class T>
const T& CArray<T>::operator[](int n) const
{
	return pdata[n];
}

template<class T>
int CArray<T>::getLength()
{
	return m_size;
}

template<class T>
void CArray<T>::reallocate()
{
	if (m_size == m_capacity)
	{
		T* old = pdata;
		m_capacity = 2 * m_capacity + 1;
		pdata = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
			pdata[i] = old[i];
		if (old != nullptr)
			delete[] old;
	}
}

template<class T>
void CArray<T>::pushBack(T var)
{
	this->reallocate();
	pdata[m_size] = var;
	m_size++;
}

template<class T>
T CArray<T>::popBack()
{
	T out = pdata[m_size - 1];
	m_size--;
	return out;
}

template<class T>
T& CArray<T>::last()
{
	return pdata[m_size - 1];
}

template<class T>
const T& CArray<T>::last() const
{
	return pdata[m_size - 1];
}

template<class T>
void CArray<T>::insert(int n, T var)
{
	this->reallocate();
	for (int i = m_size; i > n; i--)
		pdata[i] = pdata[i - 1];
	pdata[n] = var;
	m_size++;
}

template<class T>
void CArray<T>::erase(int n)
{
	this->reallocate();
	for (int i = n; i < m_size; i++)
		pdata[i] = pdata[i + 1];
	m_size--;
}

template<class T>
void CArray<T>::clear()
{
	m_size = 0;
	m_capacity = 0;
	if (pdata != nullptr)
		delete[] pdata;
	pdata = nullptr;
}
