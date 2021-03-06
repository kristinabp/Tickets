#include "Event.h"

void Event::copy(const Event & other)
{
	this->name = other.name;
	this->date = other.date;
	this->hall = other.hall;
	this->seats = other.seats;
	this->note = other.note;
	this->id = other.id;
	this->freeSeats = other.freeSeats;
	this->soldSeats = other.soldSeats;
}

void Event::createId(int row, int seat)
{
	std::string i = std::to_string(row) + "-" + std::to_string(seat) + "-" + this->note[row - 1][seat - 1] + "-" 
	+ std::to_string(date.getYear()) + "-" + std::to_string(date.getMonth()) + "-" + std::to_string(date.getDay());
	id[row-1][seat-1] = i;
}

std::string Event::takeIdNote(std::string note)
{
	std::string n;
	int counter = 0;
	int index = 0;
	while (counter < 2)
	{
		while (note[index] != '-')
		{
			index++;
		}
		index++;
		counter++;
	}
	while (note[index] != '-')
	{
		n=n+ note[index];
		index++;
	}

	return n;
}

void Event::initalize()
{
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			note[i].push_back("");
		}
	}
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			id[i].push_back("");
		}
	}
	this->freeSeats = hall.getCapacity();
}

Event::Event() : name("default"), date(Date()), hall(Hall()), note(std::vector<std::vector<std::string>>(hall.getRows())),
seats(std::vector<std::vector<SeatStatus>>(hall.getRows(), std::vector<SeatStatus>(hall.getSeats()))),
id(std::vector<std::vector<std::string>>(hall.getRows())), soldSeats(0)
{
	initalize();
}

Event::Event(const std::string name, const Date & date, const Hall & hall) : name(name), date(date), 
hall(hall), note(std::vector<std::vector<std::string>>(hall.getRows())),
seats(std::vector<std::vector<SeatStatus>>(hall.getRows(), std::vector<SeatStatus>(hall.getSeats()))),
id(std::vector<std::vector<std::string>>(hall.getRows())), soldSeats(0)
{
	initalize();
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

std::string Event::getId(int row, int seat) const
{
	return id[row-1][seat-1];
}

int Event::getFreeSeats() const
{
	return this->freeSeats;
}

int Event::getSoldSeats() const
{
	return this->soldSeats;
}

void Event::setNote(const std::string note, int row, int seat)
{
	this->note[row - 1][seat - 1] = note;
}

void Event::printBooked() const
{
	for (size_t i = 0; i < hall.getRows(); i++)
	{
		for (size_t j = 0; j < hall.getSeats(); j++)
		{
			if (seats[i][j] == 1)
			{
				std::cout << "Row: " << i+1 << ", seat: " << j+1  <<", "<< this->note[i][j]<< "\n";
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

bool Event::checkPaid(int row, int seat)const
{
	return seats[row-1][seat-1] == 2;
}

void Event::bookSeat(int row, int seat, std::string name)
{
	if (seats[row-1][seat-1] == RESERVED )
	{
		if (note[row - 1][seat - 1] == name)
		{
			std::cout << "The seat is already booked by " << name << ".\n";
		}
		else
		{
			std::cout << "The seat is already booked.\n";
		}
	}
	else if (seats[row - 1][seat - 1] == PAID)
	{
		if (note[row - 1][seat - 1] == name)
		{
			std::cout << "The seat is already paid by " << name << ".\n";
		}
		else
		{
			std::cout << "The seat is already paid.\n";
		}
	}
	else
	{
		seats[row - 1][seat - 1] = RESERVED;
		note[row - 1][seat - 1] = name;
		freeSeats--;
		createId(row, seat);
		std::cout << "Successfully booked a ticket with id " << id[row-1][seat-1] << ".\n";
	}

}

void Event::unbookSeat(int row, int seat)
{
	if (seats[row - 1][seat - 1] != RESERVED)
	{
		std::cout << "Incorrect seat.\n";
	}
	else
	{
		seats[row - 1][seat - 1] = NOTRESERVED;
		note[row - 1][seat - 1] = "";
		id[row - 1][seat - 1] = "";
		freeSeats++;
		std::cout << "Successfully unbooked a ticket.\n";
	}
}

void Event::buy(int row, int seat,std::string name)
{
	if (seats[row - 1][seat - 1] == PAID)
	{
		if (note[row - 1][seat - 1] == name)
		{
			std::cout << "The seat is already paid by " << name << ".\n";
		}
		else
		{
			std::cout << "The seat is already paid.\n";
		}
	}
	else if (seats[row - 1][seat - 1] == RESERVED)
	{
		if (takeIdNote(id[row - 1][seat - 1]) == name)
		{
			seats[row - 1][seat - 1] = PAID;
			soldSeats++;
			std::cout << "Successfully bought a ticket with id " << id[row-1][seat-1] << ".\n";
		}
		else
		{
			std::cout << "The seat is already booked.\n";
		}
	}
	else
	{
		seats[row - 1][seat - 1] = PAID;
		freeSeats--;
		soldSeats++;
		this->note[row - 1][seat - 1] = name;
		createId(row, seat);
		std::cout << "Successfully bought a ticket with id " << id[row - 1][seat - 1] << ".\n";
	}
}

void Event::printSeats() const
{
	for (size_t i = 1; i <= hall.getRows(); i++)
	{
		for (size_t j = 1; j <= hall.getSeats(); j++)
		{
			if (seats[i - 1][j - 1] == RESERVED)
			{
				std::cout << "Row: " << i << ", seat: " << j << " - booked; not paid \n";
			}
			else if(seats[i - 1][j - 1] == NOTRESERVED)
			{
				std::cout << "Row: " << i << ", seat: " << j << " - not booked; not paid \n";
			}
			else if (seats[i - 1][j - 1] == PAID)
			{
				std::cout << "Row: " << i << ", seat: " << j << " - paid \n";
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
	std::cout << "\n";
}

void Event::save(std::ostream & os)
{
	os << this->name << "\t" << this->date.getYear() << "\t" << this->date.getMonth() << "\t"
		<< this->date.getDay() << "\t" << this->hall.getNumber() << "\t" << this->hall.getRows() 
		<< "\t" << this->hall.getSeats() << "\n";
}
