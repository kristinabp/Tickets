#include "Date.h"

void Date::copy(const Date & other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

Date::Date() : day(1), month(1), year(2020)
{
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

Date::Date(const Date & other)
{
	copy(other);
}

Date::~Date()
{

}

Date & Date::operator=(const Date & other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

bool Date::operator==(const Date & other) const
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

void Date::print() const
{
	std::cout << this->day << '-' << this->month << '-' << this->year;
}
