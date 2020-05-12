#include "AddEventCommand.h"

AddEventCommand::AddEventCommand(System & receiver):receiver(receiver)
{
}

void AddEventCommand::execute()
{
	receiver.addEvent(new Event(parameters[1], Date(stoi(parameters[2]), stoi(parameters[3]), stoi(parameters[4])),
		Hall(stoi(parameters[5]), stoi(parameters[6]),stoi(parameters[7]))));
}

void AddEventCommand::unexecute()
{
}

std::string AddEventCommand::toString()
{
	return "addevent";
}

