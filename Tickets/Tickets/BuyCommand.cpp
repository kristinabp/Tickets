#include "BuyCommand.h"



BuyCommand::BuyCommand(System& receiver): receiver(receiver)
{
}

void BuyCommand::execute()
{
	receiver.buy(parameters[1], Date(stoi(parameters[2]), stoi(parameters[3]), stoi(parameters[4])),
		stoi(parameters[5]), stoi(parameters[6]), parameters[7]);
}

void BuyCommand::unexecute()
{
}

std::string BuyCommand::toString()
{
	return "buy";
}
