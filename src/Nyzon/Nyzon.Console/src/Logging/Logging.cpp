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
void PrintLine(std::string text, ConsoleColors foreground)
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
void PrintLine(std::string text, ConsoleColors foreground, ConsolePrefixes prefix)
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

// Prints a line to the console and sets the appropiated foreground color to the prefix
void PrintColoredPrefix(std::string text, ConsolePrefixes prefix)
{
	if (prefix == Warning)
		std::cout << "[" << currentDateTime() << "]" << termcolor::yellow << " [" << GetPrefix(prefix) << "] " << termcolor::reset << text << termcolor::reset << std::endl;
	else if (prefix == Error)
		std::cout << "[" << currentDateTime() << "]" << termcolor::red << " [" << GetPrefix(prefix) << "] " << termcolor::reset << text << termcolor::reset << std::endl;
	else if (prefix == Trace)
		std::cout << "[" << currentDateTime() << "]" << termcolor::magenta << " [" << GetPrefix(prefix) << "] " << termcolor::reset << text << termcolor::reset << std::endl;
	else
		PrintLine(text, White, prefix);
}

// Prints a line to the console
void PrintLine(std::string text)
{
	PrintLine(text, White, Info);
}

// Logs a debug message to the console
void LogDebug(std::string text)
{
	PrintColoredPrefix(text, Debug);
}

// Logs an informative message to the console
void LogInformation(std::string text)
{
	PrintColoredPrefix(text, Info);
}

// Logs a trace message to the console
void LogTrace(std::string text)
{
	PrintColoredPrefix(text, Trace);
}

// Logs a warning message to the console
void LogWarning(std::string text)
{
	PrintColoredPrefix(text, Warning);
}

// Logs a error message to the console
void LogError(std::string text)
{
	PrintColoredPrefix(text, Error);
}