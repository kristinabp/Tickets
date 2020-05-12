#pragma once
#include "ICommand.h"
#include "System.h"

class BuyCommand :
	public ICommand
{
private:
	System& receiver;
public:
	BuyCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

