#include "SaveAsCommand.h"

SaveAsCommand::SaveAsCommand(System &receiver):receiver(receiver)
{
}

void SaveAsCommand::execute()
{
	receiver.saveAs(parameters[1]);
}

void SaveAsCommand::unexecute()
{
}

std::string SaveAsCommand::toString()
{
	return "saveas";
}
