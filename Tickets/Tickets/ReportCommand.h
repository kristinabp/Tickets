#pragma once
#include "ICommand.h"
#include "System.h"
class ReportCommand :
	public ICommand
{
private:
	System& receiver;
public:
	ReportCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

