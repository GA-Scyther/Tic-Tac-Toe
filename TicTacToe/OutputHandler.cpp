#include "OutputHandler.h"
#include <iostream>

/// MG: Solid file, does exactly what is required!

void OutputHandler::OutputText(const char* input)
{
	std::cout << input;
}

void OutputHandler::OutputGrid(char grid[9])
{
	/// MG: The i += 3 is a good solution for this. Nice!
	for (int i = 0; i < 9; i += 3)
	{
		std::cout << grid[i] << " | " << grid[i + 1] << " | " << grid[i + 2] << std::endl;
		std::cout << "---------" << std::endl;
	}
}


void OutputHandler::ClearScreen()
{
	system("cls");
}