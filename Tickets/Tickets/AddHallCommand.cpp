#include "AddHallCommand.h"

AddHallCommand::AddHallCommand(System & receiver):receiver(receiver)
{
}

void AddHallCommand::execute()
{
	receiver.addHall(new Hall(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3])));
}

void AddHallCommand::unexecute()
{
}

std::string AddHallCommand::toString()
{
	return "addhall";
}
