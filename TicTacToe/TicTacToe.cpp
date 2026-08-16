#include "TicTacToe.h"

/// MG: Remember to always use the constructor initialiser list - it's a safety mechanism as well as useful for initial values:
TicTacToe::TicTacToe() /// : m_gridSize(9), m_isP1Turn(false), m_isGameOver(false) 
					   /// MG: Notice I set m_isP1Turn to false, even though it is true. This is because false is a sensible default, 
					   //      even if you know NewGame will set it later! I set m_gridSize to 9 however, because then you can remove it from NewGame, as it will never change!
{
	m_gridSize = 9;
	m_isP1Turn = false;
	m_isGameOver = false;

	NewGame();
}

void TicTacToe::NewGame()
{
	/// MG: Not required due to constructor. If something will never change, set it once only. For bonus points, make it const ( in header: const int m_gridSize ). Then it cannot change outside the constructor initialiser list!
	/// m_gridSize = 9; 
	m_isP1Turn = true;
	m_isGameOver = false;

	/// MG: Good!
	for (int i = 0; i < m_gridSize; i++)
	{
		m_grid[i] = ' ';
	}
}

bool TicTacToe::IsGameOver()
{
	return m_isGameOver;
}

void TicTacToe::Update()
{
	bool goodInput = false;
	int intInput;

	/// MG: Nice, see how this is the same pattern as you used inside the InputHandler. A future improvement could be to move this into that class and just have "GetIntInRange(0,8)"!
	while (!goodInput)
	{
		intInput = inputHandler.GetInputInt() - 1;
		goodInput = CheckValidLocation(intInput);

		if (!goodInput)
		{
			outputHandler.OutputText("Invalid Input - Enter a number between 1 and 9\n");
		}
	}

	if (m_isP1Turn)
	{
		m_grid[intInput] = 'O';
	}
	else
	{
		m_grid[intInput] = 'X';
	}

	// Change to next players turn
	m_isP1Turn = !m_isP1Turn;
	ProcessGameOver();
}


bool TicTacToe::CheckValidLocation(int location)
{
	/// MG: This works, but can be streamlined a lot. 

	///     A lot of students miss this logic, so really try to get to grips with it!
	///		if ( STATEMENT ) { X } is a check yes? If STATEMENT is true, do X, otherwise skip it.

	///		That means STATEMENT *MUST* be either true or false. It cannot be any other value.
	///		So your possible outcomes are: 
	/// 		
	/// 		"if ( true ) { return true; } SKIP;" 
	///		or 
	/// 		"if ( false ) { SKIP }  return false;"

	///		Do you see how the "if" here is overengineered?
	/// 	A better solution is to remove the if entirely:

	///			return STATEMENT;

	/// 	Now, if STATEMENT is true, you still return true, and if STATEMENT is false, you return false. No "if" required!
	///		Your function becomes:

	///			bool TicTacToe::CheckValidLocation(int location)
	///			{
	///				return (location >= 0 && location < 9) && m_grid[location] == ' ';
	///			}

	//if (
	//	(location >= 0 && location < 9) &&
	//	m_grid[location] == ' '
	//	)
	//{
	//	return true;
	//}
	//return false;

	return (location >= 0 && location < 9) && m_grid[location] == ' ';
}

bool TicTacToe::CompareLine(int location1, int location2, int location3)
{
	if (m_grid[location1] != ' ' && m_grid[location1] == m_grid[location2] && m_grid[location1] == m_grid[location3])
	{
		return true;
	}
	return false;
}

bool TicTacToe::CheckForTie()
{
	bool tie = false;
	for (int i = 0; i < 9; i++)
	{
		tie |= m_grid[i] == ' ';
	}

	return !tie;
}

void TicTacToe::ProcessGameOver()
{
	bool isComplete = false;
	isComplete |= CompareLine(0, 1, 2);
	isComplete |= CompareLine(3, 4, 5);
	isComplete |= CompareLine(6, 7, 8);
	isComplete |= CompareLine(0, 3, 6);
	isComplete |= CompareLine(1, 4, 7);
	isComplete |= CompareLine(2, 5, 8);
	isComplete |= CompareLine(0, 4, 8);
	isComplete |= CompareLine(2, 4, 6);

	bool restart = false;

	if (isComplete)
	{
		outputHandler.ClearScreen();
		outputHandler.OutputGrid(m_grid);
		if (m_isP1Turn)
		{
			outputHandler.OutputText("Player 1 Wins");
		}
		else
		{
			outputHandler.OutputText("Player 2 Wins");
		}

		PlayAgain();

	}
	else if (CheckForTie())
	{
		outputHandler.ClearScreen();
		outputHandler.OutputGrid(m_grid);
		outputHandler.OutputText("Tie");

		PlayAgain();
	}


	
}

void TicTacToe::PlayAgain()
{
	outputHandler.OutputText("\nPlay Again (Y/N)\n");
	char input = inputHandler.GetInputChar();
	outputHandler.OutputText("Text");
	if (input == 'Y')
	{
		NewGame();
	}
	else
	{
		m_isGameOver = true;
	}
	return;
}

void TicTacToe::Render()
{
	outputHandler.ClearScreen();
	outputHandler.OutputGrid(m_grid);
	if (m_isP1Turn)
	{
		outputHandler.OutputText("Player 1, choose your location (1-9)\n");
	}
	else
	{
		outputHandler.OutputText("Player 2, choose your location (1-9)\n");
	}
}