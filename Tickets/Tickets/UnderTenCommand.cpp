#include "UnderTenCommand.h"



UnderTenCommand::UnderTenCommand(System& receiver):receiver(receiver)
{
}

void UnderTenCommand::execute()
{
	receiver.underTen(Date(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3])), 
		 Date(stoi(parameters[4]), stoi(parameters[5]), stoi(parameters[6])), std::cout);

	std::string answer;
	std::cout << "Do you want to save the statistics? ";
	std::cin.ignore();
	getline(std::cin, answer);
	if (answer == "yes" || answer == "Yes")
	{
		std::ofstream myfile;
		myfile.open("statistics.txt");

		receiver.underTen(Date(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3])),
			Date(stoi(parameters[4]), stoi(parameters[5]), stoi(parameters[6])), myfile);

		std::cout << "Successfully saved as statistics.txt .\n";
		myfile.close();
	}
}

void UnderTenCommand::unexecute()
{
}

std::string UnderTenCommand::toString()
{
	return "underten";
}
