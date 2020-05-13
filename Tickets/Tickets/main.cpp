#include <iostream>
#include <vector>
#include "System.h"

#include "Invoker.h"

int main()
{
	Invoker remote;
	std::string input;
	while (true)
	{
		getline(std::cin, input);
		remote.executeCommand(input);
	}

	return system("pause");
}