#include "BookCommand.h"



BookCommand::BookCommand(System& receiver):receiver(receiver)
{
}

void BookCommand::execute()
{
	receiver.book(parameters[1], Date(stoi(parameters[2]), stoi(parameters[3]), stoi(parameters[4])),
		stoi(parameters[5]), stoi(parameters[6]),parameters[7]);
}

void BookCommand::unexecute()
{
}

std::string BookCommand::toString()
{
	return "book";
}

