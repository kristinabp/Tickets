#pragma once
#include "ICommand.h"
#include "System.h"
class BookingCommand :
	public ICommand
{
private:
	System& receiver;
public:
	BookingCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

