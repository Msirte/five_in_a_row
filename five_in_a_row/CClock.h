#pragma once

class CClock
{
public:
	CClock();
	long getSysTime();
	void startTimer();
	long pauseTimer();
	void continueTimer();
	long stopTimer();
private:
	long m_start;
	long m_length;
	bool isPause;
	bool isStop;
};