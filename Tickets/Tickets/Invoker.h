#ifndef INVOKER_H
#define INVOKER_H

#include "ICommand.h"
#include "OpenCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "CloseCommand.h"
#include "HelpCommand.h"
#include "ExitCommand.h"
#include "AddEventCommand.h"
#include "BookCommand.h"
#include "FreeSeatsCommand.h"
#include "UnbookCommand.h"
#include "BookingCommand.h"
#include "CheckCommand.h"
#include "ReportCommand.h"
#include "MostWatchedCommand.h"
#include "UnderTenCommand.h"
#include "BuyCommand.h"
#include "Validator.h"
#include <vector>

class Invoker
{
private:
	std::vector <ICommand *> commands;
	System* receiver;

public:
	Invoker();
	Invoker(ICommand* command);
	~Invoker();

	void executeCommand(std::string input);

};
#endif // !INVOKER_H

