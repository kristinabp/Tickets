#include "OpenCommand.h"

OpenCommand::OpenCommand(System & receiver):receiver(receiver)
{
}

void OpenCommand::execute()
{
	receiver.open(parameters[1]);
}

void OpenCommand::unexecute()
{
}

std::string OpenCommand::toString()
{
	return "open";
}
