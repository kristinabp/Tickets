#include "CloseCommand.h"



CloseCommand::CloseCommand(System& receiver):receiver(receiver)
{
}


void CloseCommand::execute()
{
	receiver.close();
}

void CloseCommand::unexecute()
{
}

std::string CloseCommand::toString()
{
	return "close";
}
