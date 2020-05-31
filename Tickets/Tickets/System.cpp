#include "System.h"

void System::open(const std::string fileName)
{
	std::fstream inputFile;
	inputFile.open(fileName, std::ios::in);
	if (!isOpen)
	{
		if (inputFile.is_open())
		{
			this->isOpen = true;
			this->fileName = fileName;
			std::string name;
			int n, r, s, d, m, y;
			int numberOfHalls;
			int hallNumber, rows, seats;
			inputFile >> numberOfHalls;
			for (size_t i = 0; i < numberOfHalls; i++)
			{
				inputFile >> hallNumber >> rows >> seats;
				availableHalls.push_back(new Hall(hallNumber, rows, seats));
			}
			while (inputFile >> name >> y >> m >> d >> n >> r >> s) {
				addEvent(new Event(name, Date(y, m, d), Hall(n, r, s)));
			}

			inputFile.close();

			std::cout << "> open " << fileName << "\n";
			std::cout << "Successfully opened " << fileName << "\n";
			std::cout << "------------------------------------------\n";
			std::cout << "-----------Available halls:--------------\n";
			for (size_t i = 0; i < availableHalls.size(); i++)
			{
				availableHalls[i]->print();
				std::cout <<" "<< availableHalls[i]->getRows()<<" " << availableHalls[i]->getSeats() <<"\n";

			}
			std::cout << "-----------Available events:--------------\n";
			for (size_t i = 0; i < events.size(); i++)
			{
				events[i]->print();
			}
			std::cout << "------------------------------------------\n";
		}
		else
		{
			std::cout << "Couldn't open " << fileName << "\n";
			std::cout << "Creating new file..\n";

			inputFile.open(fileName, std::ios::in | std::ios::out | std::ios::trunc);
			this->isOpen = true;
			this->fileName = fileName;
			inputFile.close();
			std::cout << "Please, add halls and events.\n";
		}
	}
	else
	{
		std::cout << "You have already opened a file.Close it to open a new file.\n";
	}
	

}
void System::save()
{
	if (isOpen)
	{
		if (std::ifstream(fileName).good())
		{
			std::ofstream ofs(fileName);

			ofs << availableHalls.size() << "\n";
			for (size_t i = 0; i < availableHalls.size(); i++)
			{
				availableHalls[i]->save(ofs);
			}
			for (size_t i = 0; i < events.size(); i++)
			{
				events[i]->save(ofs);

			}
			ofs.close();
			std::cout << "> save " << fileName << "\n";
			std::cout << "Successfully saved " << fileName << "\n";
		}
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}

}

