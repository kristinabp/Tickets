#include "ExitCommand.h"



ExitCommand::ExitCommand(System& receiver):receiver(receiver)
{
}

void ExitCommand::execute()
{
	receiver.exit();
}

void ExitCommand::unexecute()
{
}

std::string ExitCommand::toString()
{
	return "exit";
}
