#include "SaveCommand.h"



SaveCommand::SaveCommand(System& receiver) : receiver(receiver)
{
}

void SaveCommand::execute()
{
	receiver.save();
}

void SaveCommand::unexecute()
{
}

std::string SaveCommand::toString()
{
	return "save";
}
