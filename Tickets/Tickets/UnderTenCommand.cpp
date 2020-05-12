#include "UnderTenCommand.h"



UnderTenCommand::UnderTenCommand(System& receiver):receiver(receiver)
{
}

void UnderTenCommand::execute()
{
	receiver.underTen(Date(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3])), 
		 Date(stoi(parameters[4]), stoi(parameters[5]), stoi(parameters[6])), std::cout);
}

void UnderTenCommand::unexecute()
{
}

std::string UnderTenCommand::toString()
{
	return "underTen";
}
