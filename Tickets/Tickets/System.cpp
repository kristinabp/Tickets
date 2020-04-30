#include "System.h"

void System::open(const std::string fileName)
{
	std::fstream inputFile;
	inputFile.open(fileName, std::ios::in);

	if (inputFile.is_open())
	{
		this->fileName = fileName;
		std::string name;
		int n, r, s, d, m, y;
		while (inputFile >> name >> d >> m >> y >> n >> r >> s) {
			addEvent(new Event(name, Date(d,m,y), Hall(n,r,s)));
		}

		inputFile.close();

		std::cout << "> open " << fileName << "\n";
		std::cout << "Successfully opened " << fileName << "\n";
	}
	else
	{
		std::cout << "Couldn't open " << fileName << "\n";
	}

}
void System::save()
{
	if (std::ifstream(fileName).good())
	{
		std::ofstream ofs(fileName);
		
		for (size_t i = 0; i < events.size(); i++)
		{
			events[i]->save(ofs);
			
		}
		ofs.close();
		std::cout << "> save " << fileName << "\n";
		std::cout << "Successfully saved " << fileName << "\n";
	}
	else
	{
		std::cout << "Couldn't open " << fileName << "\n";
	}

}

void System::saveAs(const std::string fileName)
{
	std::ofstream myfile;
	myfile.open(fileName);
	if (myfile.good())
	{
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

void System::help()
{
	std::cout << "> help\n";
	std::cout << "------ The following commands are supported : -------\n";
	std::cout << "|open <file>				opens <file>\n";
	std::cout << "|close					closes currently opened file\n";
	std::cout << "|save					saves the currently open file\n";
	std::cout << "|saveas <file>				saves the currently open file in <file>\n";
	std::cout << "|help					prints this information\n";
	std::cout << "|exit					exists the program\n";
	std::cout << "|addevent <name> <date> <hall>		adds new event\n";
	std::cout << "|freeseats <name> <date>		shows free seats\n";
	std::cout << "|book <name> <date> <row> <seat> <note>	books a ticket\n";
	std::cout << "|unbook <name> <date> <row> <seat>	unbooks a ticket\n";
	std::cout << "|buy <name> <date> <row> <seat> <note>	buys a ticket\n";
	std::cout << "|bookings [<date>] [<name>]		shows the bookigs on a <date>\n";
	std::cout << "|check <code>				checks if a ticket is valid\n";
	std::cout << "|report <from> <to> [<hall>]		shows a report of paid tickets from <date> to <date> in <hall>\n";
	std::cout << "|mostwatched				shows the most watched events\n";
	std::cout << "|underten <from> <to>			shows the events with under 10% of paid tickets\n";
}

void System::exit()
{
	std::cout << "> exit\n";
	std::cout << "Exiting the program...\n";
}

System::System() : events(std::vector<Event*>())
{
}

System::System(std::vector<Event*> events)
{
	this->events = events;
}

void System::run()
{
	while (true)
	{
		std::cout << "$";
		getline(std::cin, command);
		if (command == "Help" || command == "help")
		{
			help();
		}
		else if (command == "Open" || command == "open")
		{
			std::cout << "file name: ";
			getline(std::cin, fileName);
			open(fileName);
		}
		else if (command == "Save" || command == "save")
		{
			save();
		}
		else if (command == "SaveAs" || command == "saveAs" || command == "saveas")
		{
			std::string file;
			std::cout << "save as: ";
			getline(std::cin, file);
			saveAs(file);
		}
		else if (command == "Exit" || command == "exit")
		{
			exit();
			break;
		}
		else if (command == "Close" || command == "close")
		{
		}
		else if (command == "addevent" || command == "addEvent" || command == "Addevent")
		{
			std::string name;
			int d, m, y, n, r, s;
			std::cout << "event : ";
			getline(std::cin, name);
			std::cout << "date: ";
			std::cin >> d >> m >> y;
			std::cout << "hall:";
			std::cin >> n >> r >> s;
			addEvent(new Event(name, Date(d, m, y), Hall(n, r, s)));
		}
		else if (command == "freeseats" || command == "FreeSeats" || command == "Freeseats" || command == "freeSeats")
		{
			std::string name;
			int d, m, y, n, r, s;
			std::cout << "event : ";
			getline(std::cin, name);
			std::cout << "date: ";
			std::cin >> d >> m >> y;
			freeSeats(name, Date(d, m, y));
		}
		else if (command == "book" || command == "Book")
		{
			std::string name, n;
			int d, m, y, s, r;
			std::cout << "event : ";
			getline(std::cin, name);
			std::cout << "date: ";
			std::cin >> d >> m >> y;
			std::cout << "row , seat: ";
			std::cin >> r >> s;
			std::cout << "name : ";
			getline(std::cin, n);
			book(name, Date(d, m, y),r, s, n);
		}
		else if (command == "unbook" || command == "Unbook")
		{
			std::string name;
			int d, m, y, s, r;
			std::cout << "event : ";
			getline(std::cin, name);
			std::cout << "date: ";
			std::cin >> d >> m >> y;
			std::cout << "row , seat: ";
			std::cin >> r >> s;
			unbook(name, Date(d, m, y), r, s);
		}
		else if (command == "buy" || command == "Buy")
		{
			std::string name, n;
			int d, m, y, s, r;
			std::cout << "event : ";
			getline(std::cin, name);
			std::cout << "date: ";
			std::cin >> d >> m >> y;
			std::cout << "row , seat: ";
			std::cin >> r >> s;
			std::cout << "name : ";
			getline(std::cin, n);
			buy(name, Date(d, m, y), r, s, n);
		}
		else if (command == "bookings" || command == "Bookings")
		{
			int d, m, y;
			std::cout << "date: ";
			std::cin >> d >> m >> y;
			bookings(Date(d, m, y));
		}
		else if (command == "check" || command == "Check")
		{
			std::string id;
			getline(std::cin, id);
			check(id);
		}
		else if (command == "report" || command == "Report")
		{
			int d1, m1, y1, d2, m2, y2;
			std::cout << "from: ";
			std::cin >> d1 >> m1 >> y1;
			std::cout << "to: ";
			std::cin >> d2 >> m2 >> y2;
			report(Date(d1, m1, y1), Date(d2, m2, y2));
		}
		else if (command == "mostwatched" || command == "mostWatched" || command == "MostWatched" || command == "Mostwatched")
		{
			mostWatched();
		}
		else if (command == "underten" || command == "Underten")
		{
			int d1, m1, y1, d2, m2, y2;
			std::cout << "from: ";
			std::cin >> d1 >> m1 >> y1;
			std::cout << "to: ";
			std::cin >> d2 >> m2 >> y2;
			underTen(Date(d1, m1, y1), Date(d2, m2, y2));
		}
	}
}

System & System::addEvent(Event* event)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (event->getDate() == events[i]->getDate()
			&& event->getHall() == events[i]->getHall())
		{
			std::cout << "!error - already exist an event ot this date in this hall!\n";
			return *this;
		}
	}
	this->events.push_back(event->clone());
	return *this;
}

