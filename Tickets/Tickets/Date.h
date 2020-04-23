#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;

	void copy(const Date& other);

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& other);
	~Date();

	Date& operator=(const Date& other);
	bool operator==(const Date& other)const;
	friend std::ostream& operator<<(std::ostream& os, const Date& date);

	void print()const;
};

#endif // !DATE_H


