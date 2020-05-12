#include "UnbookCommand.h"



UnbookCommand::UnbookCommand(System& receiver):receiver(receiver)
{
}

void UnbookCommand::execute()
{
	receiver.unbook(parameters[1], Date(stoi(parameters[2]), stoi(parameters[3]), stoi(parameters[4])),
		stoi(parameters[5]), stoi(parameters[6]));
}

void UnbookCommand::unexecute()
{
}

std::string UnbookCommand::toString()
{
	return "unbook";
}
