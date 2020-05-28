#include "Invoker.h"

Invoker::Invoker(): receiver(new System())
{
	commands.push_back(new OpenCommand(*receiver));
	commands.push_back(new SaveCommand(*receiver));
	commands.push_back(new SaveAsCommand(*receiver));
	commands.push_back(new CloseCommand(*receiver));
	commands.push_back(new HelpCommand(*receiver));
	commands.push_back(new ExitCommand(*receiver));
	commands.push_back(new AddEventCommand(*receiver));
	commands.push_back(new FreeSeatsCommand(*receiver));
	commands.push_back(new BookCommand(*receiver));
	commands.push_back(new UnbookCommand(*receiver));
	commands.push_back(new BookingCommand(*receiver));
	commands.push_back(new CheckCommand(*receiver));
	commands.push_back(new ReportCommand(*receiver));
	commands.push_back(new MostWatchedCommand(*receiver));
	commands.push_back(new UnderTenCommand(*receiver));
	commands.push_back(new BuyCommand(*receiver));
	commands.push_back(new AddHallCommand(*receiver));
}

Invoker::Invoker(ICommand * command) : receiver(new System())
{
	commands.push_back(command);
}

Invoker::~Invoker()
{
}

void Invoker::executeCommand(std::string input)
{
	
	for (ICommand* cmd : commands)
	{
		if (Validator :: validateCommand(cmd,input))
		{
			cmd->addParameters(input);
			cmd->execute();
			return;
		}
	}

	std::cout <<"Incorrect command.Try again.\n";
}
