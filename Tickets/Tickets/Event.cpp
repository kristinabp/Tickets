#include "Event.h"

void Event::copy(const Event & other)
{
	this->name = other.name;
	this->date = other.date;
	this->hall = other.hall;
	this->seats = other.seats;
	this->id = other.id;
	this->freeSeats = other.freeSeats;
	this->soldSeats = other.soldSeats;
}

void Event::createId(int row, int seat)
{
	std::string nameI = this->name;
	std::string i = std::to_string(row) + "-" + std::to_string(seat) + "-" + nameI[0] + "-" + std::to_string(date.getDay()) + "-" + std::to_string(date.getMonth());
	id[row - 1][seat - 1] = i;
}

Event::Event() : name("default"), date(Date()), hall(Hall()), note("empty"),
seats(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats()))),
id(std::vector<std::vector<std::string>>(hall.getRows())), soldSeats(0)
{
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			id[i].push_back("");
		}
	}
	this->freeSeats = hall.getCapacity();
}

Event::Event(const std::string name, const Date & date, const Hall & hall) : name(name), date(date), hall(hall),
seats(std::vector<std::vector<int>>(hall.getRows(), std::vector<int>(hall.getSeats()))),
id(std::vector<std::vector<std::string>>(hall.getRows())), soldSeats(0)
{
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			id[i].push_back("");
		}
	}
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

std::string Event::getId(int row, int seat) const
{
	return id[row-1][seat-1];
}

void Event::printBooked() const
{
	std::cout << "---- Booked: " << "----\n";
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			if (seats[i][j] == 1)
			{
				std::cout << "Row: " << i+1 << ", seat: " << j+1  << "\n";
			}
		}
	}
}

void Event::printPaid() const
{
	std::cout << "$ Sold: " << soldSeats << "\n";
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

bool Event::checkPaid(int row, int seat)
{
	return seats[row-1][seat-1] == 2;
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
		freeSeats--;
		soldSeats++;
		createId(row, seat);
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
				std::cout << "Row: " << i << ", seat: " << j << " - booked; not paid\n";
			}
			else if(seats[i - 1][j - 1] == 0)
			{
				std::cout << "Row: " << i << ", seat: " << j << " - not booked; not paid\n";
			}
			else if (seats[i - 1][j - 1] == 2)
			{
				std::cout << "Row: " << i << ", seat: " << j << " - paid" << " " << this->id[i-1][j-1]<<"\n";
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