void System::freeSeats(const std::string name, const Date & date)
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

bool System::book(const std::string name, const Date & date, int row, int seat, const std::string note)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name && events[i]->getDate() == date)
		{
			events[i]->setNote(note, row, seat);
			events[i]->bookSeat(row, seat);
			return true;
		}
	}
	return false;
}

bool System::unbook(const std::string name, const Date & date, int row, int seat)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name && events[i]->getDate() == date)
		{
			events[i]->unbookSeat(row, seat);
			return true;
		}
	}
	return false;
}

bool System::buy(const std::string name, const Date & date, int row, int seat, const std::string note)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name && events[i]->getDate() == date)
		{
			events[i]->buy(row, seat, note);
			return true;
		}
	}
	return false;
}

void System::bookings(const std::string name, const Date & date) const
{
	std::cout << "-------------\tBookings  -------------------------------\n";
	std::cout << "-------------\t" <<name << " , "<< date << "  ---------------\n";
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name && events[i]->getDate() == date)
		{
			std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
			events[i]->printBooked();
		}
	}
}

void System::bookings(const std::string name) const
{
	std::cout << "-------------\tBookings  ----------------\n";
	std::cout << "-------------\t" << name << "  ---------------\n";
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name)
		{
			std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
			events[i]->printBooked();
		}
	}
}

void System::bookings(const Date & date) const
{
	std::cout << "-------------\tBookings  ----------------\n";
	std::cout << "-------------\t" << date << "  ---------------\n";
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date)
		{
			std::cout << events[i]->getName() << "\n";
			events[i]->printBooked();
		}
	}
}

void System::check(std::string id)
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

void System::report(const Date & from, const Date & to, const Hall & hall)
{
	std::cout << "------- Report from " << from << " to " << to << " in hall N:" << hall << "------\n";
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getHall() == hall)
		{
			if (events[i]->getDate() >= from && events[i]->getDate() <= to)
			{
				std::cout << events[i]->getName() << "\n";
				events[i]->printPaid();
			}
			
		}
	}
}

void System::report(const Date & from, const Date & to)
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

void System::mostWatched()
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
	for (size_t i = 0; i < cur.size() ; i++)
	{
		cur[i]->print();
	}
}

void System::underTen(const Date & from, const Date & to)
{
	std::cout << "Least watched events from " << from << " to " << to << "\n";
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() >= from && events[i]->getDate() <= to)
		{
			if (events[i]->getSoldSeats() <= 0.1*(events[i]->getHall().getCapacity()))
		    {
				std::cout << events[i]->getName() << ", " << events[i]->getDate() << "\n";
		    }
		}
	}
}

void System::print() const
{
	for (size_t i = 0; i < events.size(); i++)
	{
		events[i]->print();
	}
}


