#include "Event.h"

void Event::copy(const Event & other)
{
	this->name = other.name;
	this->date = other.date;
	this->hall = other.hall;
	this->seats = other.seats;
}

Event::Event() : name("default"), date(Date()), hall(Hall()), note("empty"),
seats(std::vector<int>(hall.getCapacity()))
{
}

Event::Event(const std::string name, const Date & date, const Hall & hall) : name(name), date(date), hall(hall),
seats(std::vector<int>(hall.getCapacity()))
{
}

Event::Event(const Event & other)
{
	copy(other);
}

Event::~Event()
{
}

Event & Event::operator=(const Event & other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

bool Event::operator==(const Event & other) const
{
	return this->name == other.name && this->hall == other.hall && this->date == other.date;
}

void Event::print() const
{
	std::cout << "Event: " << this->name << ", date: ";
	this->date.print();
	std::cout << ", ";
	this->hall.print();
	std::cout << "\n";
}
