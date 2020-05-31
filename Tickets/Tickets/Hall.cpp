#include "Hall.h"

void Hall::copy(const Hall & other)
{
	this->number = other.number;
	this->rows = other.rows;
	this->seats = other.seats;
}

Hall::Hall():number(0), rows(0), seats(0)
{
}

Hall::Hall(int number, int rows, int seats) :number(number), rows(rows), seats(seats)
{
}

Hall::Hall(const Hall & other)
{
	copy(other);
}

Hall::~Hall()
{
}

Hall & Hall::operator=(const Hall & other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

bool Hall::operator==(const Hall & other) const
{
	return this->number == other.number && this->rows == other.rows && this->seats == other.seats;
}

Hall * Hall::clone() const
{
	return new Hall(*this);
}

int Hall::getNumber() const
{
	return this->number;
}

int Hall::getRows() const
{
	return this->rows;
}

int Hall::getCapacity() const
{
	return this->rows*this->seats;
}

int Hall::getSeats() const
{
	return this->seats;
}

void Hall::print() const
{
	std::cout << "Hall " << this->number;
}

void Hall::save(std::ostream & os)
{
	os << this->number << "\t" << this->rows << "\t" << this->seats << "\n";
}

std::ostream & operator<<(std::ostream & os, const Hall & hall)
{
	os << hall.number;
	return os;
}

