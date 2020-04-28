#include "System.h"

System::System() : events(std::vector<Event*>())
{
}

System::System(std::vector<Event*> events)
{
	this->events = events;
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


