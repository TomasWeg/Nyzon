#pragma once

// Include common libraries for input/output stream
#include "..\include_headers.h"
#include "..\libraries\termcolor\termcolor.hpp"

// Enumerator containing all the availables console colors
enum ConsoleColors { Red, Green, Yellow, Blue, Magenta, Cyan, White };

// Enumerator containing all the availables prefixes
enum ConsolePrefixes { Info, Debug, Warning, Error, Trace };

// Returns the string name of an prefix enumerator
std::string GetPrefix(ConsolePrefixes prefix);

// Prints a line to the console with custom foreground
void PrintLine(std::string text, ConsoleColors foreground);

// Prints a line to the console with custom foreground and a prefix
void PrintLine(std::string text, ConsoleColors foreground, ConsolePrefixes prefix);

// Prints a line to the console and sets the appropiated foreground color to the prefix
void PrintColoredPrefix(std::string text, ConsolePrefixes prefix);

// Prints a line to the console
void PrintLine(std::string text);

void LogDebug(std::string text);
void LogInformation(std::string text);
void LogWarning(std::string text);
void LogError(std::string text);
void LogTrace(std::string text);