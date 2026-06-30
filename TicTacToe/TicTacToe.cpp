#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	NewGame();
}

void TicTacToe::NewGame()
{
	m_gridSize = 9;
	m_isP1Turn = true;
	m_isGameOver = false;

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
	while (!goodInput)
	{
		intInput = inputHandler.GetInputInt() - 1;
		goodInput = CheckValidLocation(intInput);

		if (!goodInput)
		{
			outputHandler.OutputText("Invalid Input - Enter a number between 0 and 1\n");
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

	ProcessGameOver();
	m_isP1Turn = !m_isP1Turn;
}


bool TicTacToe::CheckValidLocation(int location)
{
	if (
		(location >= 0 && location < 9) &&
		m_grid[location] == ' '
		)
	{
		return true;
	}
	return false;
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

		m_isGameOver = true;
	}
	else if (CheckForTie())
	{
		outputHandler.ClearScreen();
		outputHandler.OutputGrid(m_grid);
		outputHandler.OutputText("Tie");

		m_isGameOver = true;
	}
}

void TicTacToe::Render()
{
	outputHandler.ClearScreen();
	outputHandler.OutputGrid(m_grid);
	if (m_isP1Turn)
	{
		outputHandler.OutputText("Player 1, choose your location (0-9)\n");
	}
	else
	{
		outputHandler.OutputText("Player 2, choose your location (0-9)\n");
	}
}