#pragma once
#include "ICommand.h"
#include "System.h"
class SaveCommand :
	public ICommand
{
private:
	System& receiver;

public:
	SaveCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