void System::saveAs(const std::string fileName)
{
	if (isOpen)
	{
		std::ofstream myfile;
		myfile.open(fileName);
		if (myfile.good())
		{
			myfile << availableHalls.size() << "\n";
			for (size_t i = 0; i < availableHalls.size(); i++)
			{
				availableHalls[i]->save(myfile);
			}
			for (size_t i = 0; i < events.size(); i++)
			{
				events[i]->save(myfile);
			}
			myfile.close();
			std::cout << "> save as " << fileName << "\n";
			std::cout << "Successfully saved as " << fileName << "\n";
		}
		else
		{
			std::cout << "Couldn't open " << fileName << "\n";
		}
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::close()
{
	if (isOpen)
	{
		std::cout << "> close\n";
		std::cout << "Successfully closed " << fileName << ".\n";

		this->isOpen = false;
		this->fileName = "";
		this->events.clear();
		this->availableHalls.clear();
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::help()
{
	if (isOpen)
	{
		std::cout << "> help\n";
		std::cout << "------ The following commands are supported : -------------------------------------------------\n";
		std::cout << "|open <file>				opens <file>\n";
		std::cout << "|close					closes currently opened file\n";
		std::cout << "|save					saves the currently open file\n";
		std::cout << "|saveas <file>				saves the currently open file in <file>\n";
		std::cout << "|help					prints this information\n";
		std::cout << "|exit					exists the program\n";
		std::cout << "|addevent <name> <date> <hall>		adds new event\n";
		std::cout << "|addhall <hall>		        adds new halls\n";
		std::cout << "|freeseats <name> <date>		shows free seats\n";
		std::cout << "|book <name> <date> <row> <seat> <note>	books a ticket\n";
		std::cout << "|unbook <name> <date> <row> <seat>	unbooks a ticket\n";
		std::cout << "|buy <name> <date> <row> <seat> <note>	buys a ticket\n";
		std::cout << "|bookings [<date>] [<name>]		shows the bookigs on a <date>\n";
		std::cout << "|check <code>				checks if a ticket is valid\n";
		std::cout << "|report <from> <to> [<hall>]		shows a report of paid tickets from <date> to <date> in <hall>\n";
		std::cout << "|mostwatched				shows the most watched events\n";
		std::cout << "|underten <from> <to>			shows the events with under 10% of paid tickets\n";
		std::cout << "-----------------------------------------------------------------------------------------------\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::exit()
{
	std::cout << "> exit\n";
	std::cout << "Exiting the program...\n";
}

System::System() : events(std::vector<Event*>()), availableHalls(std::vector<Hall*>()), fileName(""), isOpen(false)
{
}

System::System(std::vector<Event*> events)
{
	this->events = events;
}

void System::addEvent(Event* event)
{
	if (isOpen)
	{
		bool findHall = true;
		for (size_t i = 0; i < availableHalls.size(); i++)
		{
			if (event->getHall() == *availableHalls[i])
			{
				for (size_t j = 0; j < events.size(); j++)
				{
					if (event->getHall().getNumber() == events[j]->getHall().getNumber()
						&& event->getDate() == events[j]->getDate()
						&& event->getHall() == events[j]->getHall())
					{
						std::cout << "The hall is incorrect!\n";
						return;
					}
				}
				findHall = true;
				break;
			}
			else
			{
				findHall = false;
			}
			if (findHall)
			{
				break;
			}
		}
		if (findHall)
		{
			this->events.push_back(event->clone());
			std::cout << "Successfully added event " << event->getName() << " in hall " << event->getHall().getNumber() << " on " <<
				event->getDate() << "\n";
		}
		else
		{
			std::cout << "This hall does not exist!\n";
		}
		return;
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::addHall(Hall * hall)
{
	if (isOpen)
	{
		for (size_t i = 0; i < availableHalls.size(); i++)
		{
			if (availableHalls[i]->getNumber() == hall->getNumber() && availableHalls[i]->getRows()==hall->getRows()
				&& availableHalls[i]->getSeats()==hall->getSeats())
			{
				std::cout << "The hall already exists!\n";
				return;
			}
		}
		availableHalls.push_back(hall->clone());
		std::cout << "Successfully added new hall " <<  hall->getNumber() << "\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::freeSeats(const std::string name, const Date & date)
{
	if (isOpen)
	{
		std::cout << "-------------\tFree seats\t----------------\n ";
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getName() == name && events[i]->getDate() == date)
			{
				events[i]->print();
				std::cout << "---------------------------------\n";
				events[i]->printSeats();
			}
		}
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::book(const std::string name, const Date & date, int row, int seat, const std::string note)
{
	if (isOpen)
	{
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getName() == name && events[i]->getDate() == date)
			{
				events[i]->bookSeat(row, seat, note);
				return;
			}
		}

		std::cout << "Incorrect event. Please try again!\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
	
}

void System::unbook(const std::string name, const Date & date, int row, int seat)
{
	if (isOpen)
	{
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getName() == name && events[i]->getDate() == date)
			{
				events[i]->unbookSeat(row, seat);
				return;
			}
		}

		std::cout << "Incorrect event. Please try again!\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::buy(const std::string name, const Date & date, int row, int seat, const std::string note)
{
	if (isOpen)
	{
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getName() == name && events[i]->getDate() == date)
			{
				events[i]->buy(row, seat, note);
				return;
			}
		}

		std::cout << "Incorrect event. Please try again!\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::bookings(const std::string name, const Date & date) const
{
	if (isOpen)
	{
		std::cout << "-------------\tBookings  -------------------------------\n";
		std::cout << "-------------\t" << name << " , " << date << "  ---------------\n";
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getName() == name && events[i]->getDate() == date)
			{
				if (events[i]->getFreeSeats() == events[i]->getHall().getCapacity())
				{
					std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
					std::cout << "No booked tickets yet.\n";
				}
				else
				{
					std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
					events[i]->printBooked();
				}
			}
		}
		std::cout << "-------------------------------------------\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::bookings(const std::string name) const
{
	if (isOpen)
	{
		std::cout << "-------------\tBookings  ----------------\n";
		std::cout << "-------------\t" << name << "  ---------------\n";
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getName() == name)
			{
				if (events[i]->getFreeSeats() == events[i]->getHall().getCapacity())
				{
					std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
					std::cout << "No booked tickets yet.\n";
				}
				else
				{
					std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
					events[i]->printBooked();
				}
			}
		}
		std::cout << "-------------------------------------------\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::bookings(const Date & date) const
{
	if (isOpen)
	{
		std::cout << "-------------\tBookings  ----------------\n";
		std::cout << "-------------\t" << date << "  ---------------\n";
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getDate() == date)
			{
				if (events[i]->getFreeSeats() == events[i]->getHall().getCapacity())
				{
					std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
					std::cout << "No booked tickets yet.\n";
				}
				else
				{
					std::cout << events[i]->getName() << "\n";
					events[i]->printBooked();
				}
			}
		}
		std::cout << "-------------------------------------------\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::check(std::string id)
{
	if (isOpen)
	{
		int counter = 0;
		int row, seat;
		std::string cur;
		while (id[counter] != '-')
		{
			cur = cur + id[counter];
			counter++;
		}
		row = std::stoi(cur);
		counter++;
		cur = "";
		while (id[counter] != '-')
		{
			cur = cur + id[counter];
			counter++;
		}
		seat = std::stoi(cur);

		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getId(row, seat) == id)
			{
				std::cout << "Correct Id.\n";
				return;
			}
		}
		std::cout << "Incorrect Id.\n";
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::report(const Date & from, const Date & to, int hall)
{
	if (isOpen)
	{
		std::cout << "------- Report from " << from << " to " << to << " in hall N:" << hall << "------\n";
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getHall().getNumber() == hall)
			{
				if (events[i]->getDate() >= from && events[i]->getDate() <= to)
				{
					std::cout << events[i]->getName() << "\n";
					events[i]->printPaid();
				}
			}
		}
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::report(const Date & from, const Date & to)
{
	if (isOpen)
	{
		std::cout << "------- Report from " << from << " to " << to << "------\n";
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getDate() >= from && events[i]->getDate() <= to)
			{
				std::cout << events[i]->getName() << ", " << events[i]->getDate() << "\n";
				events[i]->printPaid();
			}
		}
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::mostWatched()
{
	if (isOpen)
	{
		std::vector <Event*> cur;
		for (size_t i = 0; i < events.size(); i++)
		{
			cur.push_back(this->events[i]);
		}

		std::sort(cur.begin(), cur.end(), [](const Event* lhs, const Event* rhs)
		{
			return lhs->getFreeSeats() < rhs->getFreeSeats();
		});

		std::cout << "----------Top events :------------\n";
		for (size_t i = 0; i < cur.size(); i++)
		{
			cur[i]->print();
		}
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::underTen(const Date & from, const Date & to, std::ostream& os)
{
	if (isOpen)
	{
		os << "Least watched events from " << from << " to " << to << "\n";
		for (size_t i = 0; i < events.size(); i++)
		{
			if (events[i]->getDate() >= from && events[i]->getDate() <= to)
			{
				if (events[i]->getSoldSeats() <= 0.1*(events[i]->getHall().getCapacity()))
				{
					os << events[i]->getName() << ", " << events[i]->getDate() << "\n";
				}
			}
		}
	}
	else
	{
		std::cout << "Please, open a file.\n";
	}
}

void System::print() const
{
	for (size_t i = 0; i < events.size(); i++)
	{
		events[i]->print();
	}
}


