#include "CheckCommand.h"



CheckCommand::CheckCommand(System& receiver): receiver(receiver)
{
}

void CheckCommand::execute()
{
	receiver.check(parameters[1]);
}

void CheckCommand::unexecute()
{
}

std::string CheckCommand::toString()
{
	return "check";
}
