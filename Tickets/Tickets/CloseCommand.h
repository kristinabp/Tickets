#pragma once
#include "ICommand.h"
#include "System.h"
class CloseCommand :
	public ICommand
{
private:
	System& receiver;
public:
	CloseCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

