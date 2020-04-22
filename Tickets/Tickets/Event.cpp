#include "Event.h"

void Event::copy(const Event & other)
{
	this->name = other.name;
	this->date = other.date;
	this->hall = other.hall;
	this->seats = other.seats;
	this->freeSeats = other.freeSeats;
}

Event::Event() : name("default"), date(Date()), hall(Hall()), note("empty"),
seats(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats())))
{
	this->freeSeats = hall.getCapacity();
}

Event::Event(const std::string name, const Date & date, const Hall & hall) : name(name), date(date), hall(hall),
seats(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats())))
{
	this->freeSeats = hall.getCapacity();
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

Event * Event::clone() const
{
	return new Event(*this);
}

std::string Event::getName() const
{
	return this->name;
}

Date  Event::getDate() const
{
	return this->date;
}

Hall Event::getHall() const
{
	return this->hall;
}

int Event::getRows() const
{
	return this->hall.getRows();
}

int Event::getSeats() const
{
	return this->hall.getSeats();
}

void Event::bookSeat(int row, int seat)
{
	if (seats[row-1][seat-1] == 1 )
	{
		std::cout << "The seat is already booked.\n";
	}
	else
	{
		seats[row - 1][seat - 1] = 1;
		freeSeats--;
	}
}

void Event::unbookSeat(int row, int seat)
{
	if (seats[row - 1][seat - 1] == 0)
	{
		std::cout << "Incorrect seat\n";
	}
	else
	{
		seats[row - 1][seat - 1] = 0;
		freeSeats++;
	}
}

bool Event::checkSeat(int row, int seat) const
{
	return seats[row - 1][seat - 1] != 0;
}

void Event::printSeats() const
{
	for (size_t i = 1; i <= hall.getRows(); i++)
	{
		for (size_t j = 1; j <= hall.getSeats(); j++)
		{
			if (checkSeat(i, j))
			{
				std::cout << "Row: " << i << ", seat: " << j << " - already booked\n";
			}
			else
			{
				std::cout << "Row: " << i << ", seat: " << j << " - not booked yet\n";
			}
		}
	}
}

void Event::print() const
{
	std::cout << "Event: " << this->name << ", date: ";
	this->date.print();
	std::cout << ", ";
	this->hall.print();
	std::cout << ", free seats: " << this->freeSeats;
	std::cout << "\n";
}
