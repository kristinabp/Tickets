#pragma once
#include "ICommand.h"
#include "System.h"
class UnbookCommand :
	public ICommand
{
private:
	System& receiver;
public:
	UnbookCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

