#pragma once
#include "ICommand.h"
#include "System.h"
class CheckCommand :
	public ICommand
{
private:
	System& receiver;
public:
	CheckCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

