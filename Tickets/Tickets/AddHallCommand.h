#pragma once
#include "ICommand.h"
#include "System.h"
class AddHallCommand:
	public ICommand
{
private:
	System& receiver;
public:
	AddHallCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

