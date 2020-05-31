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
	Hall();
	Hall(int number, int rows, int seats);
	Hall(const Hall& other);
	~Hall();

	Hall& operator=(const Hall& other);
	bool operator==(const Hall& other)const;

	Hall* clone()const;

	int getNumber()const;
	int getRows()const;
	int getCapacity()const;
	int getSeats()const;
	friend std::ostream& operator<<(std::ostream& os, const Hall& hall);

	void print()const;
	void save(std::ostream& os);
};
#endif // !HALL_H

