#include "Event.h"

void Event::copy(const Event & other)
{
	this->name = other.name;
	this->date = other.date;
	this->hall = other.hall;
	this->seats = other.seats;
	this->id = other.id;
	this->freeSeats = other.freeSeats;
}

Event::Event() : name("default"), date(Date()), hall(Hall()), note("empty"),
seats(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats()))),
id(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats())))
{
	this->freeSeats = hall.getCapacity();
}

Event::Event(const std::string name, const Date & date, const Hall & hall) : name(name), date(date), hall(hall),
seats(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats()))),
id(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats())))
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
//
//void Event::setNote(int row, int seat)
//{
//	this->note[row][seat] = note;
//}

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

int Event::getId(int row, int seat) const
{
	return id[row-1][seat-1];
}

void Event::printBooked() const
{
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			if (seats[i][j] == 1)
			{
				std::cout << "Row: " << i+1 << ", seat: " << j+1 << "\n";
			}
		}
	}
}

void Event::printPaid() const
{
	std::cout << "Sold tickets: " << soldSeats << "\n";
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			if (seats[i][j] == 2)
			{
				std::cout << "Row: " << i+1 << ", seat: " << j+1 << "\n";
			}
		}
	}
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

void Event::buy(int row, int seat)
{
	if (seats[row - 1][seat - 1] > 1)
	{
		std::cout << "The seat is already booked and paid.\n";
	}
	else if (seats[row - 1][seat - 1] == 1)
	{
		std::cout << "The seat is already booked.\n";
	}
	else
	{
		seats[row - 1][seat - 1] = 2;
		soldSeats++;
		//id[row - 1][seat - 1] = row * 1000 + seat;
	}
}

void Event::printSeats() const
{
	for (size_t i = 1; i <= hall.getRows(); i++)
	{
		for (size_t j = 1; j <= hall.getSeats(); j++)
		{
			if (seats[i - 1][j - 1] == 1)
			{
				std::cout << "Row: " << i << ", seat: " << j << " - already booked\n";
			}
			else if(seats[i - 1][j - 1] == 0)
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
