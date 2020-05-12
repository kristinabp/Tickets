#pragma once
#include "ICommand.h"
#include "System.h"
class UnderTenCommand :
	public ICommand
{
private:
	System& receiver;
public:
	UnderTenCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

