#ifndef OPENCOMMAND_H
#define OPENCOMMAND_H

#include "ICommand.h"
#include "System.h"

class OpenCommand : public ICommand
{
private:
	System& receiver;

public:
	OpenCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();

};
#endif // !OPENCOMMAND_H

