/// MG: IMPORTANT! Make sure #pragma once is the FIRST line, otherwise you risk breakages in move complex situations. 
///		This is because #pragma once prevents code being duplicated when it links. Anything before it can still be duplicated. 
// 		So your includes will be duplicated if you #include TicTacToe.h in more than one .cpp file
///		I can explain in more detail in person, but don't put #includes above it!
/// #pragma once
#pragma once

#include "InputHandler.h"
#include "OutputHandler.h"

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
	void NewGame();
	void PlayAgain();

	InputHandler inputHandler;
	OutputHandler outputHandler;

public:
	/// MG: NewGame could be private, as nothing external calls it. Prefer private over public where possible
	
	void Update();
	void Render();
	bool IsGameOver();

	TicTacToe();
};

