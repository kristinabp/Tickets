#pragma once
#include "ICommand.h"
#include "System.h"
class MostWatchedCommand :
	public ICommand
{
private:
	System& receiver;
public:
	MostWatchedCommand(System& receiver);
	void execute();
	void unexecute();

	std::string toString();
};

