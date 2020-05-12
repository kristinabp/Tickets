#ifndef ADDEVENTCOMMAND_H
#define ADDEVENTCOMMAND_H

#include "ICommand.h"
#include "System.h"

class AddEventCommand : public ICommand
{
private:
	System& receiver;

public:
	AddEventCommand(System& receiver);
	void execute();
	void unexecute();

	std::string toString();
};
#endif // !ADDEVENTCOMMAND_H
