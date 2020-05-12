#pragma once
#include "ICommand.h"
#include "System.h"
class FreeSeatsCommand :
	public ICommand
{
private:
	System& receiver;
public:
	FreeSeatsCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

