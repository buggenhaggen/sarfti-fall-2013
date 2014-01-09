#include <windows.h>

class CTimer
{
public:
	CTimer() 
	{
		QueryPerformanceFrequency(&mqFreq);
	}
	~CTimer() {}

	void Start() 
	{
		QueryPerformanceCounter(&mqStart);
	}
	void End() 
	{
		QueryPerformanceCounter(&mqEnd);
	}
	double GetTimeInSeconds()
	{
		return (mqEnd.QuadPart - mqStart.QuadPart)/static_cast<double>(mqFreq.QuadPart);
	}
private:
	LARGE_INTEGER mqStart;
	LARGE_INTEGER mqEnd;
	LARGE_INTEGER mqFreq;
};
