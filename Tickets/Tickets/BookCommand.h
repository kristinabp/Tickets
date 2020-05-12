#pragma once
#include "ICommand.h"
#include "System.h"

class BookCommand :
	public ICommand
{
private:
	System& receiver;
public:
	BookCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

