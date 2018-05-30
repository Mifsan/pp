#include "stdafx.h"
#include "MonteCarloPi.h"
#include "Timer.h"
#include <iostream>

const size_t ARGUMENTS_COUNT = 3;

int main(int argc, char* argv[])
{	
	Timer timer;
	timer.Start();
	MonteCarloPi monteCarlo(2638400);
	monteCarlo.GeneratePointsInCircle();
	timer.Stop();
	std::cout << "Pi = " << monteCarlo.GetResultPi() << std::endl;
	std::cout << "Time = " << timer.GetPassedTime() << " sec" << std::endl;
    return 0;
}

