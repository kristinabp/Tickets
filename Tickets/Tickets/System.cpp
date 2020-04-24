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
			//events[i]->setNote(note);
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

bool System::buy(const std::string name, const Date & date, int row, int seat)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name && events[i]->getDate() == date)
		{
			events[i]->buy(row, seat);
			return true;
		}
	}
	return false;
}

void System::bookings(const std::string name, const Date & date) const
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name && events[i]->getDate() == date)
		{
			events[i]->printBooked();
		}
	}
}

void System::bookings(const std::string name) const
{
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
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date)
		{
			std::cout << events[i]->getName() << " ," << events[i]->getDate() << "\n";
			events[i]->printBooked();
		}
	}
}

void System::check(int id)
{
	if (id > 9999 && id < 1000)
	{
		std::cout << "Incorrect id!\n";
	}
	else
	{
		int row = id / 1000;
		int seat = id % 1000;
		for (size_t i = 0; i < events.size(); i++)
		{
			if (id == events[i]->getId(row, seat))
			{
				std::cout << "Correct id!\n";
				break;
			}
		}
	}
}

void System::report(const Date & from, const Date & to, const Hall & hall)
{
	std::cout << "Paid tickets from " << from << " to " << to << " in " << hall << "\n";
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

void System::print() const
{
	for (size_t i = 0; i < events.size(); i++)
	{
		events[i]->print();
	}
}


