#include "FreeSeatsCommand.h"



FreeSeatsCommand::FreeSeatsCommand(System& receiver):receiver(receiver)
{
}

void FreeSeatsCommand::execute()
{
	receiver.freeSeats(parameters[1], Date(stoi(parameters[2]),stoi(parameters[3]),stoi(parameters[4])));
}

void FreeSeatsCommand::unexecute()
{
}

std::string FreeSeatsCommand::toString()
{
	return "freeseats";
}
