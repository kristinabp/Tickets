#ifndef HALL_H
#define HALL_H

#include <iostream>

class Hall
{
private:
	int number;
	int rows;
	int seats;

	void copy(const Hall& other);

public:
	Hall(int number = 0, int rows = 0, int seats = 0);
	Hall(const Hall& other);
	~Hall();

	Hall& operator=(const Hall& other);
	bool operator==(const Hall& other)const;

	int getNumber()const;
	int getRows()const;
	int getCapacity()const;
	int getSeats()const;
	friend std::ostream& operator<<(std::ostream& os, const Hall& hall);

	void print()const;
};
#endif // !HALL_H

