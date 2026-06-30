#include <iostream>
#include "TicTacToe.h"

int main()
{
	TicTacToe game;

	while (!game.IsGameOver())
	{
		game.Render();
		game.Update();
	}

	return 0;
}