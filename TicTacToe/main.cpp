#include <iostream>
#include "TicTacToe.h"

/// MG: Good clean main function. Overall comments for the project are below!

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


/* MG:
	Overall this is is a solid implementation of the task sheet's requirements. You code is logical, clear and consistently formatted.
	Good work! 
	The main are for improvements I see in this project is commenting. 
	When you are coding, it is always useful to add comments to epalain the purposes of anything that may be unclear.

	Bear in mind that "Unclear", if not unclear for you, as you are writing it. It is unclear to a coder looking at the code for the first time, or to you, looking at 
	it again in 3 months time. 

	As a bear minimum, you should add the purpose of your classes as comments to the header files, and any algorithms you write, just add a note explainign what they are for.
	In general, think about adding comments to any public functions within a class (again in the header) also, as that is the code modt likely to be used by others. 

	Also, ensure the result is user friendly!
	For example, when I enter an incorrect input, I am asked to enter either 0 or 1, rather than 0-8. Similarly, the render functions asks the player for 0-9, which is 
	10 options! Making sure what you create is suitable for users is a core part of being a programmer, whether the user is a player, like in this case, or another coder, if you are making an api or working in a team!

	That said, you've done well here overall. Good work! I would like to see the restart implemented though!
*/