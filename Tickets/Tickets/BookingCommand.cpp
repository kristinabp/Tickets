#include "BookingCommand.h"



BookingCommand::BookingCommand(System& receiver): receiver(receiver)
{
}

void BookingCommand::execute()
{
	if (parameters.size() == 5)
	{
		receiver.bookings(parameters[1], Date(stoi(parameters[2]), stoi(parameters[3]), stoi(parameters[4])));
	}
	else if (parameters.size() == 2)
	{
		receiver.bookings(parameters[1]);
	}
	else if (parameters.size() == 4)
	{
		receiver.bookings(Date(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3])));
	}
}

void BookingCommand::unexecute()
{
}

std::string BookingCommand::toString()
{
	return "bookings";
}
