#include "stdafx.h"
#include "IMonteCarloCalculatePiStrategy.h"
#include "SingleThreadedCalculatePiStrategy.h"
#include "MultiThreadedCalculatePiStrategy.h"
#include "Chronometer.h"

std::unique_ptr<IMonteCarloCalculatePiStrategy> GetStrategy(size_t iterationsCount, size_t threadsCount)
{
	if (threadsCount == 1)
	{
		return std::make_unique<SingleThreadedCalculatePiStrategy>(iterationsCount);
	}
	return std::make_unique<MultiThreadedCalculatePiStrategy>(iterationsCount, threadsCount);
}

void CalculatePiAndDumpToStdout(size_t iterationsCount, size_t threadsCount)
{
	auto pStrategy = GetStrategy(iterationsCount, threadsCount);

	Chronometer chronometer;
	const float pi = pStrategy->Calculate();
	std::cout << "Calculated PI: " << pi << std::endl;
	std::cout << "Time taken: " << chronometer.GrabDeltaTime().count() << " seconds" << std::endl;
}

void DumpHelpToStrm(std::ostream& strm)
{
	strm << "Usage: 'CalculatePiMonteCarloMethod.exe <iterations> <threads>'\n"
		"or 'CalculatePiMonteCarloMethod.exe --help' for help" << std::endl;
}

int main(int argc, char* argv[])
{
	try
	{
		if (argc == 2 && strcmp(argv[1], "--help") == 0)
		{
			DumpHelpToStrm(std::cout);
		}
		else if (argc == 3)
		{
			CalculatePiAndDumpToStdout(std::stoi(argv[1]), std::stoi(argv[2]));
		}
		else
		{
			std::cerr << "Can't recognize arguments...\n";
			DumpHelpToStrm(std::cerr);
			return 1;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
