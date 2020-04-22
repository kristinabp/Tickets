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

void System::print() const
{
	for (size_t i = 0; i < events.size(); i++)
	{
		events[i]->print();
	}
}


