#include "stdafx.h"
#include "ThreadHandler.h"


ThreadHandler::ThreadHandler()
{
}

void ThreadHandler::Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param)
{
	m_threads.push_back(CreateThread(NULL, 0, threadProc, param, 0, 0));
}

void ThreadHandler::JoinAll()
{
	WaitForMultipleObjects((DWORD)m_threads.size(), m_threads.data(), true, INFINITE);
}


ThreadHandler::~ThreadHandler()
{
}
