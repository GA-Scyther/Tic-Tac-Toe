/// MG: This is solid, and fulfils the goal, but always try to thing about reusability going forwards.

///		Notice that lines 18 through 25 are identical to 36 through 47? Because they don't use the variable "input", which *is* different, 
///		we could extract that into a private helper function:

		/*  
		bool InputHandler::CheckInputValid()
		{
			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				return false;
			}
			return true;
		}	
		*/ 

/// Then your code becomes:

/* 
		int InputHandler::GetInputInt()
		{
			bool goodInput = false;
			int input;
			while (!goodInput)
			{
				goodInput = CheckInputValid();
			}
			return input;
		}
		char InputHandler::GetInputChar()
		{
			bool goodInput = false;
			int input;
			while (!goodInput)
			{
				goodInput = CheckInputValid();
			}
			return input;
		}
	*/

/// Which is simpler, and also means if there is an issue with the cin checking, you only need to change it one place!
/// Otherwise, good job!

#include "InputHandler.h"
#include <iostream>

bool InputHandler::CheckInputValid()
{
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return false;
	}
	return true;
}

// Returns -1 if number is incorrect
int InputHandler::GetInputInt()
{
	bool goodInput = false;
	int input;
	while (!goodInput)
	{
		std::cin >> input;
		goodInput = CheckInputValid();
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
		goodInput = CheckInputValid();
	}

	return input;
}