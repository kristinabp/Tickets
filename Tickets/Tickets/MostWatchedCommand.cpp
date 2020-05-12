#include "MostWatchedCommand.h"



MostWatchedCommand::MostWatchedCommand(System& receiver) :receiver(receiver)
{
}

void MostWatchedCommand::execute()
{
	receiver.mostWatched();
}

void MostWatchedCommand::unexecute()
{
}

std::string MostWatchedCommand::toString()
{
	return "mostwatched";
}
