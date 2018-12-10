#include"CClock.h"
#include <time.h>

CClock::CClock()
{
	m_start = time(0);
	m_length = 0;
	isPause = false;
	isStop = true;
}

long CClock::getSysTime()
{
	return time(0);
}

void CClock::startTimer()
{
	m_start = time(0);
	m_length = 0;
	isPause = false;
	isStop = false;
}

long CClock::pauseTimer()
{
	if (isPause || isStop)
		return m_length;
	else
	{
		isPause = true;
		m_length += time(0) - m_start;
		return m_length;
	}
}

void CClock::continueTimer()
{
	if (!isPause || isStop)
		return;
	else
	{
		isPause = false;
		m_start = time(0);
	}
}

long CClock::stopTimer()
{
	if (isStop || isPause)
		return m_length;
	else
	{
		isStop = true;
		m_length += time(0) - m_start;
		return m_length;
	}
}