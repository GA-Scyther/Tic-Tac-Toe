#include "InputHandler.h"
#include <iostream>

// Returns -1 if number is incorrect
int InputHandler::GetInputInt()
{
	bool goodInput = false;
	int input;

	while (!goodInput)
	{
		std::cin >> input;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}

		goodInput = true;
	}

	return input;
}

char InputHandler::GetInputChar()
{
	bool goodInput = false;
	char input;

	while (!goodInput)
	{
		std::cin >> input;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;
		}

		goodInput = true;
	}

	return input;
}