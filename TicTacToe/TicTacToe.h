#include "InputHandler.h"
#include "OutputHandler.h"

#pragma once
class TicTacToe
{
private:
	int m_gridSize;
	char m_grid[9];
	bool m_isP1Turn;
	bool m_isGameOver;

	bool CheckValidLocation(int location);
	bool CompareLine(int location1, int location2, int location3);
	void ProcessGameOver();
	bool CheckForTie();

	InputHandler inputHandler;
	OutputHandler outputHandler;

public:
	void NewGame();
	void Update();
	void Render();
	bool IsGameOver();

	TicTacToe();
};

