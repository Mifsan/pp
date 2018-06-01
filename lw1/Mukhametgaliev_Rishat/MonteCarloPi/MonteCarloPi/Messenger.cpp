#include "stdafx.h"
#include "Messenger.h"

static const std::string MAX_ITERATIONS_COUNT = std::to_string(std::numeric_limits<std::size_t>::max());
static const std::string MIN_ITERATIONS_COUNT = std::to_string(1);

static const std::string MAX_THREADS_COUNT = std::to_string(std::numeric_limits<std::size_t>::max());
static const std::string MIN_THREADS_COUNT = std::to_string(1);

static const std::string ITERATIONS_COUNT_INFO = "<iterations count>: [" + MIN_ITERATIONS_COUNT + "; " + MAX_ITERATIONS_COUNT + "]\n";
static const std::string THREADS_COUNT_INFO = "<threads count>: [" + MIN_THREADS_COUNT + "; " + MAX_THREADS_COUNT + "]\n";

static const std::string HELP_MESSAGE = "Usage: MonteCarloPi.exe <iterations count> <threads count>\n" + ITERATIONS_COUNT_INFO + THREADS_COUNT_INFO;
static const std::string ERROR_MESSAGE = "Invalid arguments\n" + HELP_MESSAGE;

Messenger::Messenger()
{
}


Messenger::~Messenger()
{
}

void Messenger::PrintHelpMessage()
{
	std::cout << HELP_MESSAGE;
}

void Messenger::PrintErrorMessage()
{
	std::cout << ERROR_MESSAGE;
}
