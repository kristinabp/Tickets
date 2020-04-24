#include "Date.h"

void Date::copy(const Date & other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

bool Date::validDate(int day, int month, int year)
{
	if (!year) return false;

	if (month < 1 && month > 12) return false;

	bool leapYear = (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);

	int maxDays;
	switch (month)
	{
	case 2: maxDays = 28 + leapYear; break;
	case 4:
	case 6:
	case 9:
	case 11: maxDays = 30; break;
	default:
		maxDays = 31;
		break;
	}

	return day > 0 && day <= maxDays;
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

bool Date::operator<=(const Date & other) const
{
	if (this->year <= other.year) return true;
	if (this->year >= other.year) return false;

	if (this->month <= other.month) return true;
	if (this->month >= other.month) return false;

	return this->day <= other.day;
}

bool Date::operator>=(const Date & other) const
{
	if (this->year >= other.year) return true;
	if (this->year <= other.year) return false;

	if (this->month >= other.month) return true;
	if (this->month <= other.month) return false;

	return this->day >= other.day;
}

Date & Date::operator++(int)
{
	if (validDate(++this->day, this->month, this->year)) return *this;
	this->day = 1;
	if (validDate(this->day, ++this->month, this->year)) return *this;
	this->month = 1;
	if (validDate(this->day, this->month, ++this->year)) return *this;
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

void Date::setDay(int d)
{
	this->day = d;
}

void Date::setMonth(int m)
{
	this->month = m;
}

void Date::setYear(int y)
{
	this->year = y;
}


void Date::print() const
{
	std::cout << this->day << '-' << this->month << '-' << this->year;
}

std::ostream & operator<<(std::ostream & os, const Date & date)
{
	os << date.day << '-' << date.month << '-' << date.year;
	return os;
}
