#include "ReportCommand.h"



ReportCommand::ReportCommand(System& receiver) :receiver(receiver)
{
}

void ReportCommand::execute()
{
	if (parameters.size() == 7)
	{
		receiver.report(Date(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3])),
			Date(stoi(parameters[4]), stoi(parameters[5]), stoi(parameters[6])));
	}
	else if (parameters.size() == 8)
	{
		receiver.report(Date(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3])),
			Date(stoi(parameters[4]), stoi(parameters[5]), stoi(parameters[6])), stoi(parameters[7]));
	}
}

void ReportCommand::unexecute()
{
}

std::string ReportCommand::toString()
{
	return "report";
}
