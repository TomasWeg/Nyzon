#include "Logging.h"
#include "..\datetime\datetime.h"

// Returns the string name of an prefix enumerator
std::string GetPrefix(ConsolePrefixes prefix)
{
	switch (prefix)
	{
	case Info:
		return "Information";
	case Debug:
		return "Debug";
	case Warning:
		return "Warning";
	case Error:
		return "Error";
	case Trace:
		return "Trace";

	default:
		return "Debug";
	}
}

// Prints a line to the console with custom foreground
void PrintLine(const char* text, ConsoleColors foreground)
{
	if (foreground == Red)
		std::cout << "[" << currentDateTime() << "] " << termcolor::red << text << termcolor::reset << std::endl;
	else if (foreground == Green)
		std::cout << "[" << currentDateTime() << "] " << termcolor::green << text << termcolor::reset << std::endl;
	else if (foreground == Yellow)
		std::cout << "[" << currentDateTime() << "] " << termcolor::yellow << text << termcolor::reset << std::endl;
	else if (foreground == Blue)
		std::cout << "[" << currentDateTime() << "] " << termcolor::blue << text << termcolor::reset << std::endl;
	else if (foreground == Magenta)
		std::cout << "[" << currentDateTime() << "] " << termcolor::magenta << text << termcolor::reset << std::endl;
	else if (foreground == Cyan)
		std::cout << "[" << currentDateTime() << "] " << termcolor::cyan << text << termcolor::reset << std::endl;
	else if (foreground == White)
		std::cout << "[" << currentDateTime() << "] " << termcolor::white << text << termcolor::reset << std::endl;
}

// Prints a line to the console withc custom foreground and a prefix
void PrintLine(const char* text, ConsoleColors foreground, ConsolePrefixes prefix)
{
	if(foreground == Red)
		std::cout << "[" << currentDateTime() << "] [" << GetPrefix(prefix) << "] " << termcolor::red << text << termcolor::reset << std::endl;
	else if (foreground == Green)
		std::cout << "[" << currentDateTime() << "] [" << GetPrefix(prefix) << "] " << termcolor::green << text << termcolor::reset << std::endl;
	else if (foreground == Yellow)
		std::cout << "[" << currentDateTime() << "] [" << GetPrefix(prefix) << "] " << termcolor::yellow << text << termcolor::reset << std::endl;
	else if (foreground == Blue)
		std::cout << "[" << currentDateTime() << "] [" << GetPrefix(prefix) << "] " << termcolor::blue << text << termcolor::reset << std::endl;
	else if (foreground == Magenta)
		std::cout << "[" << currentDateTime() << "] [" << GetPrefix(prefix) << "] " << termcolor::magenta << text << termcolor::reset << std::endl;
	else if (foreground == Cyan)
		std::cout << "[" << currentDateTime() << "] [" << GetPrefix(prefix) << "] " << termcolor::cyan << text << termcolor::reset << std::endl;
	else if (foreground == White)
		std::cout << "[" << currentDateTime() << "] [" << GetPrefix(prefix) << "] " << termcolor::white << text << termcolor::reset << std::endl;
}

// Prints a line to the console
void PrintLine(const char* text) 
{
	PrintLine(text, White, Info);
}