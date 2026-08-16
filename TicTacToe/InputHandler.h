#pragma once
class InputHandler
{
private:
	/// MG: See the comments on the cpp for why this exists.
	///     bool CheckInputValid();
	bool CheckInputValid();
public:
	int GetInputInt();
	char GetInputChar();
};

