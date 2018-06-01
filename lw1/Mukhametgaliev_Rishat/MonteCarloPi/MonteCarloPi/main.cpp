#include "stdafx.h"
#include "MonteCarloPi.h"
#include "Timer.h"
#include "Messenger.h"

const size_t ARGUMENTS_COUNT = 3;
const std::string HELP_FLAG = "--help";

int main(int argc, char* argv[])
{
	if (argc == 2 && argv[1] == HELP_FLAG)
	{
		Messenger::PrintHelpMessage();
		return 1;
	}
	if (argc < ARGUMENTS_COUNT)
	{
		Messenger::PrintErrorMessage();
		return 1;
	}
	try
	{
		size_t iterationsCount = std::stoull(argv[1]);
		size_t threadsCount = std::stoull(argv[2]);
		if (iterationsCount < 1 || threadsCount < 1)
		{
			throw std::invalid_argument("");
		}
		Timer timer;
		timer.Start();
		MonteCarloPi monteCarlo(iterationsCount, threadsCount);
		monteCarlo.Run();
		timer.Stop();
		std::cout << "Pi = " << monteCarlo.GetResultPi() << std::endl;
		std::cout << "Time = " << timer.GetPassedTime() << " sec" << std::endl;
	}
	catch (std::exception const &ex)
	{
		std::cout << ex.what();
		Messenger::PrintErrorMessage();
	}
	return 0;
}
