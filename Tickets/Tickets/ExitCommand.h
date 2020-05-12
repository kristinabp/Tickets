#pragma once
#include "ICommand.h"
#include "System.h"
class ExitCommand :
	public ICommand
{
private:
	System& receiver;
public:
	ExitCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

